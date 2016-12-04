#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <sstream>

std::string decrypt(std::string str, int rotate) {
    std::string decrypted = "";
    for (char& c : str) {
        if (c == '-') {
            continue;
        }
        char s = c - 'a';
        s = (s + rotate) % 26;
        s = s + 'a';
        decrypted += s;
    }

    return decrypted;
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str; 
    while (std::getline(file, str)) {
        boost::trim(str);
        std::string end = str.substr(str.find_last_of("-")+1, str.length());
        std::stringstream ss(end);
        int id;
        ss >> id;
        std::cout << "ID: " << id << '\n';
        str = str.substr(0, str.find_last_of("-"));
        str = decrypt(str, id);
        std::cout << str << '\n';
    }
    return 0;
}
