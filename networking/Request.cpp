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

#include "Request.h"
#include "additions/AlcoholType.h"
#include "additions/MilkType.h"
#include "additions/SpiceType.h"
#include "additions/SweetenerType.h"
#include "additions/SyrupType.h"

#include <iostream>
#include <sstream>

int getAddition(std::string type, std::string content);

std::string readuntil(Socket *in, std::string delimiter) {
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

Request::Request(Socket *socket) {
    *socket >> method;
    *socket >> path;
    *socket >> protocol;

    std::string temp = readuntil(socket, "\r\n");
    while ((temp = readuntil(socket, "\r\n")) != "") {
        int split = temp.find(": ", 0);
        if (split == std::string::npos) {
            method = "INVALID";
            return;
        }
        headers[temp.substr(0, split)] = temp.substr(split + 2, temp.length());
    }

    size_t ptr = 0;
    std::string delimiter = "; ";
    if (headers.count("Accept-Additions")) {
        addition_map["milk-type"] = (int) MilkType::NONE;
        addition_map["sweetener-type"] = (int) SweetenerType::NONE;
        addition_map["syrup-type"] = (int) SyrupType::NONE;
        addition_map["spice-type"] = (int) SpiceType::NONE;
        addition_map["alcohol-type"] = (int) AlcoholType::NONE;

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
            std::string addition_content = addition.substr(split + 1, addition.length());
            addition_map[addition_type] = getAddition(addition_type, addition_content);

            additions.erase(0, ptr + delimiter.length());
        }
        addition = additions.substr(0, ptr);
        int split = addition.find("=", 0);
        if (split == std::string::npos) {
            method = "INVALID";
            return;
        }
        std::string addition_type = addition.substr(0, split);
        std::string addition_content = addition.substr(split + 1, addition.length() - split - 2);
        addition_map[addition_type] = getAddition(addition_type, addition_content);
    }

    if (headers.count("Content-type") != 0) {
        std::string content_type = headers["Content-type"];
        while ((ptr = content_type.find(delimiter)) != std::string::npos) {
            std::string sub = content_type.substr(0, ptr);
            int split = sub.find("=", 0);
            if (split != std::string::npos) {
                std::string title = sub.substr(0, split);
                std::string value = sub.substr(split + 1, sub.length());
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
        if (content == "Whisky") return (int) AlcoholType::WHISKY;
        else if (content == "Rum") return (int) AlcoholType::RUM;
        else if (content == "Kahlua") return (int) AlcoholType::KAHLUA;
        else if (content == "Aquavit") return (int) AlcoholType::AQUAVIT;
        else return (int) AlcoholType::NONE;
    } else if (type == "milk-type") {
        if (content == "Cream") return (int) MilkType::CREAM;
        else if (content == "Half-and-half") return (int) MilkType::HALF_AND_HALF;
        else if (content == "Part-Skim") return (int) MilkType::PART_SKIM;
        else if (content == "Skim") return (int) MilkType::SKIM;
        else if (content == "Non-Dairy") return (int) MilkType::NON_DAIRY;
        else if (content == "Whole-milk") return (int) MilkType::WHOLE_MILK;
        else return (int) MilkType::NONE;
    } else if (type == "spice-type") {
        if (content == "Cinnamon") return (int) SpiceType::CINNAMON;
        else if (content == "Nutmeg") return (int) SpiceType::NUTMEG;
        else if (content == "Cardamom") return (int) SpiceType::CARDAMOM;
        else if (content == "Clove") return (int) SpiceType::CLOVE;
        else return (int) SpiceType::NONE;
    } else if (type == "sweetener-type") {
        if (content == "Sugar") return (int) SweetenerType::SUGAR;
        else if (content == "Stevia") return (int) SweetenerType::STEVIA;
        else if (content == "Honey") return (int) SweetenerType::HONEY;
        else if (content == "Maple-syrup") return (int) SweetenerType::MAPLE_SYRUP;
        else if (content == "Agave") return (int) SweetenerType::AGAVE;
        else return (int) SweetenerType::NONE;
    } else if (type == "syrup-type") {
        if (content == "Vanilla") return (int) SyrupType::VANILLA;
        else if (content == "Almond") return (int) SyrupType::ALMOND;
        else if (content == "Raspberry") return (int) SyrupType::RASPBERRY;
        else if (content == "Chocolate") return (int) SyrupType::CHOCOLATE;
        else return (int) SyrupType::NONE;
    }
    return -1;
}
