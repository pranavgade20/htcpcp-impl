/*************************************************************************
 *  Copyright (C) 2021 by Pranav Gade <pranavgade20@gmail.com>           *
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
    /**
     * The size of our buffers
     */
    static const int bufSize = 1024;
    /**
     * Array to buffer output
     */
    char outBuf_[bufSize];
    /**
     * Array to buffer input
     */
    char inBuf_[bufSize + 16 - sizeof(int)];
    /**
     * file descriptor pointing to our socket
     */
    int fd_;
public:
    /**
     * constructs a Socket object that uses fd for read/write calls
     * @param fd the file descriptor this socket is wrapped around
     */
    Socket(int fd);

    /**
     * destructor to flush buffers and close file descriptor
     */
    ~Socket();

    /**
     * closes the connection
     */
    void close();

protected:
    /**
     * writes a byte to the socket. we are required to override this as we are inheriting from
     * ostream
     * @param c the byte to write.
     * @return EOF if writing is not possible
     */
    int overflow(int c);

    /**
     * read a byte from the socket. we are required to override this as we are inheriting from
     * istream
     * @return one byte read from the socket, EOF otherwise
     */
    int underflow();

    /**
     * flush the output buffer
     * @return -1 if we can't write to the socket, 0 otherwise
     */
    int sync();
};


#endif //HTCPCP_SOCKET_H
