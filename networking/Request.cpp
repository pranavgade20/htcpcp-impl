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

#include "Request.h"

#include <iostream>

Request::Request(Socket *socket) {
    std::string method, path, protocol;
    *socket >> method;
    *socket >> path;
    *socket >> protocol;

    std::cout << method << path << std::endl;
    // TODO : read into a map
    std::string line;
    *socket >> line;
    std::cout << line << std::endl;
}


// Sample request

// BREW /pot-2 HTCPCP/1.0
// Host: localhost:8081
// User-Agent: curl
// Accept: text/html
// Accept-Language: en-US,en
// Content-type: application/coffee-pot-command; boundary=---------------------------58123037437716747452831683647
// Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;

// -----------------------------58123037437716747452831683647
// Content-Type: message/coffeepot

// start


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

// <html> Brewing </html>
