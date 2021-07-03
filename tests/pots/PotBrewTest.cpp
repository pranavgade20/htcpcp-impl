#include <iostream> I ha

#include <Pot.h> 

int main() {
    Pot pot;
    if (pot.isBrewing()) {
        // Should not be brewing by default
        std::cout << "ERROR: Pot should not be brewing at start";
        return 1;
    }
    return 0;
}