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
#include "additions/AlcoholType.h"
#include "additions/MilkType.h"
#include "additions/SpiceType.h"
#include "additions/SweetenerType.h"
#include "additions/SyrupType.h"

#include <iostream>
#include <sstream>

int getAddition(std::string type, std::string content);
std::string readuntil(Socket *in, std::string delimiter)
{
    std::string cr;
    char delim = *(delimiter.rbegin());
    size_t sz = delimiter.size(), tot;
    do {
        std::string temp;
        std::getline(*in, temp, delim);
        cr += temp + delim;
        tot = cr.size();
    } while ((tot < sz) || (cr.substr(tot - sz, sz) != delimiter));
    return cr.substr(0, tot - sz);
}

Request::Request(Socket *socket)
{
    *socket >> method;
    *socket >> path;
    *socket >> protocol;

    std::string temp = readuntil(socket, "\r\n");
    while ((temp = readuntil(socket, "\r\n")) != "") {
//        std::cout << temp << std::endl;
        int split = temp.find(": ", 0);
        if (split == std::string::npos) {
            method = "INVALID";
            return;
        }
        headers[temp.substr(0, split)] = temp.substr(split + 2, temp.length());
//        std::cout << temp.substr(0, split) << "||" << temp.substr(split + 2, temp.length()) << std::endl;
    }

    size_t ptr = 0;
    std::string delimiter = "; ";
    if (headers.count("Accept-Additions")) {
        std::string additions = headers["Accept-Additions"];
        std::string addition;
        while ((ptr = additions.find(delimiter)) != std::string::npos) {
            addition = additions.substr(0, ptr);
            int split = addition.find("=", 0);
            if (split == std::string::npos) {
                method = "INVALID";
                return;
            }
            std::string addition_type = addition.substr(0, split);
            std::string addition_content = addition.substr(split + 2, addition.length());

            addition_map[addition_type] = getAddition(addition_type, addition_content);

            additions.erase(0, ptr + delimiter.length());
        }
    }

    if (headers.count("Content-type") != 0) {
        std::string content_type = headers["Content-type"];
        while ((ptr = content_type.find(delimiter)) != std::string::npos) {
            std::string sub = content_type.substr(0, ptr);
            int split = sub.find("=", 0);
            if (split != std::string::npos) {
                std::string title = sub.substr(0, split);
                std::string value = sub.substr(split + 2, sub.length());
                if (title == "boundary") {
                    readuntil(socket, value);
                    break;
                }
            }
            content_type.erase(0, ptr + delimiter.length());
        }

        while ((temp = readuntil(socket, "\r\n")) != "") {
            std::cout << temp << std::endl;
            body_headers.push_back(temp);
        }
    }

    body = readuntil(socket, "\r\n");
}

std::string Request::getMethod() {
    return this->method;
}

std::map<std::string, int> Request::getAdditions() {
    return this->addition_map;
}

std::string Request::getBody() {
    return this->body;
}

int getAddition(std::string type, std::string content) {
    if (type == "alcohol-type") {
        if (content == "Whiskey") return (int)AlcoholType::WHISKY;
        else if (content == "Rum") return (int)AlcoholType::RUM;
        else if (content == "Kahlua") return (int)AlcoholType::KAHLUA;
        else if (content == "Aquavit") return (int)AlcoholType::AQUAVIT;
        else return (int)AlcoholType::NONE;
    } else if (type == "milk-type") {
        if (content == "Cream") return (int)MilkType::CREAM;
        else if (content == "Half-and-half") return (int)MilkType::HALF_AND_HALF;
        else if (content == "Part-Skim") return (int)MilkType::PART_SKIM;
        else if (content == "Skim") return (int)MilkType::SKIM;
        else if (content == "Non-Dairy") return (int)MilkType::NON_DAIRY;
        else if (content == "Whole-milk") return (int)MilkType::WHOLE_MILK;
        else return (int)MilkType::NONE;
    } else if (type == "spice-type") {
        if (content == "Cinnamon") return (int)SpiceType::CINNAMON;
        else if (content == "Nutmeg") return (int)SpiceType::NUTMEG;
        else if (content == "Cardamom") return (int)SpiceType::CARDAMOM;
        else if (content == "Clove") return (int)SpiceType::CLOVE;
        else return (int)SpiceType::NONE;
    } else if (type == "sweetener-type") {
        if (content == "Sugar") return (int)SweetenerType::SUGAR;
        else if (content == "Stevia") return (int)SweetenerType::STEVIA;
        else if (content == "Honey") return (int)SweetenerType::HONEY;
        else if (content == "Maple-syrup") return (int)SweetenerType::MAPLE_SYRUP;
        else if (content == "Agave") return (int)SweetenerType::AGAVE;
        else return (int)SweetenerType::NONE;
    }
    return -1;
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
