#ifndef HTCPCP_TEAPOT_H
#define HTCPCP_TEAPOT_H

#include "Pot.h"

class TeaPot : public Pot {
    public:
        TeaPot() {};
        void addMilk(int type);
        void addSweetener(int type);
        void addSyrup(int type);
        void addSpice(int type);
        void addAlcohol(int type);
};

#endif