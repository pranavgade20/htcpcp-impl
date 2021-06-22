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

#include "Cup.h"

#include "additions/AlcoholType.h"
#include "additions/MilkType.h"
#include "additions/SpiceType.h"
#include "additions/SweetenerType.h"
#include "additions/SyrupType.h"

Cup::setMilk(int key) {
    milk = static_cast<MilkType>(key);
};

Cup::setSweetener(int key) {
    sweetener = static_cast<SweetenerType>(key);
};

Cup::setSyrup(int key) {
    syrup = static_cast<SyrupType>(key);
};

Cup::setSpice(int key) {
    spice = static_cast<SpiceType>(key);
};

Cup::setAlcohol(int key) {
    alcohol = static_cast<AlcoholType>(key);
};
