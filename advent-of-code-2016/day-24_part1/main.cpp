#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <stack>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;

typedef struct coordinates {
    int x, y;
    string path;
    string found;
    bool operator<(coordinates other) const {
        return x < other.x && y < other.y;
    }

    bool operator==(coordinates other) const {
        return x == other.x && y == other.y;
    }
} coordinates;

vector<coordinates> alreadyVisited;
bool visited(coordinates c) {
    return std::find(alreadyVisited.begin(), alreadyVisited.end(), c) != alreadyVisited.end();
}

// Gather all valid moves around a coordinate and add them to a vector.
vector<coordinates> allMoves(vector<vector<char>> maze, int x, int y, string paths, string founds) {
    vector<coordinates> ret;
    if (x > 0 && maze[y][x - 1] != '#' && !visited({x - 1, y, "", ""})) {
        ret.push_back({x - 1, y, paths + 'L', founds});
        alreadyVisited.push_back({x - 1, y, "", ""});
    }
    if (x < maze[y].size() && maze[y][x + 1] != '#' && !visited({x + 1, y, "", ""})) {
        ret.push_back({x + 1, y, paths + 'R', founds});
        alreadyVisited.push_back({x + 1, y, "", ""});
    }
    if (y > 0 && maze[y - 1][x] != '#' && !visited({x, y - 1, "", ""})) {
        ret.push_back({x, y - 1, paths + 'U', founds});
        alreadyVisited.push_back({x, y - 1, "", ""});
    }
    if (y < maze.size() && maze[y + 1][x] != '#' && !visited({x, y + 1, "", ""})) {
        ret.push_back({x, y + 1, paths + 'D', founds});
        alreadyVisited.push_back({x, y + 1, "", ""});
    }
    return ret;
}

int main(int argc, char* argv[]) {

    std::ifstream file(argv[1]);
    string s;
    vector<vector<char>> maze;
    int startx, starty = 0;
    while (std::getline(file, s)) {
        boost::trim(s);
        maze.push_back(vector<char>(s.begin(), s.end()));
    }
    for (int y = 0; y < maze.size(); ++y)
    {
        for (int x = 0; x < maze[y].size(); ++x)
        {
            if (maze[y][x] == '0') {
                startx = x;
                starty = y;
                break;
            }
        }
    }
    string goal = "1234567";
    string found;
    vector<string> validPaths;
    stack<coordinates> allPaths;
    allPaths.push({startx, starty, "", ""});
    while(!allPaths.empty()) {
        coordinates currentPath = allPaths.top();
        // int n;
        // std::cin >> n;
        allPaths.pop();
        // currentPath.found.erase(std::remove(currentPath.found.begin(), currentPath.found.end(), '.'), currentPath.found.end());
        // int n;
        // std::cin >> n;
        // printf("y: %d x: %d\n", currentPath.y, currentPath.x);
        char c = maze[currentPath.y][currentPath.x];
        // std::cout << "Still Good" << "\n";
        if (std::isdigit(c) && found.find(c) == std::string::npos) {
            if (c != '0') {
                found += c;
                stack<coordinates> empty;
                std::swap(allPaths, empty);
                validPaths.push_back(currentPath.path);
                allPaths.push({currentPath.x, currentPath.y, "", ""});
                currentPath.path = "";
                currentPath.found = "";
                alreadyVisited.clear();
            }
        }

        printf("Current Found: %s\n", found.c_str());
        if (std::is_permutation(goal.begin(), goal.end(), found.begin())) {
            break;
        }
        vector<coordinates> directions = allMoves(maze, currentPath.x, currentPath.y, currentPath.path, currentPath.found);
        for(auto it = directions.begin(); it != directions.end(); ++it) {
            allPaths.push(*it);
        }
    }
    // std::sort(validPaths.begin(), validPaths.end(), [](string s1, string s2){return s1.length() < s2.length();});
    // cout << "Shortest Path Length: " << validPaths.front() << endl;
    string allPath = "";
    for (auto it = validPaths.begin(); it != validPaths.end(); ++it)
    {
        allPath += *it;
    }
    std::cout << allPath << '\n';

    return 0;
}
