#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <stack>
#include <map>
#include <fstream>

using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::string;
using std::stack;
using std::map;

typedef struct loc {
    int x, y;
} loc;

typedef struct node {
    loc l;
    int size, used, avail, usage;
    string name;
    node* left;
    node* right;
    node* up;
    node* down;

    void move (node src, node dst) {

    }

    bool operator==(node other) const {
        return name != other.name;
    }
} node;

// // Gather all valid moves around a coordinate and add them to a vector.
// vector<node> allMoves(int x, int y, string paths) {
//     vector<coordinates> ret;
//     if (x > 0 && openedDoors.find(md5[2]) != string::npos) {
//         ret.push_back({x - 1, y, paths + 'L'});
//     }
//     if (x < 3 && openedDoors.find(md5[3]) != string::npos) {
//         ret.push_back({x + 1, y, paths + 'R'});
//     }
//     if (y > 0 && openedDoors.find(md5[0]) != string::npos) {
//         ret.push_back({x, y - 1, paths + 'U'});
//     }
//     if (y < 3 && openedDoors.find(md5[1]) != string::npos) {
//         ret.push_back({x, y + 1, paths + 'D'});
//     }
//     for(auto it = ret.begin(); it != ret.end(); ++it) {
//         printf("x: %d, y: %d, path: %s", it->x, it->y, it->path.c_str());
//     }
//     int n;
//     std::cin >> n;
//     return ret;
// }

int main(int argc, char* argv[]) {
    // gather all the valid paths here which lead to the goal coordinate x, y.
    int viablePairCount = 0;

    std::ifstream file(argv[1]);
    vector<node> nodes;
    string s;
    while (std::getline(file, s)) {
        int x, y;
        int size, used, avail, usage;
        sscanf(s.c_str(), "/dev/grid/node-x%d-y%d     %dT   %dT    %dT   %d", &x, &y, &size, &used, &avail, &usage);
        node n = {{x, y}, size, used, avail, usage, s, nullptr, nullptr, nullptr, nullptr};
        nodes.push_back(n);
    }


    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = 0; j < nodes.size(); ++j) {
            // std::cout << "Node: " << nodes[i].name << '\n';
            if (nodes[i].name != nodes[j].name) {
                if (nodes[i].used != 0 && nodes[i].used < nodes[j].avail) {
                    viablePairCount++;
                }
            }
        }
    }

    std::cout << "Viable Pairs: " << viablePairCount << "\n";
    //
    // // We save all the valid paths in the stack and begin taking them out until we find
    // // one path which lead to the goal coordinates. If that is found, we save it in
    // // validPaths.
    // stack<coordinates> allPaths;
    // // we begin from 0, 0 and an empty Path.
    // allPaths.push({0, 0, ""});
    // // We search until the stack is empty, meaning there are no more paths left to go on.
    // while(!allPaths.empty()) {
    //     // let's check out the path
    //     coordinates currentPath = allPaths.top();
    //     allPaths.pop();
    //     // The path doesn't lead to the goal, so we generate
    //     // possible moves from the current location and save it in path.
    //     if (currentPath.x == 3 && currentPath.y == 3) {
    //         // the path lead to the goal, we save the path.
    //         validPaths.push_back(currentPath.path);
    //         continue;
    //     }
    //     // The Path accumulates here with valid moves which are then taken one - by - one
    //     // through the stack's pop operation. Saving the new X, Y, and the accumulated path
    //     // so far.
    //     vector<coordinates> directions = allMoves(currentPath.x, currentPath.y, currentPath.path);
    //     for(auto it = directions.begin(); it != directions.end(); ++it) {
    //         // we push all the possible moves from 0, 0 into the stack.
    //         allPaths.push(*it);
    //     }
    // }
    // std::sort(validPaths.begin(), validPaths.end(), [](string s1, string s2){return s1.length() < s2.length();});
    // cout << "Longest Path Length: " << validPaths.back().length() << endl;

    return 0;
}
