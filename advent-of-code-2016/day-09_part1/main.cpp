#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ifstream t(argv[1]);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string s = buffer.str();
    boost::trim(s);
    int newSize = 0;
    for(int i = 0; i < s.length();) {
        if (s[i] == '(') {
            std::string sub = s.substr(i, s.substr(i).find_first_of(')')+1);
            int n, m;
            std::sscanf(sub.c_str(), "(%dx%d)", &n, &m);
            int skip = n * m;
            newSize += skip;
            if (i+n+(sub.length()) > s.length()) {
                newSize += s.substr(i).length();
                break;
            }
            i += n+sub.length();
            continue;
        }
        i++;
        newSize++;
    }
    std::cout << "New size: " << newSize << '\n';
}
