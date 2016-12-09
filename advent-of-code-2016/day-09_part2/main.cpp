#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>

int decompress(std::string s, int depth) {
    if (s.find('(') == std::string::npos) {
        return s.length();
    }
    int newSize = 0;
    for(int i = 0; i < s.length();) {
        // Extract the () part and call this function performing this operation 
        // decompress(head) + decompress( s.substr(head+1) );
    }
    return newSize;
}

int main(int argc, char* argv[]) {
    std::ifstream t(argv[1]);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string s = buffer.str();
    boost::trim(s);
    int newSize = decompress(s, 0);
    std::cout << "New size: " << newSize << '\n';
}
