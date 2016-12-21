#include <string>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <vector>

using std::string;
using std::vector;

void swapByIndex(string& s, int from, int to) {
    std::swap(s[from], s[to]);

}

void swapByCharacter(string& s, char a, char b) {
    int a2 = s.find(a);
    int b2 = s.find(b);
    std::swap(s[a2], s[b2]);
}

void reverseString(string& s, int from, int until) {
    std::reverse(s.begin()+from, s.begin()+until);
}

void rotateLeft(string& s, int by) {
    std::rotate(s.begin(), s.begin()+by, s.end());
}

void rotateRight(string& s, int by) {
    std::rotate(s.rbegin(), s.rbegin()+by, s.rend());
}

void move(string& s, int x, int y) {
    char a = s[x];
    s.erase(x, x);
    s.insert(s.begin() + y, a);
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    string str = "abcdefgh";
    string s;
    while (std::getline(file, s)) {
        boost::trim(s);
        vector<string> split;
        boost::split(split, s, boost::is_any_of(" "));

        if (split[0] == "rotate") {
            if (split[1] == "right") {
                int by;
                std::sscanf(s.c_str(), "rotate right %d steps", &by);
                rotateRight(str, by);
            } else if (split[1] == "left") {
                int by;
                std::sscanf(s.c_str(), "rotate left %d steps", &by);
                rotateLeft(str, by);
            }
        } else if (split[0] == "swap") {
            if (split[1] == "position") {
                int x, y;
                std::sscanf(s.c_str(), "swap position %d with position %d", &x, &y);
                swapByIndex(str, x, y);
            } else if (split[1] == "letter") {
                char a, b;
                std::sscanf(s.c_str(), "swap letter %s with letter %s", &a, &b);
                swapByCharacter(str, a, b);
            }
        } else if (split[0] == "reverse") {
            int x, y;
            std::sscanf(s.c_str(), "reverse positions %d through %d", &x, &y);
            reverseString(str, x, y);
        } else if (split[0] == "move") {
            int x, y;
            std::sscanf(s.c_str(), "move position %d to position %d", &x, &y);
            move(str, x, y);
        }
    }
    printf("Password: %s\n", str.c_str());
    return 0;
}
