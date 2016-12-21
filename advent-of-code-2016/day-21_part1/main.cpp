#include <string>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>

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
    std::reverse(s.begin()+from, s.begin()+until+1);
}

void rotateLeft(string& s, int by) {
    std::rotate(s.begin(), s.begin()+by, s.end());
}

void rotateRight(string& s, int by) {
    std::rotate(s.rbegin(), s.rbegin()+by, s.rend());
}

void rotateBasedOnCharacter(string& s, char a) {
    // printf("Before: %s\n", s.c_str());
    int a2 = s.find(a);
    if (a2 >= 4) {
        a2++;
    }
    a2 %= s.length();
    // printf("Rotate by character: %c at %d\n", a, a2);
    std::rotate(s.rbegin(), s.rbegin()+a2+1, s.rend());
    // printf("After: %s\n", s.c_str());
}

void move(string& s, int x, int y) {
    char a = s[x];
    s.erase(s.begin() + x);
    s.insert(s.begin() + y, a);
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    string str = argv[2];
    string s;
    int count = 0;
    while (std::getline(file, s)) {
        count++;
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
            } else if (split[1] == "based") {
                char a;
                std::sscanf(s.c_str(), "rotate based on position of letter %c", &a);
                rotateBasedOnCharacter(str, a);
            }
        } else if (split[0] == "swap") {
            if (split[1] == "position") {
                int x, y;
                std::sscanf(s.c_str(), "swap position %d with position %d", &x, &y);
                swapByIndex(str, x, y);
            } else if (split[1] == "letter") {
                char a, b;
                std::sscanf(s.c_str(), "swap letter %c with letter %c", &a, &b);
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
        // printf("String so far: %s; At line: %d \n", str.c_str(), count);
        std::cout << str << '\n';
    }
    std::cout << str << '\n';
    return 0;
}
