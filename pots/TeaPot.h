#ifndef HTCPCP_TEAPOT_H
#define HTCPCP_TEAPOT_H

#include "Pot.h"

class TeaPot : public Pot {
protected:
    /**
    * throws error 418
    */
    void addMilk(int type) override;
    /**
    * throws error 418
    */
    void addSweetener(int type) override;
    /**
    * throws error 418
    */
    void addSyrup(int type) override;
    /**
    * throws error 418
    */
    void addSpice(int type) override;
    /**
    * throws error 418
    */
    void addAlcohol(int type) override;
public:
    TeaPot() {};
    virtual std::string getServerName();
};

#endif
