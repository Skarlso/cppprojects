#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <map>

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string str;
    int column_length = 0;
    std::vector<std::vector<char>> content;
    std::string phrase = "";
    while (std::getline(file, str)) {
        boost::trim(str);
        column_length = str.length();
        std::vector<char> s(str.begin(), str.end());
        content.push_back(s);
    }

    for (int i = 0; i < column_length; ++i)
    {
        std::map<char, int> letters;
        for (std::vector<char> in : content) {
            letters[in.at(i)]++;
        }

        std::vector<std::pair<char, int>> v;
        std::copy(letters.begin(), letters.end(), std::back_inserter(v));
        std::sort(v.begin(), v.end(), [](auto p1, auto p2){
            return p1.second > p2.second;
        });
        phrase += v.front().first;
    }
    std::cout << phrase << '\n';
    return 0;
}
