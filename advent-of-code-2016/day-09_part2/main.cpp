#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>

typedef unsigned long long verylong;

verylong decompress(std::string s) {
    ///std::cout << s << '\n';
    //if (s.find('(') == std::string::npos) {
    //    return s.length();
    //}
    verylong newSize = 0;
    for(int i = 0; i < s.length();) {
        if (s[i] == '(') {
            std::string sub = s.substr(i, s.substr(i).find_first_of(')')+1);
            int c_count, times;
            std::sscanf(sub.c_str(), "(%dx%d)", &c_count, &times);
            newSize += times * decompress(s.substr(i + sub.length(), c_count));
            i += c_count + sub.length();
        } else {
            i++;
            newSize++;
        }
    }
    return newSize;
}

int main(int argc, char* argv[]) {
    std::ifstream t(argv[1]);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string s = buffer.str();
    boost::trim(s);
    verylong newSize = decompress(s);
    std::cout << "New size: " << newSize << '\n';
}
