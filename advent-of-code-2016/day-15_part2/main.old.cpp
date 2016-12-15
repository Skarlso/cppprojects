#include <iostream>
#include <vector>

using std::vector;

typedef struct disc {
    int initialPosition;
    int maxPosition;
} disc;


int main() {
    vector<disc> discs = {
        {5, 17},
        {8, 19},
        {1, 7},
        {7, 13},
        {1, 5},
        {0, 3},
        {0, 11}
    };
    int planetaryAlignmentLoops = 0;
    int planetaryAlignment = true;
    for (int t = 0; ++t;) {
        int delay = 1;
        for (auto it = discs.begin(); it != discs.end(); ++it) {
            int state = (it->initialPosition + delay + t) % it->maxPosition;
            if (state != 0) {
                planetaryAlignment = false;
            }
            delay++;
        }
        if (planetaryAlignment) {
            planetaryAlignmentLoops = t;
            break;
        } 
        planetaryAlignment = true;
    }

    std::cout << planetaryAlignmentLoops << '\n';
}
