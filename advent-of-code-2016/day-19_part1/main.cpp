#include <vector>
#include <iostream>

using std::vector;
using std::cout;

const int ELFS = 3001330;

int getTheElfWithTheNextPresent(vector<int> circle, int from) {
    int elf = -1;
    for (int i = from + 1; i != from;) {
        if (circle[i] > 0) {
            elf = i;
        }

        i = (i + 1) % circle.size();
    }

    return elf;
}

int main() {
    vector<int> presentCicrle;

    for (int i = 0; i < ELFS; ++i) {
        presentCicrle.push_back(1);
    }
    cout << "Present size: " << presentCicrle.size() << '\n';
    bool moreThanOneElfHasPresents = true;
    int theElfWithTheMostPresent = 0;
    while(moreThanOneElfHasPresents) {
        for (int i = 0; i < ELFS; ++i) {
            if (presentCicrle[i] == 0) {
                continue;
            }
            
            int nextElf = getTheElfWithTheNextPresent(presentCicrle, i);
            if (nextElf == -1) {
                theElfWithTheMostPresent = i;
                moreThanOneElfHasPresents = false;
                break;    
            }
            presentCicrle[i] += presentCicrle[nextElf];
            presentCicrle[nextElf] = 0;
        }
    }
    //for (int i = 0; i < presentCicrle.size(); ++i) {
    //    cout << "I: " << presentCicrle[i] << '\n';
    //}
    cout << "The elf with the most present: " << theElfWithTheMostPresent << '\n';
}
