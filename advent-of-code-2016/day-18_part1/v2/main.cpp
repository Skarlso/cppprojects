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
    {0, 0, 1},
    {1, 0, 0},
    {0, 1, 1},
    {1, 1, 0}
};

vector<int> getNextRow(vector<int> current_row) {
    vector<int> next_row;
    for (int i = 0; i < current_row.size(); ++i) {
        vector<int> to_check;
        if (i == 0) {
            to_check.push_back(1);
            to_check.push_back(current_row.at(i));
            to_check.push_back(current_row.at(i+1));
        } else if (i + 1 == current_row.size()) {
            to_check.push_back(current_row.at(i-1));
            to_check.push_back(current_row.at(i));
            to_check.push_back(1);
        } else {
            to_check.push_back(current_row.at(i-1));
            to_check.push_back(current_row.at(i));
            to_check.push_back(current_row.at(i+1));
        }
        bool t = false;
        for (auto it = traps.begin(); it != traps.end(); ++it) {
            if (to_check == *it) {
                t = true;
            }
        }
        t ? next_row.push_back(0) : next_row.push_back(1);
    }
    return next_row;
}

int main() {
    vector<vector<int>> alltraps;
    vector<int> row;
    for (auto it = begin.begin(); it != begin.end(); ++it) {
        if (*it == '.') {
            row.push_back(1);
        } else {
            row.push_back(0);
        }
    }
    alltraps.push_back(row);
    std::cout << "Starting to Generate field." << '\n';
    for(int i = 0; i < BOUNDRY_P2 - 1; ++i) {
        alltraps.push_back(getNextRow(alltraps.at(i)));
    }
    std::cout << "Generated field." << '\n';
    int safe = 0;
    for(auto it = alltraps.begin(); it != alltraps.end(); ++it) {
        for(auto s = it->begin(); s != it->end(); ++s) {
            safe += *s;
        }
    }
    std::cout << "Safe places: " << safe << '\n';
    return 0;
}
