#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
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
map <string,string> holdermap;


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
    holdermap[type]=val;
    it++;
}
map<string,int> parsedmap;

if(holdermap["milk-type"]=="CREAM"){
    parsedmap["milk-type"]=MilkType::CREAM;
}
else if(holdermap["milk-type"]=="HALF_AND_HALF"){
    parsedmap["milk-type"]=MilkType::HALF_AND_HALF;
}
else if(holdermap["milk-type"]=="WHOLE_MILK"){
    parsedmap["milk-type"]=MilkType::WHOLE_MILK;
}
else if(holdermap["milk-type"]=="PART_SKIM"){
    parsedmap["milk-type"]=MilkType::PART_SKIM;
}
else if(holdermap["milk-type"]=="NON_DAIRY"){
    parsedmap["milk-type"]=MilkType::NON_DAIRY;
}
if(holdermap["spice-type"]=="CINNAMON"){
    parsedmap["spice-type"]=SpiceType::CINNAMON;
}
else if(holdermap["spice-type"]=="NUTMEG"){
    parsedmap["spice-type"]=SpiceType::NUTMEG;
}
else if(holdermap["spice-type"]=="CARDAMOM"){
    parsedmap["spice-type"]=SpiceType::CARDAMOM;
}
else if(holdermap["spice-type"]=="CLOVE"){
    parsedmap["spice-type"]=SpiceType::CLOVE;
}
if(holdermap["sweetener-type"]=="SUGAR"){
    parsedmap["sweetener-type"]=MilkType::SUGAR;
}
else if(holdermap["sweetener-type"]=="STEVIA"){
    parsedmap["sweetener-type"]=MilkType::STEVIA;
}
else if(holdermap["sweetener-type"]=="HONEY"){
    parsedmap["sweetener-type"]=MilkType::HONEY;
}
else if(holdermap["sweetener-type"]=="MAPLE_SYRUP"){
    parsedmap["sweetener-type"]=MilkType::MAPLE_SYRUP;
}
else if(holdermap["sweetener-type"]=="AGAVE"){
    parsedmap["sweetener-type"]=MilkType::AGAVE;
}
if(holdermap["syrup-type"]=="VANILLA"){
    parsedmap["syrup-type"]=MilkType::VANILLA;
}
else if(holdermap["syrup-type"]=="ALMOND"){
    parsedmap["syrup-type"]=MilkType::ALMOND;
}
else if(holdermap["syrup-type"]=="RASPBERRY"){
    parsedmap["syrup-type"]=MilkType::RASPBERRY;
}
else if(holdermap["syrup-type"]=="CHOCOLATE"){
    parsedmap["syrup-type"]=MilkType::CHOCOLATE;
}
if(holdermap["alcohol-type"]=="WHISKY"){
    parsedmap["alcohol-type"]=MilkType::WHISKY;
}
else if(holdermap["alcohol-type"]=="RUM"){
    parsedmap["alcohol-type"]=MilkType::RUM;
}
else if(holdermap["alcohol-type"]=="KAHLUA"){
    parsedmap["alcohol-type"]=MilkType::KAHLUA;
}
else if(holdermap["alcohol-type"]=="AQUAVIT"){
    parsedmap["alcohol-type"]=MilkType::AQUAVIT;
}
}