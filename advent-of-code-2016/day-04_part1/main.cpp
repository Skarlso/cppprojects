#include <algorithm>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <map>

std::string extract_five_most_commond_letters(std::map<char, int> letters) {
    std::string common = "";
    std::vector<std::pair<char, int>> v;
    std::copy(letters.begin(), letters.end(), std::back_inserter(v));
    std::sort(v.begin(), v.end(), [](auto p1, auto p2){
        return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
    });
    for (std::vector<std::pair<char,int>>::iterator it=v.begin(); it!=v.end(); ++it) {
        common += it->first;
    }
    return common.substr(0, 5);
}

std::string extract_needed_letters(std::string str) {
    std::size_t begin = str.find("[");
    std::string needed_letters = str.substr(begin+1);
    needed_letters.pop_back();
    return needed_letters;
}

int extract_id(std::string str) {
    std::string end = str.substr(str.find_last_of("-")+1, str.length());
    std::stringstream ss(end);
    int id;
    ss >> id;
    return id;
}

std::map<char, int> extract_letter_count(std::string str) {
    std::map<char, int> ret;
    str = str.substr(0, str.find_last_of("-"));
    for (char& c : str) {
        if (c != '-') {
            ret[c]++;
        }
    }
    return ret;
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str; 
    int valid_count = 0;
    while (std::getline(file, str)) {
        boost::trim(str);
        std::string needed_letters = extract_needed_letters(str);
        int id = extract_id(str);
        std::map <char, int> letters = extract_letter_count(str);
        std::string common = extract_five_most_commond_letters(letters);
        if (common == needed_letters) {
            valid_count += id;
        }
    }
    std::cout << valid_count << '\n';
    return 0;
}
