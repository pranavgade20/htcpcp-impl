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

#ifndef HTCPCP_SERVERSOCKET_H
#define HTCPCP_SERVERSOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>

#include "Socket.h"

class ServerSocket {
private:
    /**
     * port and address we will listen on
     */
    struct sockaddr_in address;
    /**
     * file descriptor of incoming connections
     */
    int server_fd;
public:
    /**
     * creates a ServerSocket listening on the specified port
     * @param port the port to listen on
     */
    ServerSocket(int port);

    /**
     * wait for an incoming connection, and return a Socket object representing the incoming connection
     * @return a Socket object representing the incoming connection
     */
    Socket *accept();
};


#endif //HTCPCP_SERVERSOCKET_H
