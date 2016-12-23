#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <map>
#include <cmath>

using std::string;
using std::vector;
using std::cout;
using std::endl;

std::map<std::string, int> registers = {{"a", 7}, {"b", 0}, {"c", 0}, {"d", 0}};
#define int_or_reg(r) (registers.find(r) != registers.end() ? registers[r] : std::atoi(r.c_str()))

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
        // std::cout << "=========" << "\n";
        // for (auto insts = instructions.begin(); insts != instructions.end(); ++insts)
        // {
        //     std::cout << insts->at(0) << "\n";
        // }
        if (it->at(0) == "cpy") {
            string reg = it->at(2);
            string src = it->at(1);
            int value = int_or_reg(src);
            if (reg == "a" || reg == "b" || reg == "c" || reg == "d") {
                registers[reg] = value;
            } else {
                ++it;
                continue;
            }
        } else if (it->at(0) == "jnz") {
            int reg = int_or_reg(it->at(1));
            int value = int_or_reg(it->at(2));
            // if (reg == "a" || reg == "b" || reg == "c" || reg == "d") {
            // std::cout << "JUMPING by: " << value << "\n";
            if (reg > 0) {
                if (value > instructions.size()) {
                    ++it;
                    continue;
                }
                std::advance(it, value);
                continue;
            }
        } else if (it->at(0) == "inc") {
            string reg = it->at(1);
            registers[reg]++;
        } else if (it->at(0) == "dec") {
            string reg = it->at(1);
            registers[reg]--;
        } else if (it->at(0) == "tgl") {
            int value = int_or_reg(it->at(1));
            if (value > instructions.size()) {
                ++it;
                continue;
            }
            auto nxt = it;
            if (value > 0) nxt = std::next(it, value);
            if (value < 0) nxt = std::prev(it, std::abs(value));
            string inst = nxt->at(0);
            if (inst == "dec" || inst == "tgl") {
                inst = "inc";
            } else if (inst == "inc") {
                inst = "dec";
            } else if (inst == "jnz") {
                inst = "cpy";
            } else if (inst == "cpy") {
                inst = "jnz";
            }
            nxt->at(0) = inst;
        }
        ++it;
    }

    cout << "a: " << registers["a"] << " b: " << registers["b"] << " c: " << registers["c"] << " d: " << registers["d"] << endl;
    return 0;
}
