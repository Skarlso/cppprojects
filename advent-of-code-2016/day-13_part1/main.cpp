#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <array>

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<vector<int>> maze;
//const int DESIGNER_INPUT = 1352;
//const int TARGET_X = 31;
//const int TARGET_Y = 39;
vector<std::array<int, 2>> pathsAlreadyWalked;
const int DESIGNER_INPUT = 10;
const int TARGET_X = 7;
const int TARGET_Y = 4;

void extendMaze() {
    // Extend maze will also calculate the maze's walls and open spaces.
}

int popcount(int x, int y) {
    int decimal = ((x*x) + (3*x) + (2*x*y) + (y) + (y*y)) + DESIGNER_INPUT;
    std::bitset<sizeof(int) * CHAR_BIT> b(decimal);
    return (b.count() & 1) == 1;
}

void constructMaze() {
    for (int y = 0; y < TARGET_Y + 10; ++y) {
        vector<int> row;
        for (int x = 0; x < TARGET_X + 10; ++x) {
            row.push_back(popcount(x, y));
        }
        maze.push_back(row);
    }
}

void displayMaze() {
    for(auto row = maze.begin(); row != maze.end(); ++row) {
        for(auto col = row->begin(); col != row->end(); ++col) {
            *col ? cout << "#" : cout << ".";
        }
        cout << endl;
    }
}

int calculatePaths() {
    return 0;
}

int main() {
    // construct initial maze
    // expand it if necessary
    constructMaze();
    displayMaze();
    int x = 1, y = 1;
    while (x != TARGET_X && y != TARGET_Y) {
        x++;
        y++; 
    }
           
    return 0;
}
