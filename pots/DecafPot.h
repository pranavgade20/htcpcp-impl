#ifndef HTCPCP_DECAFPOT_H
#define HTCPCP_DECAFPOT_H

#include "CoffeePot.h"

class DecafPot : public CoffeePot {
public:
    DecafPot() {};

    virtual std::string getServerName() override;
};

#endif