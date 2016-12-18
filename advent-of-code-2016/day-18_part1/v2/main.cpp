#include <iostream>
#include <string>
#include <vector>
#define BOUNDRY 40
#define BOUNDRY_P2 400000

using std::string;
using std::vector;

// TODO: Consider changing this into an int 0-1 -s and doing binary arithmetic on them.
const string begin = ".^^^.^.^^^.^.......^^.^^^^.^^^^..^^^^^.^.^^^..^^.^.^^..^.^..^^...^.^^.^^^...^^.^.^^^..^^^^.....^....";
const string test = ".^^.^.^^^^";
vector<vector<int>> traps = {
    {{1}, {1}, {0}},
    {{0}, {1}, {1}},
    {{1}, {0}, {0}},
    {{0}, {0}, {1}}
};

vector<int> getNextRow(vector<int> current_row) {
    vector<int> next_row;
    for (int i = 0; i < current_row.length(); ++i) {
        string to_check = "";
        if (i == 0) {
            to_check += '.';
            to_check += current_row.at(i);
            to_check += current_row.at(i+1);
        } else if (i + 1 == current_row.length()) {
            to_check += current_row.at(i-1);
            to_check += current_row.at(i);
            to_check += '.';
        } else {
            to_check += current_row.at(i-1);
            to_check += current_row.at(i);
            to_check += current_row.at(i+1);
        }
        if (std::find(traps.begin(), traps.end(), to_check) == traps.end()) {
            next_row += '.';
        } else {
            next_row += '^';
        }
    }
    return next_row;
}

int main() {
    vector<vector<int>> traps;
    for (auto it = begin.begin(); it != begin.end(); ++it) {
        vector<int> row;
        if (*it == '.') {
            row.push_back(0);
        } else {
            row.push_back(1);
        }
    }
    traps.push_back(begin);
    for(int i = 0; i < BOUNDRY_P2 - 1; ++i) {
        traps.push_back(getNextRow(traps.at(i)));
    }
    int safe = 0;
    for(auto it = traps.begin(); it != traps.end(); ++it) {
        for(auto s = it->begin(); s != it->end(); ++s) {
            if (*s == '.') safe++;
        }
    }
    std::cout << "Safe places: " << safe << '\n';
    return 0;
}
