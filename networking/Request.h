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
    std::map <std::string, std::string> headers;
    std::map<std::string, int> addition_map;
    std::vector <std::string> body_headers;
    std::string method;
    std::string path;
    std::string protocol;
    std::string body;
public:
    Request(Socket *socket);

    std::string getMethod();

    std::map<std::string, int> getAdditions();

    std::string getBody();
};


#endif //HTCPCP_REQUEST_H
