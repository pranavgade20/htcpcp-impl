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
    response_code_string = getErrorString(response_code);
    body = getErrorString(response_code);

    headers["Server"] = "Coffee Pot";
    if (response_code == 418) {
        headers["Server"] = "Tea Pot";
    }
    headers["Content-Type"] = "text/html; charset=utf-8";
} 

Response::Response(int response_code, std::string body) { 
    this->response_code = response_code;
    this->body = body;
    response_code_string = getErrorString(response_code);

    headers["Server"] = "Coffee Pot";
    if (response_code == 418) {
        headers["Server"] = "Tea Pot";
    }
    headers["Content-Type"] = "text/html; charset=utf-8";
}

// make a static method which gets error string from code, like I'm a teapot from 418

std::string Response::getErrorString(int response_code) {
    if (response_code == 200) {
        return "OK";
    }
    else if (response_code == 400) {
        return "Bad Request";
    }
    else if (response_code == 405) {
        return "Method Not Allowed";
    }
    else if (response_code == 406) {
        return "Not Acceptable";
    }
    else if (response_code == 415) {
        return "Unsupported Media Type";
    }
    else if (response_code == 418) {
        return "I'm a teapot";
    } else {
        return "Internal Server Error";
    }
}

void Response::sendResponse(Socket* socket) {
    *socket << "HTTP/1.0 " << this->response_code << getResponseString(this->response_code) << "\r\n";
    for (auto it : this->headers) {
        *socket << it.first << ": " << it.second << "\r\n";
    }
    *socket << "\r\n" << this->body << "\r\n";
}

std::string Response::getResponseString(int code) {
    switch (code) {
        case 200: return "OK";
        case 400: return "Bad Request";
        case 418: return "I'm a teapot";
        case 500: return "Server Error";
        //TODO add more
    }
    return "NOT IMPLEMENTED";
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
