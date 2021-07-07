#ifndef HTCPCP_COFFEEPOT_H
#define HTCPCP_COFFEEPOT_H

#include "Pot.h"

class CoffeePot : public Pot {
public:
    CoffeePot() {};

    virtual std::string getServerName();
};

#endif