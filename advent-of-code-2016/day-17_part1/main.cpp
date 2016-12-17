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
    vector<coordinates> validPaths;
    stack<coordinates> allPaths;
    allPaths.push({0, 0, ""});
    while(!allPaths.empty()) {
        coordinates currentPath = allPaths.top();
        allPaths.pop();
        if (currentPath.x == 3 && currentPath.y == 3) {
            validPaths.push_back(currentPath);
            continue;
        }
        vector<coordinates> directions = allMoves(currentPath.x, currentPath.y, currentPath.path);
        for(auto it = directions.begin(); it != directions.end(); ++it) {
            allPaths.push(*it);
        }
    }
    std::sort(validPaths.begin(), validPaths.end());
    cout << "First valid path: " << validPaths.front().path << endl;
    return 0;
}
