#include <string>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

typedef struct command {
    string action;
    string subcommand;
    string raw;
} command;

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
    int a2 = s.find(a);
    if (a2 >= 4) {
        a2++;
    }
    a2 %= s.length();
    std::rotate(s.rbegin(), s.rbegin()+a2+1, s.rend());
}

void move(string& s, int x, int y) {
    char a = s[x];
    s.erase(s.begin() + x);
    s.insert(s.begin() + y, a);
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    string start = argv[2];
    string goal = argv[3];
    string s;
    int count = 0;
    vector<command> instructions;
    while (std::getline(file, s)) {
        count++;
        boost::trim(s);
        vector<string> split;
        boost::split(split, s, boost::is_any_of(" "));
        instructions.push_back({split[0], split[1], s});
    }
    string origin = start;
    do {
        string str = origin;
        for (auto it = instructions.begin(); it != instructions.end(); ++it) {
            if (it->action == "rotate") {
                if (it->subcommand == "right") {
                    int by;
                    std::sscanf(it->raw.c_str(), "rotate right %d steps", &by);
                    rotateRight(str, by);
                } else if (it->subcommand == "left") {
                    int by;
                    std::sscanf(it->raw.c_str(), "rotate left %d steps", &by);
                    rotateLeft(str, by);
                } else if (it->subcommand == "based") {
                    char a;
                    std::sscanf(it->raw.c_str(), "rotate based on position of letter %c", &a);
                    rotateBasedOnCharacter(str, a);
                }
            } else if (it->action == "swap") {
                if (it->subcommand == "position") {
                    int x, y;
                    std::sscanf(it->raw.c_str(), "swap position %d with position %d", &x, &y);
                    swapByIndex(str, x, y);
                } else if (it->subcommand == "letter") {
                    char a, b;
                    std::sscanf(it->raw.c_str(), "swap letter %c with letter %c", &a, &b);
                    swapByCharacter(str, a, b);
                }
            } else if (it->action == "reverse") {
                int x, y;
                std::sscanf(it->raw.c_str(), "reverse positions %d through %d", &x, &y);
                reverseString(str, x, y);
            } else if (it->action == "move") {
                int x, y;
                std::sscanf(it->raw.c_str(), "move position %d to position %d", &x, &y);
                move(str, x, y);
            }
        }
        if (str == goal) {
            std::cout << "Found: " << origin << '\n';
            break;
        }
    } while (std::next_permutation(origin.begin(), origin.end()));
    return 0;
}
