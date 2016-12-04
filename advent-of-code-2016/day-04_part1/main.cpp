#include <algorithm>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <map>

bool cmp(const std::pair<char, int>  &p1, const std::pair<char, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second;
    }
}

std::string extract_five_most_commond_letters(std::map<char, int> letters) {
    std::string common = "";
    std::vector<std::pair<char, int>> v;
    std::copy(letters.begin(), letters.end(), std::back_inserter(v));
    std::sort(v.begin(), v.end(), cmp);
    for (std::vector<std::pair<char,int>>::iterator it=v.begin(); it!=v.end(); ++it) {
        common += it->first;
    }
    return common.substr(0, 5);
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str; 
    int valid_count = 0;
    while (std::getline(file, str)) {
        std::map <char, int> letters;
        boost::trim(str);
        // Extracting what letters are needed by getting the last element
        // Regex didn't work. Falling back to substring of some weird architecture error... :/
        std::size_t begin = str.find("[");
        std::string needed_letters = str.substr(begin+1);
        needed_letters.pop_back();
        std::string end = str.substr(str.find_last_of("-")+1, str.length());
        std::stringstream ss(end);
        int id;
        ss >> id;
        std::cout << "ID: " << id << '\n';
        str = str.substr(0, str.find_last_of("-"));
        for (char& c : str) {
            // Counting number of letter occurances
            if (c != '-') {
                letters[c]++;
            }
        }
        // Extracting 5 most commond letters in alphabetical order
        std::string common = extract_five_most_commond_letters(letters);
        if (common == needed_letters) {
            valid_count += id;
        }
    }
    std::cout << valid_count << '\n';
    return 0;
}
