#ifndef HTCPCP_DECAFPOT_H
#define HTCPCP_DECAFPOT_H

#include "CoffeePot.h"

class DecafPot : public CoffeePot {
public:
    /**
     * the default constructor
     */
    DecafPot() {};

    /**
     * get the name of this pot
     * @return this pot's name
     */
    virtual std::string getServerName() override;
};

#endif