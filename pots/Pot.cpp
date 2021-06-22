/*************************************************************************
 *  Copyright (C) 2020 by Pranav Gade <pranavgade20@gmail.com>, Nehal Sharma <lcs2020001@iiitl.ac.in>            *
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

#include "Pot.h"
#include "Cup.h"

Cup* Pot::brew(Request req) {
    // placeholder additions map, called add_map from req
    std::map<std::string, std::string> add_map;
    Cup* cup = new Cup;
    brewing = true;
    addMilk(cup, add_map["milk-type"]);
    addSweetener(cup, add_map["sweetener-type"]); 
    addSyrup(cup, add_map["syrup-type"]);
    addSpice(cup, add_map["spice-type"]);
    addAlcohol(cup, add_map["alcohol-type"]);
    return cup; 
};

Pot::addMilk(Cup* cup, std::string type) {
    
};

Pot::addSweetener(Cup* cup, std::string type) {
    
};

Pot::addSyrup(Cup* cup, std::string type) {
    
};

Pot::addSpice(Cup* cup, std::string type) {
    
};

Pot::addAlcohol(Cup* cup, std::string type) {
    
};


