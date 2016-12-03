#include <algorithm>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <sstream>
#include <vector>

inline bool is_triangle(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}

int count_valid_triangles(std::vector<int> col) {
    int valid = 0;
    for (int i = 0; i < col.size(); i += 3) {
        if (i+2 < col.size() && is_triangle(col.at(i), col.at(i+1), col.at(i+2))) {
            valid++;
        }
    }
    return valid;
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str; 
    int valid_counter = 0;
    std::vector<int> col1;
    std::vector<int> col2;
    std::vector<int> col3;
    while (std::getline(file, str)) {
        std::vector<int> result;
        boost::trim(str);
        int a, b, c;
        std::stringstream ss(str);
        ss >> a >> b >> c;
        col1.push_back(a);
        col2.push_back(b);
        col3.push_back(c);
    }

    valid_counter += count_valid_triangles(col1);
    valid_counter += count_valid_triangles(col2);
    valid_counter += count_valid_triangles(col3);    

    std::cout << "Valid triangles: " <<valid_counter << '\n';
    return 0;
}
