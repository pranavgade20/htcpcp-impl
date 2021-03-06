/*************************************************************************
 *  Copyright (C) 2021 by Nehal Sharma <lcs2020001@iiitl.ac.in>           *
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

#ifndef HTCPCP_CUP_H
#define HTCPCP_CUP_H

#include <string>
#include <vector>

#include "additions/AlcoholType.h"
#include "additions/MilkType.h"
#include "additions/SpiceType.h"
#include "additions/SweetenerType.h"
#include "additions/SyrupType.h"

class Cup {
private:
    MilkType milk;
    SweetenerType sweetener;
    SyrupType syrup;
    SpiceType spice;
    AlcoholType alcohol;

    /**
     * @return array of strings of additions in this cup
     */
    std::vector <std::string> getAdditionsArray();

public:
    /**
     * basic constructor
     */
    Cup();

    /**
     * setter for milk
     */
    void setMilk(MilkType milk);

    /**
     * setter for sweetener
     */
    void setSweetener(SweetenerType sweetener);

    /**
     * setter for syrup
     */
    void setSyrup(SyrupType syrup);

    /**
     * setter for spice
     */
    void setSpice(SpiceType spice);

    /**
     * setter for alcohol
     */
    void setAlcohol(AlcoholType alcohol);

    /**
     * get addition name
     * @param addition code of addition
     * @return string of addition
     */
    static std::string getAdditionName(int addition);

    /**
     * get description of cup
     */
    std::string getDescription();
};


#endif //HTCPCP_CUP_H
