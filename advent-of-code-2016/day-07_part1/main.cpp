#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <map>

bool getABBA(std::string str) {
    bool supportsTLS = false;
    bool bracketIndicator = false;
    bool allowABBA = true;
    for(int i = 3; i < str.length(); i++) {
        if (str[i] == '[') {
            bracketIndicator = true;
        }
        if (str[i] == ']') {
            bracketIndicator = false;
        }
        if (str[i] == str[i-3] && str[i-1] == str[i-2] && str[i] != str[i-1]) {
            if (bracketIndicator) {
                allowABBA = false;
            }
            supportsTLS = true;
        } 
    }
    return allowABBA && supportsTLS;
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str;
    int supportTLS = 0;
    while (std::getline(file, str)) {
        boost::trim(str);
        if (getABBA(str)) {
            std::cout << "Supporting TLS: " << str << std::endl;
            supportTLS++;
        }
    }
    std::cout << "Supporting TLS: " << supportTLS << std::endl;
    return 0;
}
