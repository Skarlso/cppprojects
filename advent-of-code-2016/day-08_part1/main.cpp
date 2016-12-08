#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdio.h>

const int WIDE = 50;
const int TALL = 6;
std::vector<std::vector<int>> display;

void rectAxB(int x, int y) {
    for (int i = 0; i < y; ++i)
        for (int j = 0; j < x; ++j)
            display[i][j] = 1;
}

std::vector<int> createRowColumn(int l) {
    std::vector<int> newRow;
    for (int i = 0; i < l; ++i)
        newRow.push_back(0);
    return newRow;
}

void rotateRow(int row, int by) {
    std::vector<int> newRow = createRowColumn(WIDE);
    for (int i = 0; i < WIDE; ++i) {
        int shiftedI = (i + by) % WIDE;
        newRow[shiftedI] = display[row][i];
    }
    display[row] = newRow;
}

void rotateColumn(int col, int by) {
    std::vector<int> newCol = createRowColumn(TALL);
    for (int i = 0; i < TALL; ++i) {
        int shiftedI = (i + by) % TALL;
        newCol[shiftedI] = display[i][col];
    }
    for (int i = 0; i < TALL; ++i)
        display[i][col] = newCol[i];
}

void fillWithZeros() {
    for (int i = 0; i < TALL; ++i) {
        std::vector<int> row;
        for (int j = 0; j < WIDE; ++j) {
            row.push_back(0);
        }
        display.push_back(row);
    }
}

void displayDisplay() {
    for (int i = 0; i < TALL; ++i) {
        for (int j = 0; j < WIDE; ++j) {
            if (display[i][j] == 1) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int countLit() {
    int count = 0;
    for (int i = 0; i < TALL; ++i)
        for (int j = 0; j < WIDE; ++j)
            if (display[i][j] == 1) {
                count++;
            }
    return count;
}

int main(int argc, char* argv[]) {
    fillWithZeros();
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
    displayDisplay();
}
