/*************************************************************************
 *  Copyright (C) 2020 by Pranav Gade <pranavgade20@gmail.com>           *
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

#include "Request.h"

#include <iostream>

Request::Request(Socket *socket) {
  private:
    std::string method, path, protocol;
    *socket >> method;
    *socket >> path;
    *socket >> protocol;
  public:
    

std::cout << method << path << std::endl;
string input;
string line;

while (getline(cin, line))
{   input+="$";
    input += line;
    if (line == "start")
        break;
}

stringstream obj(input);
string temp=" ";
int t=6;
while(t--){
    getline(obj,temp,':');
    };
    getline(obj,temp,';');
string content_type=temp.substr(temp.find(" ")+1,(temp.length()-1));

obj.str(std::string());
obj<<input;

t=8;
while(t--){
    getline(obj,temp,'$');
}
string accept_additions=temp.substr(temp.find(" ")+1,(temp.length()-17));

obj.str(std::string());
obj<<accept_additions;
temp=" ";

vector<string> holder;

map <string, int> add_map;

// initialising all additions with NONE    
add_map["milk-type"] = MilkType::NONE;
add_map["spice-type"] = SpiceType::NONE;
add_map["sweetener-type"] = SweetenerType::NONE;
add_map["syrup-type"] = SyrupType::NONE;
add_map["alcohol-type"] = AlcoholType::NONE;
    
while(obj>>temp){
    holder.push_back(temp);
}
vector<string> ::iterator it=holder.begin();
while (it!=holder.end())
{
    stringstream tempobj;
    string temp1=*it;
    tempobj<<temp1;
    string type;
    string val;
    getline(tempobj,type,'=');
    getline(tempobj,val,';');

    if(type=="milk-type) {
        if(val=="Cream"){
            add_map[type]=MilkType::CREAM;
        }
        else if(val=="Half-and-half"){
            add_map[type]=MilkType::HALF_AND_HALF;
        }
        else if(val=="Whole-milk"){
            add_map[type]=MilkType::WHOLE_MILK;
        }
        else if(val=="Part-skim"){
            add_map[type]=MilkType::PART_SKIM;
        }
        else if(val=="Skim"){
            add_map[type]=MilkType::SKIM;
        }
        else if(val=="Non-dairy"){
            add_map[type]=MilkType::NON_DAIRY;
        }
        else {
            throw string("wrong milk-type");
        }
    } else if(type=="spice-type") {
        if(val=="Cinnamon"){
            add_map[type]=SpiceType::CINNAMON;
        }
        else if(val=="Nutmeg"){
            add_map[type]=SpiceType::NUTMEG;
        }
        else if(val=="Cardamom"){
            add_map[type]=SpiceType::CARDAMOM;
        }
        else if(val=="Clove"){
            add_map[type]=SpiceType::CLOVE;
        }
        else {
            throw string("wrong spice type");
        }
    } else if(type=="sweetener-type") {
        if(val=="Sugar"){
            add_map[type]=SweetenerType::SUGAR;
        }
        else if(val=="Stevia"){
            add_map[type]=SweetenerType::STEVIA;
        }
        else if(val=="Honey"){
            add_map[type]=SweetenerType::HONEY;
        }
        else if(val=="Maple-syrup"){
            add_map[type]=SweetenerType::MAPLE_SYRUP;
        }
        else if(val=="Agave"){
            add_map[type]=SweetenerType::AGAVE;
        }
        else {
            throw string("wrong sweetener type");
        }
    } else if(type=="syrup-type") {
        if(val=="Vanilla"){
            add_map[type]=SyrupType::VANILLA;
        }
        else if(val=="Almond"){
            add_map[type]=SyrupType::ALMOND;
        }
        else if(val=="Raspberry"){
            add_map[type]=SyrupType::RASPBERRY;
        }
        else if(val=="Chocolate"){
            add_map[type]=SyrupType::CHOCOLATE;
        }
        else {
            throw string("wrong syrup type");
        }
    } else if(type=="alcohol-type){
        if(val=="Whisky"){
            add_map[type]=AlcoholType::WHISKY;
        }
        else if(val=="Rum"){
            add_map[type]=AlcoholType::RUM;
        }
        else if(val=="Kahlua"){
            add_map[type]=AlcoholType::KAHLUA;
        }
        else if(val=="Aquavit"){
            add_map[type]=AlcoholType::AQUAVIT;
        }
        else {
            throw string("wrong alcohol type");
        }
    } else {
        throw string("wrong addition type");
    }
    it++;
    std::string line;
    *socket >> line;
    std::cout << line << std::endl;
}


// Sample request

// BREW /pot-2 HTCPCP/1.0
// Host: localhost:8081
// User-Agent: curl
// Accept: text/html
// Accept-Language: en-US,en
// Content-type: application/coffee-pot-command; boundary=---------------------------58123037437716747452831683647
// Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;

// -----------------------------58123037437716747452831683647
// Content-Type: message/coffeepot

// start


// HTCPCP/1.0 406 Not Acceptable
// Date: Fri, 04 Jun 2021 15:22:53 GMT
// Server: Coffee Pot
// Content-Type: text/html; charset=utf-8

// HTCPCP/1.0 418 I'm a teapot
// Date: Fri, 04 Jun 2021 15:22:53 GMT
// Server: Tea Pot
// Content-Type: text/html; charset=utf-8

// HTCPCP/1.0 200 OK
// Date: Fri, 04 Jun 2021 15:22:53 GMT
// Server: Coffee Pot
// Content-Type: text/html; charset=utf-8

// <html> Brewing </html>
