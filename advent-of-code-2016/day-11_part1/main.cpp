#include <iostream>
#include <vector>
#include <string>

typedef struct component {
    int id;
    std::string name;
} chip, generator;

bool checkIfCombinationIsValid(std::vector<component> fl) {
    bool valid = false;
    // Cycle through and check who is with whom according to the rules.
    // If a chips own generator is not on the floor but the chip is, AND there are other generators on the floor without
    // their chips.  -> fail.
    for (std::vector<component>::iterator it = fl.begin(); it != fl.end(); ++it) {
         
    }
    return valid;
}

void makeMove() {

}

int main() {
    std::vector<chip> chips {
        {0, "polonium"},
        {1, "thulium"},
        {2, "promethium"},
        {3, "ruthenium"},
        {4, "cobalt"}
    };
    std::vector<generator> generators {
        {0, "polonium"},
        {1, "thulium"},
        {2, "promethium"},
        {3, "ruthenium"},
        {4, "cobalt"}
    };
    std::vector<std::vector<component>> floors = {
        {generators[0], generators[1], generators[2], generators[3], generators[4], chips[1], chips[3], chips[4]},
        {chips[0], chips[2]},
        {},
        {}
    };
    
    // Gool is, everything is on the last row in floors
    

    return 0;  
}
