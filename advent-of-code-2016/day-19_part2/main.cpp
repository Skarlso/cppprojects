#include <vector>
#include <iostream>
#include <math.h>

using std::vector;
using std::cout;

//const int ELFS = 3001330;
const int ELFS = 5;

int getTheElfWithTheNextPresent(bool circle[ELFS], int from) {
    int elf = -1;
    int i = (from + int(floor(ELFS/2))) % ELFS;
    for (;i != from;) {
        if (circle[i]) {
            elf = i;
            break;
        }

        i = (i + 1) % ELFS;
    }

    return elf;
}

int main() {
    bool presentCicrle[ELFS];

    for (int i = 0; i < ELFS; ++i) {
        presentCicrle[i] = true;
    }
    cout << "Present size: " << ELFS << '\n';
    bool moreThanOneElfHasPresents = true;
    int theElfWithTheMostPresent = 0;
    while(moreThanOneElfHasPresents) {
        for (int i = 0; i < ELFS; ++i) {
            if (!presentCicrle[i]) {
                continue;
            }
            int nextElf = getTheElfWithTheNextPresent(presentCicrle, i);
            if (nextElf == -1) {
                theElfWithTheMostPresent = i;
                moreThanOneElfHasPresents = false;
                break;
            }
            presentCicrle[i] = true;
            presentCicrle[nextElf] = false;
        }
    }
    //for (int i = 0; i < presentCicrle.size(); ++i) {
    //    cout << "I: " << presentCicrle[i] << '\n';
    //}
    cout << "The elf with the most present: " << theElfWithTheMostPresent+1 << '\n';
}
