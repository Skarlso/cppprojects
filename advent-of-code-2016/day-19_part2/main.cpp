#include <vector>
#include <iostream>
#include <math.h>
#include <stdio.h>

using std::vector;
using std::cout;

typedef struct elf {
    int index;
    bool present;
} elf;

const int ELFS = 3001330;
// const int ELFS = 5;

int main() {
    vector<elf> presentCircle;

    for (int i = 0; i < ELFS; ++i) {
        presentCircle.push_back({i+1, true});
    }
    int i = 0;
    while(presentCircle.size() > 1) {
        int nextElf = (i + int(floor(presentCircle.size()/2))) % presentCircle.size();
        //printf("Next Elf index is: %d\n", nextElf);
        presentCircle.erase(presentCircle.begin()+nextElf);

        if (nextElf < i) {
            i = i % presentCircle.size();
        } else {
            i = (i + 1) % presentCircle.size();
        }
        if (presentCircle.size() % 1000 == 0) {
            cout << "Vector size: " << presentCircle.size() << '\n'; 
        }
        //printf("Next index: %d\n", i);
    }
    for (int i = 0; i < presentCircle.size(); ++i) {
        cout << "I: " << presentCircle[i].index << '\n';
    }
    cout << "===============" << '\n';
}
