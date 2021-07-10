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

#include "ServerSocket.h"

ServerSocket::ServerSocket(int port) {
    server_fd = socket(AF_INET, SOCK_STREAM, 0); // tcp socket over ipv4, default protocol
    if (server_fd == 0) {
        throw server_fd;
    }

    int option_value = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &option_value, sizeof(option_value)) == -1) {
        throw -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw -1;
    }

    if (listen(server_fd, 7) == -1) {
        throw -1;
    }
}

Socket *ServerSocket::accept() {
    socklen_t address_size = sizeof(address);
    int socket_fd = ::accept(server_fd, (struct sockaddr *) &address, &address_size);
    if (socket_fd == -1) throw socket_fd;
    return new Socket(socket_fd);
}
