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

#ifndef HTCPCP_SOCKET_H
#define HTCPCP_SOCKET_H

#include <streambuf>
#include <ostream>
#include <istream>
#include <sys/socket.h>
#include <unistd.h>

class Socket : public std::streambuf, public std::ostream, public std::istream {
private:
    static const int bufSize = 1024;
    char outBuf_[bufSize];
    char inBuf_[bufSize + 16 - sizeof(int)];
    int fd_;
public:
    Socket(int fd);

    ~Socket();

    void close();

protected:
    int overflow(int c);

    int underflow();

    int sync();
};


#endif //HTCPCP_SOCKET_H
