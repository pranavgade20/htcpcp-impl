/*************************************************************************
 *  Copyright (C) 2020 by Pranav Gade <pranavgade20@gmail.com>           *
 *                                                                       *
 *  This program is free software; you can redistribute it and/or        *
 *  modify it under the terms of the GNU General Public License as       *
 *  published by the Free Software Foundation; either version 3 of       *
 *  the License, or (at your option) any later version.                  *
 *                                                                       *
 *  This program is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *  GNU General Public License for more details.                         *
 *                                                                       *
 *  You should have received a copy of the GNU General Public License    *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.*
 *************************************************************************/

#include "Socket.h"
#include <sys/socket.h>
#include <unistd.h>

Socket::Socket(int fd) {
    fd_ = fd;
    setg(inBuf_, inBuf_, inBuf_);
    setp(outBuf_, outBuf_ + bufSize - 1);
}

Socket::~Socket() {
    close();
}

void Socket::close() {
    if (fd_ >= 0) {
        sync();
        ::close(fd_);
        shutdown(fd_, SHUT_RDWR);
    }
}

int Socket::overflow(int c) {
    if (!std::streambuf::traits_type::eq_int_type(c, std::streambuf::traits_type::eof())) {
        *pptr() = std::streambuf::traits_type::to_char_type(c);
        pbump(1);
    }
    return sync() == -1 ? std::streambuf::traits_type::eof() : std::streambuf::traits_type::not_eof(c);
}

int Socket::sync() {
    if (pbase() != pptr()) {
        std::streamsize size(pptr() - pbase());
        std::streamsize done(::write(fd_, outBuf_, size));

        if (0 < done) {
            std::copy(pbase() + done, pptr(), pbase());
            setp(pbase(), epptr());
            pbump(size - done);
        }
    }
    return pptr() != epptr() ? 0 : -1;
}

int Socket::underflow() {
    if (gptr() == egptr()) {
        std::streamsize pback(std::min(gptr() - eback(), std::ptrdiff_t(16 - sizeof(int))));
        std::copy(egptr() - pback, egptr(), eback());
        int done(::read(fd_, eback() + pback, bufSize));
        setg(eback(), eback() + pback, eback() + pback + std::max(0, done));
    }
    return gptr() == egptr() ? std::streambuf::traits_type::eof() : std::streambuf::traits_type::to_int_type(*gptr());
}
