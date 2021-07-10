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

#ifndef HTCPCP_REQUEST_H
#define HTCPCP_REQUEST_H

#include "Socket.h"
#include <string>
#include <map>
#include <vector>

class Request {
private:
    /**
     * Map for storing header names and value pairs
     */
    std::map<std::string, std::string> headers;
    /**
     * Map for storing addition type and value pairs
     */
    std::map<std::string, int> addition_map;
    /**
     * A list of unparsed headers in the body of the request
     */
    std::vector <std::string> body_headers;
    /**
     * The method of the request(for example, BREW, or POST)
     */
    std::string method;
    /**
     * The request path
     */
    std::string path;
    /**
     * The request protocol
     */
    std::string protocol;
    /**
     * The request body
     */
    std::string body;
public:
    /**
     * Construct a request object from incoming connection.
     * @param socket the socket representing incoming connection
     */
    Request(Socket *socket);

    /**
     * get the method of the request(for example, BREW or POST)
     * @return the request method
     */
    std::string getMethod();

    /**
     * get the additions requested in this request
     * @return the additions requested
     */
    std::map<std::string, int> getAdditions();

    /**
     * get the body of this request
     * @return the request body
     */
    std::string getBody();
};


#endif //HTCPCP_REQUEST_H
