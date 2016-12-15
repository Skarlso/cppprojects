#include <iostream>
#include <vector>

using std::vector;

typedef struct disc {
    int initialPosition;
    int maxPosition;
    int delay;
    bool zeroAtTime(int t) {
        return ((initialPosition + delay + t) % maxPosition) == 0;
    };
} disc;


int main() {
    vector<disc> discs = {
        {5, 17, 1},
        {8, 19, 2},
        {1, 7, 3},
        {7, 13, 4},
        {1, 5, 5},
        {0, 3, 6},
        {0, 11, 7}
    };
    int planetaryAlignmentLoops = 0;
    for (int t = 0; ++t;) {
        if (std::all_of(discs.cbegin(), discs.cend(), [t](disc d) { return d.zeroAtTime(t); })) {
            planetaryAlignmentLoops = t;
            break;
        }
    }

    std::cout << planetaryAlignmentLoops << '\n';
}
