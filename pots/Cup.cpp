/*************************************************************************
 *  Copyright (C) 2020 by Nehal Sharma <lcs2020001@iiitl.ac.in>          *
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

#include <iostream>
#include <string>
#include "Cup.h"

#include "additions/AlcoholType.h"
#include "additions/MilkType.h"
#include "additions/SpiceType.h"
#include "additions/SweetenerType.h"
#include "additions/SyrupType.h"

Cup::Cup() {
    milk = MilkType::NONE;
    sweetener = SweetenerType::NONE;
    syrup = SyrupType::NONE;
    spice = SpiceType::NONE;
    alcohol = AlcoholType::NONE;
}

void Cup::setMilk(MilkType milk) {
    this->milk = milk;
    std::cout << "Milk set to " << getAdditionName((int)milk) << std::endl;
};

void Cup::setSweetener(SweetenerType sweetener) {
    this->sweetener = sweetener;
    std::cout << "Sweetener set to " << getAdditionName((int)sweetener) << std::endl;
};

void Cup::setSyrup(SyrupType syrup) {
    this->syrup = syrup;
    std::cout << "Syrup set to " << getAdditionName((int)syrup) << std::endl;
};

void Cup::setSpice(SpiceType spice) {
    this->spice = spice;
    std::cout << "Spice set to " << getAdditionName((int)spice) << std::endl;
};

void Cup::setAlcohol(AlcoholType alcohol) {
    this->alcohol = alcohol;
    std::cout << "Alcohol set to " << getAdditionName((int)alcohol) << std::endl;
};

std::string Cup::getAdditionName(int addition) {
    switch (addition) {
        case ((int)MilkType::CREAM):
            return "Cream";
        case ((int)MilkType::HALF_AND_HALF):
            return "Half and Half";
        case ((int)MilkType::WHOLE_MILK):
            return "Whole Milk";
        case ((int)MilkType::PART_SKIM):
            return "Part Skim Milk";
        case ((int)MilkType::SKIM):
            return "Skim Milk";
        case ((int)MilkType::NON_DAIRY):
            return "Non-Dairy Milk";
        case ((int)SpiceType::CINNAMON):
            return "Cinnamon";
        case ((int)SpiceType::NUTMEG):
            return "Nutmeg";
        case ((int)SpiceType::CARDAMOM):
            return "Cardamom";
        case ((int)SpiceType::CLOVE):
            return "Clove";
        case ((int)SweetenerType::SUGAR):
            return "Sugar";
        case ((int)SweetenerType::STEVIA):
            return "Stevia";
        case ((int)SweetenerType::HONEY):
            return "Honey";
        case ((int)SweetenerType::MAPLE_SYRUP):
            return "Maple Syrup";
        case ((int)SweetenerType::AGAVE):
            return "Agave";
        case ((int)SyrupType::VANILLA):
            return "Vanilla Syrup";
        case ((int)SyrupType::ALMOND):
            return "Almond Syrup";
        case ((int)SyrupType::RASPBERRY):
            return "Raspberry Syrup";
        case ((int)SyrupType::CHOCOLATE):
            return "Chocolate Syrup";
        case ((int)AlcoholType::WHISKY):
            return "Whisky";
        case ((int)AlcoholType::RUM):
            return "Rum";
        case ((int)AlcoholType::KAHLUA):
            return "Kahlua";
        case ((int)AlcoholType::AQUAVIT):
            return "Aquavit";
        default:
            return "None";
    }
}

std::vector <std::string> Cup::getAdditionsArray() {
    std::vector <std::string> ret;
    if (this->milk != MilkType::NONE) ret.push_back(getAdditionName((int)this->milk));
    if (this->sweetener != SweetenerType::NONE) ret.push_back(getAdditionName((int)this->sweetener));
    if (this->syrup != SyrupType::NONE) ret.push_back(getAdditionName((int)this->syrup));
    if (this->spice != SpiceType::NONE) ret.push_back(getAdditionName((int)this->spice));
    if (this->alcohol != AlcoholType::NONE) ret.push_back(getAdditionName((int)this->alcohol));
    return ret;
}

std::string Cup::getDescription() {
    std::vector<std::string> additions = getAdditionsArray();
    std::string output = "";

    for (int i = 0; i < additions.size() - 2; ++i) {
        output += additions[i] + ", ";
    }

    if (additions.size() >= 2) {
        output += additions[additions.size()-2] + ", and ";

    }

    if (additions.size() >= 1) {
        output += additions[additions.size()-1];

    }
    return output;
}
