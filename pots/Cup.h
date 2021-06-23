/*************************************************************************
 *  Copyright (C) 2020 by Nehal Sharma <lcs2020001@iiitl.ac.in>           *
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
public:
    Cup();
    void setMilk(MilkType milk);
    void setSweetener(SweetenerType sweetener);
    void setSyrup(SyrupType syrup);
    void setSpice(SpiceType spice);
    void setAlcohol(AlcoholType alcohol);
};


#endif //HTCPCP_CUP_H
