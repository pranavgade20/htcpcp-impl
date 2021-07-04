/*************************************************************************
 *  Copyright (C) 2020 by Manasvi Agrawal <lit2020029@gmail.com>         *
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

#include "Response.h"

#include <iostream>

Response::Response(int response_code, std::string response_code_string)
{
    this->response_code = response_code;
    this->response_code_string = response_code_string;

    headers["Server"] = "Coffee Pot";
    headers["Content-Type"] = "text/html; charset=utf-8";

        if (response_code == 200)
    {
        std::cout << "HTCPC/1.0 200 OK" << std::endl;
    }
    else if (response_code == 406)
    {
        std::cout << "HTCPC/1.0 406 Not Acceptable" << std::endl;
    }
    else if (response_code == 405)
    {
    }
    else if (response_code == 400)
    {
    }
    else if (response_code == 418)
    {
        std::cout << "HTCPC/1.0 418 I'm a teapot" << std::endl;
        headers["Server"] = "Tea Pot";
    }

    std::cout << "Server: " + headers["Server"] << std::endl;
    std::cout << "Content-Type: " + headers["Content-Type"] << std::endl;
    std::cout << body << std::endl;
}

void Response::sendResponse(Socket* socket) {
    *socket << "HTTP/1.0 " << this->response_code << this->response_code_string << "\r\n";
    for (auto it : this->headers) {
        *socket << it.first << ": " << it.second << "\r\n";
    }
    *socket << "\r\n" << this->body << "\r\n";
}

// Sample Response

// HTCPCP/1.0 406 Not Acceptable
// Date: Fri, 04 Jun 2021 15:22:53 GMT
// Server: Coffee Pot
// Content-Type: text/html; charset=utf-8

// HTCPCP/1.0 418 I'm a teapot
// Date: Fri, 04 Jun 2021 15:22:53 GMT
// Server: Tea Pot
// Content-Type: text/html; charset=utf-8

// HTCPCP/1.0 200 OK
// Date: Fri, 04 Jun 2021 15:22:53 GMT
// Server: Coffee Pot
// Content-Type: text/html; charset=utf-8
