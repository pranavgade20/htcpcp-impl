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

#ifndef HTCPCP_SPICETYPE_H
#define HTCPCP_SPICETYPE_H

/**
 * This enum represents all the available spice type additions
 */
enum class SpiceType {
    NONE = 2 << 29, CINNAMON, NUTMEG, CARDAMOM, CLOVE,
};


#endif //HTCPCP_SPICETYPE_H
