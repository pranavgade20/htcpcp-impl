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

#ifndef HTCPCP_SWEETENERTYPE_H
#define HTCPCP_SWEETENERTYPE_H


enum class SweetenerType {
    NONE = 3 << 29, SUGAR, STEVIA, HONEY, MAPLE_SYRUP, AGAVE,
};


#endif //HTCPCP_SWEETENERTYPE_H
