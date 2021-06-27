#include <iostream>

#include <Pot.h>

int main() {
    Pot pot;
    if (pot.removeCup() != nullptr) {
        // Should not have a cup by default
        std::cout << "ERROR: Pot should not have a cup at start";
        return 1;
    }
    return 0;
}