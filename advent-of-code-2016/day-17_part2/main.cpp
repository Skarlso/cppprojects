#include <bitset>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <openssl/md5.h>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::string;
using std::stack;

typedef struct coordinates {
    int x, y;
    string path;
    bool operator<(coordinates other) const {
        return path.length() < other.path.length();
    }
    
    bool operator==(coordinates other) const {
        return path.length() == other.path.length();
    }
} coordinates;

const string INPUT = "hhhxzeay";
const string openedDoors = "bcdef";

string generateMD5Checksum(string input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.length(), (unsigned char*)&digest);
    char mdString[33];
    for(int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    return mdString;
}

// Gather all valid moves around a coordinate and add them to a vector.
vector<coordinates> allMoves(int x, int y, string paths) {
    string md5 = generateMD5Checksum(INPUT + paths);
    vector<coordinates> ret;
    if (x > 0 && openedDoors.find(md5[2]) != string::npos) {
        ret.push_back({x - 1, y, paths + 'L'});
    }
    if (x < 3 && openedDoors.find(md5[3]) != string::npos) {
        ret.push_back({x + 1, y, paths + 'R'});
    }
    if (y > 0 && openedDoors.find(md5[0]) != string::npos) {
        ret.push_back({x, y - 1, paths + 'U'});
    }
    if (y < 3 && openedDoors.find(md5[1]) != string::npos) {
        ret.push_back({x, y + 1, paths + 'D'});
    }
    return ret;
}

int main() {
    // gather all the valid paths here which lead to the goal coordinate x, y.
    vector<coordinates> validPaths;
    // We save all the valid paths in the stack and begin walking it by pops.
    stack<coordinates> allPaths;
    // we begin from 0, 0.
    allPaths.push({0, 0, ""});
    // We search until the stack is empty, meaning there are no more paths left to go on.
    while(!allPaths.empty()) {
        // let's check out the path
        coordinates currentPath = allPaths.top();
        allPaths.pop();
        // The path doesn't lead to the goal, so we generate
        // possible moves from the current location.
        if (currentPath.x == 3 && currentPath.y == 3) {
            // the path lead to the goal, we save the path.
            validPaths.push_back(currentPath);
            continue;
        }
        // current location (0, 0) -> possible moves from zero, zero are ->
        // since the path is always appended, we gather all the steps until
        // we arrive at the goal.
        vector<coordinates> directions = allMoves(currentPath.x, currentPath.y, currentPath.path);
        for(auto it = directions.begin(); it != directions.end(); ++it) {
            // we push all the possible moves from 0, 0 into the stack.
            allPaths.push(*it);
        }
    }
    std::sort(validPaths.begin(), validPaths.end());
    cout << "Longest Path Length: " << validPaths.back().path.length() << endl;

    return 0;
}
