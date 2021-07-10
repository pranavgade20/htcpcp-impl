/*************************************************************************
 *  Copyright (C) 2021 by Pranav Gade <pranavgade20@gmail.com>, Nehal Sharma <lcs2020001@iiitl.ac.in>           *
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

#ifndef HTCPCP_POT_H
#define HTCPCP_POT_H

#include <string>
#include <map>
#include "Cup.h"
#include <Socket.h>
#include <HTTPRequestType.h>
#include <Request.h>
#include <Response.h>
#include "additions/AlcoholType.h"
#include "additions/MilkType.h"
#include "additions/SpiceType.h"
#include "additions/SweetenerType.h"
#include "additions/SyrupType.h"

class Response;

class Pot {
private:
    /**
     * a state variable
     */
    bool brewing;
    /**
     * pointer to a cup in brewing state
     */
    Cup *cup;    
protected:    
    /**
     * adds the requested milk to the cup while brewing
     */
    virtual void addMilk(int type);
    /**
     * adds the requested sweetener to the cup while brewing
     */
    virtual void addSweetener(int type);
    /**
     * adds the requested syrup to the cup while brewing
     */
    virtual void addSyrup(int type);
    /**
     * adds the requested spice to the cup while brewing
     */
    virtual void addSpice(int type);
    /**
     * adds the requested alcohol to the cup while brewing
     */
    virtual void addAlcohol(int type);
public:
    /**
     * a constructor
     */
    Pot() : brewing(false), cup(nullptr) {};
    /**
     * responds to BREW and POST requests, else sends a response with appropriate error
     */
    Response *brew(Request *req);
    /**
     * getter for current server name
     */
    virtual std::string getServerName();
    /**
     * removes and returns the cup pointed to by this pot
     */    
    Cup *removeCup();
    /**
     * getter for brewing
     */    
    bool isBrewing();
};


#endif //HTCPCP_POT_H
