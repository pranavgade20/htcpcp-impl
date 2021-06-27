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

#include "additions/AlcoholType.h"
#include "additions/MilkType.h"
#include "additions/SpiceType.h"
#include "additions/SweetenerType.h"
#include "additions/SyrupType.h"

void Pot::brew(Request* req) {
    // placeholder additions map, called add_map from req
    std::map<std::string, int> add_map;
    cup = new Cup;
    brewing = true;
    addMilk(cup, add_map["milk-type"]);
    addSweetener(cup, add_map["sweetener-type"]); 
    addSyrup(cup, add_map["syrup-type"]);
    addSpice(cup, add_map["spice-type"]);
    addAlcohol(cup, add_map["alcohol-type"]);
    brewing = false;
};

/**
 * get the cup from this pot
 * @return pointer to cup if not removed already, nullptr otherwise
 */
Cup* Pot::removeCup() {
    Cup* ret = cup;
    cup = nullptr;
    return ret;
}

void Pot::addMilk(Cup* cup, int type) {
    MilkType milk = static_cast<MilkType>(type);
    cup->setMilk(milk);
};

void Pot::addSweetener(Cup* cup, int type) {
    SweetenerType sweetener = static_cast<SweetenerType>(type);
    cup->setSweetener(sweetener);
};

void Pot::addSyrup(Cup* cup, int type) {
    SyrupType syrup = static_cast<SyrupType>(type);
    cup->setSyrup(syrup);
};

void Pot::addSpice(Cup* cup, int type) {
    SpiceType spice = static_cast<SpiceType>(type);
    cup->setSpice(spice);
};

void Pot::addAlcohol(Cup* cup, int type) {
    AlcoholType alcohol = static_cast<AlcoholType>(type);
    cup->setAlcohol(alcohol);
}

bool Pot::isBrewing() {
    return brewing;
};


