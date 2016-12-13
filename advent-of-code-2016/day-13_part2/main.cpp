#include <bitset>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stdio.h>

using std::cout;
using std::endl;
using std::set;
using std::vector;

typedef struct coordinates {
    int x, y;
    bool operator<(coordinates other) const {
        return x < other.x && y < other.y;
    }
    
    bool operator==(coordinates other) const {
        return x == other.x && y == other.y;
    }
} coordinates;

const int DESIGNER_INPUT = 1352;
const int TARGET_X = 31;
const int TARGET_Y = 39;
vector<coordinates> alreayVisited;

bool wall(int x, int y) {
    int decimal = ((x*x) + (3*x) + (2*x*y) + (y) + (y*y)) + DESIGNER_INPUT;
    std::bitset<sizeof(int) * CHAR_BIT> b(decimal);
    return (b.count() & 1) == 1;
}

bool visited(coordinates c) {
    return std::find(alreayVisited.begin(), alreayVisited.end(), c) != alreayVisited.end();
}

vector<coordinates> move(vector<coordinates> p) {
    vector<coordinates> ret;
    for(auto it = p.begin(); it != p.end(); ++it) {
        int x = it->x;
        int y = it->y;
        if (x != 0) {
            if (!visited({x-1, y}) && !wall(x-1, y)) {
                alreayVisited.push_back({x-1, y});
                ret.push_back({x-1, y});
            }
        }
        if (y != 0) {
            if (!visited({x, y-1}) && !wall(x, y-1)) {
                alreayVisited.push_back({x, y-1});
                ret.push_back({x, y-1});
            }
        }
        if (!visited({x+1, y}) && !wall(x+1, y)) {
            alreayVisited.push_back({x+1, y});
            ret.push_back({x+1, y});
        }
        if (!visited({x, y+1}) && !wall(x, y+1)) {
            alreayVisited.push_back({x, y+1});
            ret.push_back({x, y+1});
        }
    } 
    return ret;
}

int main() {
    coordinates goal = {TARGET_X, TARGET_Y};
    vector<coordinates> mPath;
    int stepCount = 0;
    mPath.push_back({1, 1});
    while (std::find(mPath.begin(), mPath.end(), goal) == mPath.end()) {
        mPath = move(mPath);
        stepCount++;
        if (stepCount == 50) {
            cout << "Distinct loc: " << alreayVisited.size() << endl;
        }
    }
    cout << "Step Count: " << stepCount << endl;
    return 0;
}
