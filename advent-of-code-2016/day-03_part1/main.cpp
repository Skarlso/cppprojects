#include <algorithm>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str; 
    int valid_counter = 0;
    while (std::getline(file, str)) {
        std::vector<int> result;
        boost::trim(str);
        int a, b, c;
        std::stringstream ss(str);
        ss >> a >> b >> c;
        result.push_back(a);
        result.push_back(b);
        result.push_back(c);
        std::sort(result.begin(), result.end());
        if ((result.at(0) + result.at(1)) > result.at(2)) {
            valid_counter++;
        } 

    }
    std::cout << "Valid triangles: " <<valid_counter << '\n';
    return 0;
}
