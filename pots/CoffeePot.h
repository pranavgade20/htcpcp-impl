#ifndef HTCPCP_COFFEEPOT_H
#define HTCPCP_COFFEEPOT_H

#include "Pot.h"

class CoffeePot : public Pot {
public:
    /**
     * the default constructor
     */
    CoffeePot() {};

    /**
     * get the name of this pot
     * @return this pot's name
     */
    virtual std::string getServerName();
};

#endif