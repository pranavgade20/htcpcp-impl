/*************************************************************************
 *  Copyright (C) 2021 by Pranav Gade <pranavgade20@gmail.com>,          *
 *  Nehal Sharma <lcs2020001@iiitl.ac.in>                                *
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

#include <iostream>

Response *Pot::brew(Request *req) {
    if (req->getMethod() != "POST" && req->getMethod() != "BREW") {
        Response* ret =  new Response(405);
        ret->addHeader("Server", this->getServerName());
        return ret;
    }

    std::string body = req->getBody();
    if (body == "start" && brewing == false) {
        cup = new Cup();
        brewing = true;
        try {
            addMilk(req->getAdditions()["milk-type"]);
            addSweetener(req->getAdditions()["sweetener-type"]);
            addSyrup(req->getAdditions()["syrup-type"]);
            addSpice(req->getAdditions()["spice-type"]);
            addAlcohol(req->getAdditions()["alcohol-type"]);
            Response* ret =  new Response(200, "Started brewing your coffee...");
            ret->addHeader("Server", this->getServerName());
            return ret;
        }
        catch (int err) {
            Response* ret =  new Response(err);
            ret->addHeader("Server", this->getServerName());
            return ret;
        }
    } else if (body == "stop" && brewing && cup != nullptr) {
        brewing = false;
        Cup *readyCup = removeCup();
        if (readyCup->getDescription() == "") {
            std::string description = "Your Coffee is ready!";
            Response* ret =  new Response(200, description);
            ret->addHeader("Server", this->getServerName());
            return ret;
        } else {
            std::string description = "Your Coffee with " + readyCup->getDescription() + " is ready!";
            Response* ret =  new Response(200, description);
            ret->addHeader("Server", this->getServerName());
            return ret;
        }
    } else {
        Response* ret =  new Response(400);
        ret->addHeader("Server", this->getServerName());
        return ret;
    }
}

/**
 * get the cup from this pot
 * @return pointer to cup if not removed already, nullptr otherwise
 */
Cup *Pot::removeCup() {
    Cup *ret = cup;
    cup = nullptr;
    return ret;
}

void Pot::addMilk(int type) {
    MilkType milk = static_cast<MilkType>(type);
    cup->setMilk(milk);
};

void Pot::addSweetener(int type) {
    SweetenerType sweetener = static_cast<SweetenerType>(type);
    cup->setSweetener(sweetener);
};

void Pot::addSyrup(int type) {
    SyrupType syrup = static_cast<SyrupType>(type);
    cup->setSyrup(syrup);
};

void Pot::addSpice(int type) {
    SpiceType spice = static_cast<SpiceType>(type);
    cup->setSpice(spice);
};

void Pot::addAlcohol(int type) {
    AlcoholType alcohol = static_cast<AlcoholType>(type);
    cup->setAlcohol(alcohol);
}

bool Pot::isBrewing() {
    return brewing;
}

std::string Pot::getServerName() {
    return "Pot";
};
