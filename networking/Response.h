/*************************************************************************
 *  Copyright (C) 2020 by Manasvi Agrawal <lit2020029@gmail.com>           *
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

#ifndef HTCPCP_RESPONSE_H
#define HTCPCP_RESPONSE_H

#include <string>
#include "Request.h"
#include "CoffeePot.h"
#include "TeaPot.h"

class Response
{
private:
    int response_code;
    std::string body;
    std::string headers;
public:
    Response(int response_code, std::string body);
};

#endif // HTCPCP_RESPONSE_H/**//// HTCPCP/1.0 418 I'm a teapot// Date: Fri, 04 Jun 2021 15:22:53 GMT// Server: Tea Pot// Content-Type: text/html; charset=utf-8//// Your coffee with skin milk, maple syrup is eready :))D3)))