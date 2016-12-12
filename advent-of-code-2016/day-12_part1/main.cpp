#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <map>

using std::string;
using std::vector;
using std::cout;
using std::endl;

std::map<std::string, int> registers = {{"a", 0}, {"b", 0}, {"c", 1}, {"d", 0}};
// std::map<std::string, Have here a map of instr<function> -> with lambda.

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    string str;
    std::stringstream ss;
    vector<vector<string>> instructions;
    while (std::getline(file, str)) {
        boost::trim(str);
        vector<string> split;
        boost::split(split, str, boost::is_any_of(" "));
        instructions.push_back(split);
    }

    for (auto it = instructions.begin(); it != instructions.end();) {
        if (it->at(0) == "cpy") {
            string reg = it->at(2);
            int value = 0;
            string src = it->at(1);
            if (src == "a" || src == "b" || src == "c" || src == "d") {
                value = registers[src];
            } else {
                value = std::atoi(src.c_str());
            }
            registers[reg] = value;
        } else if (it->at(0) == "jnz") {
            string reg = it->at(1);
            int value = std::atoi(it->at(2).c_str());
            if (reg == "a" || reg == "b" || reg == "c" || reg == "d") {
                if (registers[reg] > 0) {
                    std::advance(it, value);
                    continue;
                }
            } else {
                std::advance(it, value);
                continue;
            }
        } else if (it->at(0) == "inc") {
            string reg = it->at(1);
            registers[reg]++;
        } else if (it->at(0) == "dec") {
            string reg = it->at(1);
            registers[reg]--;
        }
        ++it;
    }

    cout << "a: " << registers["a"] << " b: " << registers["b"] << " c: " << registers["c"] << " d: " << registers["d"] << endl;
    return 0;  
}
