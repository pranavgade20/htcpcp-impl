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
#include <sstream>

std::string readuntil(Socket *in, std::string delimiter)
{
    std::string cr;
    char delim = *(delimiter.rbegin());
    size_t sz = delimiter.size(), tot;
    do
    {
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
    while ((temp = readuntil(socket, "\r\n")) != "")
    {
        std::cout << temp << std::endl;
        int split = temp.find(": ", 0);
        if (split == std::string::npos)
        {
            method = "INVALID";
            return;
        }
        headers[temp.substr(0, split)] = temp.substr(split + 2, temp.length());
        std::cout << temp.substr(0, split) << "||" << temp.substr(split + 2, temp.length()) << std::endl;
    }

    if (headers["Content-Type"] != "message/coffeepot")
    {
        method = "INVALID";
        return;
    }
    if (headers.count("Accept-Additions") == 0)
    {
        method = "INVALID";
        return;
    }

    std::string additions = headers["Accept-Additions"];
    std::string delimiter = "; ";
    size_t ptr = 0;
    std::string addition;
    while ((ptr = additions.find(delimiter)) != std::string::npos)
    {
        addition = additions.substr(0, ptr);
        int split = addition.find("=", 0);
        if (split == std::string::npos)
        {
            method = "INVALID";
            return;
        }
        std::string addition_type = addition.substr(0, split);
        std::string addition_content = addition.substr(split + 2, addition.length());

        addition_map[addition_type] = getAddition(addition_type, addition_content);

        additions.erase(0, ptr + delimiter.length());
    }
    std::cout << additions << std::endl;

    //TODO parse boundary and set content
}

int getAddition(std::string type, std::string content)
{
    if (addition_map["milk-type"] == "CREAM")
    {
        return MilkType::CREAM;
    }
    else if (addition_map["milk-type"] == "HALF_AND_HALF")
    {
        return ilkType::HALF_AND_HALF;
    }
    else if (addition_map["milk-type"] == "WHOLE_MILK")
    {
        return MilkType::WHOLE_MILK;
    }
    else if (addition_map["milk-type"] == "PART_SKIM")
    {
        return MilkType::PART_SKIM;
    }
    else if (addition_map["milk-type"] == "NON_DAIRY")
    {
        return MilkType::NON_DAIRY;
    }
    if (addition_map["spice-type"] == "CINNAMON")
    {
        return SpiceType::CINNAMON;
    }
    else if (addition_map["spice-type"] == "NUTMEG")
    {
        return SpiceType::NUTMEG;
    }
    else if (addition_map["spice-type"] == "CARDAMOM")
    {
        return SpiceType::CARDAMOM;
    }
    else if (addition_map["spice-type"] == "CLOVE")
    {
        return SpiceType::CLOVE;
    }
    else
    {
    }
    if (addition_map["sweetener-type"] == "SUGAR")
    {
        return SweetenerType::SUGAR;
    }
    else if (addition_map["sweetener-type"] == "STEVIA")
    {
        return SweetenerType::STEVIA;
    }
    else if (addition_map["sweetener-type"] == "HONEY")
    {
        return SweetenerType::HONEY;
    }
    else if (addition_map["sweetener-type"] == "MAPLE_SYRUP")
    {
        return SweetenerType::MAPLE_SYRUP;
    }
    else if (addition_map["sweetener-type"] == "AGAVE")
    {
        return SweetenerType::AGAVE;
    }
    if (addition_map["syrup-type"] == "VANILLA")
    {
        return SyrupType::VANILLA;
    }
    else if (addition_map["syrup-type"] == "ALMOND")
    {
        return SyrupType::ALMOND;
    }
    else if (addition_map["syrup-type"] == "RASPBERRY")
    {
        return SyrupType::RASPBERRY;
    }
    else if (addition_map["syrup-type"] == "CHOCOLATE")
    {
        return SyrupType::CHOCOLATE;
    }
    if (addition_map["alcohol-type"] == "WHISKY")
    {
        return AlcoholType::WHISKY;
    }
    else if (addition_map["alcohol-type"] == "RUM")
    {
        return AlcoholType::RUM;
    }
    else if (addition_map["alcohol-type"] == "KAHLUA")
    {
        return AlcoholType::KAHLUA;
    }
    else if (addition_map["alcohol-type"] == "AQUAVIT")
    {
        return AlcoholType::AQUAVIT;
    }
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
