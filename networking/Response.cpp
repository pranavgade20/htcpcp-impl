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

Response::Response(int response_code) {
    this->response_code = response_code;
    error_string(response_code);
    body = response_code_string;

    headers["Server"] = "Coffee Pot";
    if (response_code == 418) {
        headers["Server"] = "Tea Pot";
    }
    headers["Content-Type"] = "text/html; charset=utf-8";
} 

Response::Response(int response_code, std::string body) { 
    this->response_code = response_code;
    // this->response_code_string = response_code_string;
    this->body = body;

    headers["Server"] = "Coffee Pot";
    if (response_code == 418) {
        headers["Server"] = "Tea Pot";
    }
    headers["Content-Type"] = "text/html; charset=utf-8";
}

// make a static method which gets error string from code, like I'm a teapot from 418

void Response::error_string(int response_code) {
    if (response_code == 200) {
        response_code_string = "OK";
    }
    else if (response_code == 400) {
        response_code_string = "Bad Request";
    }
    else if (response_code == 405) {
        response_code_string = "Method Not Allowed";
    }
    else if (response_code == 406) {
        response_code_string = "Not Acceptable";
    }
    else if (response_code == 415) {
        response_code_string = "Unsupported Media Type";
    }
    else if (response_code == 418) {
        response_code_string = "I'm a teapot";
    }
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
