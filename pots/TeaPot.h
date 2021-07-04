#include "Pot.h"

class TeaPot: public Pot {
    public:
        TeaPot();
        void addMilk(int type);
        void addSweetener(int type);
        void addSyrup(int type);
        void addSpice(int type);
        void addAlcohol(int type);
};