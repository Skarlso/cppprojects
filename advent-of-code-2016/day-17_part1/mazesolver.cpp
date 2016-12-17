#include <stdio.h>
const int goalx = 3;
const int goaly = 3;

void displayMaze(char maze[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

bool solveMaze(char maze[4][4], int x, int y) {
    maze[y][x] = 'x';

    if (x == goalx && y == goaly) {
        return true;
    }
    
    if (x > 0 && maze[y][x - 1] == '*' && solveMaze(maze, x - 1, y)) {
        return true;
    }
    if (x < 4 && maze[y][x + 1] == '*' && solveMaze(maze, x + 1, y)) {
        return true;
    }
    if (y > 0 && maze[y - 1][x] == '*' && solveMaze(maze, x, y - 1)) {
        return true;
    }
    if (y < 4 && maze[y + 1][x] == '*' && solveMaze(maze, x, y + 1)) {
        return true;
    }
    maze[y][x] = '*';

    return false;
}

int main() {
    char maze[4][4] = {
        {'*', '.', '.' ,'.'},
        {'*', '.', '.', '.'},
        {'*', '.', '.', '.'},
        {'*', '*', '*', '*'}
    };

    if (solveMaze(maze, 0, 0)) {
        printf("Maze, solved.\n");
        displayMaze(maze);
    } else {
        printf("Maze unsolvable.\n");
    }
}
