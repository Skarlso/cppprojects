#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>

const int WIDE = 50;
const int TALL = 6;
std::vector<std::vector<int>> display(TALL, std::vector<int>(WIDE, 0));

void rectAxB(int x, int y) {
    for (auto row = display.begin(); row != display.begin() + y; row++) {
        std::replace(row->begin(), row->begin()+x, 0, 1);
    }
}

void rotateRow(int row, int by) {
    std::rotate(display[row].rbegin(), display[row].rbegin()+by, display[row].rend());
}

void rotateColumn(int col, int by) {
    std::vector<int> newCol (TALL, 0);
    for (int i = 0; i < TALL; ++i) {
        int shiftedI = (i + by) % TALL;
        newCol[shiftedI] = display[i][col];
    }
    for (int i = 0; i < TALL; ++i)
        display[i][col] = newCol[i];
}

void displayDisplay() {
    for (auto row = display.begin(); row != display.end(); row++) {
        for (auto col = row->begin(); col != row->end(); col++) {
            *col ? std::cout << "#" : std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str;
    std::stringstream ss;
    while (std::getline(file, str)) {
        boost::trim(str);
        std::vector<std::string> instructions;
        boost::split(instructions, str, boost::is_any_of(" "));
        std::string action = instructions[0];
        if (action == "rect") {
            int x, y;
            char c_str[1024];
            strcpy(c_str, instructions[1].c_str());
            std::sscanf (c_str, "%dx%d", &x, &y);
            rectAxB(x, y);
        } else if (action == "rotate") {
            std::string rc = instructions[1];
            if (rc == "row") {
                int row, by;
                char c_str[1024];
                strcpy(c_str, str.c_str());
                std::sscanf (c_str, "rotate row y=%d by %d", &row, &by);
                rotateRow(row, by);
            } else if (rc == "column") {
                int col, by;
                char c_str[1024];
                strcpy(c_str, str.c_str());
                std::sscanf (c_str, "rotate column x=%d by %d", &col, &by);
                rotateColumn(col, by);
            }
        }
    }
    std::cout << "Lit count: cat <<< | grep -o '#' | wc -c" << '\n';
    displayDisplay();
}
