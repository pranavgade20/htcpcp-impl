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

Cup::Cup()
{
    milk = MilkType::NONE;
    sweetener = SweetenerType::NONE;
    syrup = SyrupType::NONE;
    spice = SpiceType::NONE;
    alcohol = AlcoholType::NONE;
}

void Cup::setMilk(MilkType milk)
{
    this->milk = milk;
    std::cout << "Milk set to " << (int)milk << std::endl;
};

void Cup::setSweetener(SweetenerType sweetener)
{
    this->sweetener = sweetener;
    std::cout << "Sweetener set to " << (int)sweetener << std::endl;
};

void Cup::setSyrup(SyrupType syrup)
{
    this->syrup = syrup;
    std::cout << "Syrup set to " << (int)syrup << std::endl;
};

void Cup::setSpice(SpiceType spice)
{
    this->spice = spice;
    std::cout << "Spice set to " << (int)spice << std::endl;
};

void Cup::setAlcohol(AlcoholType alcohol)
{
    this->alcohol = alcohol;
    std::cout << "Alcohol set to " << (int)alcohol << std::endl;
};

std::vector<std::string> Cup::getAdditionsArray()
{
    std::vector<std::string> v1;
    if (milk == MilkType::CREAM)
    {
        v1.push_back("Cream");
    }
    else if (milk == MilkType::HALF_AND_HALF)
    {
        v1.push_back("Half and Half");
    }
    else if (milk == MilkType::WHOLE_MILK)
    {
        v1.push_back("Whole Milk");
    }
    else if (milk == MilkType::PART_SKIM)
    {
        v1.push_back("Part Skim Milk");
    }
    else if (milk == MilkType::SKIM)
    {
        v1.push_back("Skim Milk");
    }
    else if (milk == MilkType::NON_DAIRY)
    {
        v1.push_back("Non-Dairy Milk");
    }
    if (spice == SpiceType::CINNAMON)
    {
        v1.push_back("Cinnamon");
    }
    else if (spice == SpiceType::NUTMEG)
    {
        v1.push_back("Nutmeg");
    }
    else if (spice == SpiceType::CARDAMOM)
    {
        v1.push_back("Cardamom");
    }
    else if (spice == SpiceType::CLOVE)
    {
        v1.push_back("Clove");
    }
    if (sweetener == SweetenerType::SUGAR)
    {
        v1.push_back("Sugar");
    }
    else if (sweetener == SweetenerType::STEVIA)
    {
        v1.push_back("Stevia");
    }
    else if (sweetener == SweetenerType::HONEY)
    {
        v1.push_back("Honey");
    }
    else if (sweetener == SweetenerType::MAPLE_SYRUP)
    {
        v1.push_back("Maple Syrup");
    }
    else if (sweetener == SweetenerType::AGAVE)
    {
        v1.push_back("Agave");
    }
    if (syrup == SyrupType::VANILLA)
    {
        v1.push_back("Vanilla Syrup");
    }
    else if (syrup == SyrupType::ALMOND)
    {
        v1.push_back("Almond Syrup");
    }
    else if (syrup == SyrupType::RASPBERRY)
    {
        v1.push_back("Raspberry Syrup");
    }
    else if (syrup == SyrupType::CHOCOLATE)
    {
        v1.push_back("Chocolate Syrup");
    }
    if (alcohol == AlcoholType::WHISKY)
    {
        v1.push_back("Whisky");
    }
    else if (alcohol == AlcoholType::RUM)
    {
        v1.push_back("Rum");
    }
    else if (alcohol == AlcoholType::KAHLUA)
    {
        v1.push_back("Kahlua");
    }
    else if (alcohol == AlcoholType::AQUAVIT)
    {
        v1.push_back("Aquavit");
    }
    return v1;
}

std::string Cup::getDescription()
{
    std::vector<std::string> v2 = getAdditionsArray();
    int size = v2.size();
    std::string output = "";
    for (int i = 0; i < size - 2; i++)
    {
        output += v2[i];
        output += ", ";
    }
    if(size>=2) {
        output += v2[size - 2];
        output += " and ";
    }
    if(size>=1) {
        output += v2[size - 1];
    }
    return output;    
}
