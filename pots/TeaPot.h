#ifndef HTCPCP_TEAPOT_H
#define HTCPCP_TEAPOT_H

#include "Pot.h"

class TeaPot : public Pot {
public:
    TeaPot() {};

    void addMilk(int type) override;

    void addSweetener(int type) override;

    void addSyrup(int type) override;

    void addSpice(int type) override;

    void addAlcohol(int type) override;

    virtual std::string getServerName();
};

#endif