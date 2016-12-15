#include <iostream>

typedef struct disc {
    int initialPosition;
    int maxPosition;
} disc;


int main() {
    disc d1 = {5, 17};
    disc d2 = {8, 19};
    disc d3 = {1, 7};
    disc d4 = {7, 13};
    disc d5 = {1, 5};
    disc d6 = {0, 3};
    disc d7 = {0, 11};
    int planetaryAlignmentLoops = 0;
    for (int t = 0; ++t;) {
        int state = 0;
        state += (d1.initialPosition + t + 1) % d1.maxPosition;
        state += (d2.initialPosition + t + 2) % d2.maxPosition;
        state += (d3.initialPosition + t + 3) % d3.maxPosition;
        state += (d4.initialPosition + t + 4) % d4.maxPosition;
        state += (d5.initialPosition + t + 5) % d5.maxPosition;
        state += (d6.initialPosition + t + 6) % d6.maxPosition;
        state += (d7.initialPosition + t + 7) % d7.maxPosition;
        if (state == 0) {
            planetaryAlignmentLoops = t;
            break;
        } 
    }
    std::cout << planetaryAlignmentLoops << '\n';
}
