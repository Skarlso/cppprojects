#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

const int goalx = 3;
const int goaly = 3;

string paths = "";

bool isClear(char maze[4][4], int x, int y) {
    return maze[y][x] == '*';
}

bool solveMaze(char maze[4][4], int x, int y) {
    maze[y][x] = 'S';
    if (x == goalx && y == goaly) {
        return true;
    }
    
    if (x > 0 && maze[y][x - 1] == '*' && solveMaze(maze, x - 1, y)) {
        paths += 'L';
        return true;
    }
    if (x < 4 && maze[y][x + 1] == '*' && solveMaze(maze, x + 1, y)) {
        paths += 'R';
        return true;
    }
    if (y > 0 && maze[y - 1][x] == '*' && solveMaze(maze, x, y - 1)) {
        paths += 'U';
        return true;
    }
    if (y < 4 && maze[y + 1][x] == '*' && solveMaze(maze, x, y + 1)) {
        paths += 'D';
        return true;
    }

    maze[y][x] = '*';
    return false;
}

int main() {
    char maze[4][4] = {
        {'*', '.', '.' ,'.'},
        {'*', '*', '.', '.'},
        {'*', '*', '.', '.'},
        {'*', '*', '*', '*'}
    };
    solveMaze(maze, 0, 0);
    std::reverse(paths.begin(), paths.end());
    printf("Path: %s\n", paths.c_str());
}
