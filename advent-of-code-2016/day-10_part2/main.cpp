#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <map>


typedef struct chip {
    int num;
} chip;

inline bool sortChips(chip c1, chip c2) { return (c1.num < c2.num); }

typedef struct output {
    std::vector<chip> chips;
} bot, output;

int multiply(output o) {
    int res = 1;
    std::for_each(o.chips.begin(), o.chips.end(), [&](chip c) {
                res *= c.num;
            });
 
    return res;
}

void collectOutput(std::map<int, output> &out, int id, int value) {
    if (out.find(id) == out.end()) {
        output o;
        o.chips = std::vector<chip>{};
        out[id] = o;
    }
    out[id].chips.push_back({value});
}

void performSwaps(std::vector<std::string> swaps, std::map<int, output> &outs, std::map<int, bot> &bots) {
    bool done = false;
    while (!done) {
        done = true;
        for(auto it = swaps.begin(); it != swaps.end(); ++it) {
            int botSource, highDesID, lowDesID;
            char lowDes[10];
            char highDes[10];
            std::sscanf(it->c_str(), "bot %d gives low to %s %d and high to %s %d", &botSource, lowDes, &lowDesID, highDes, &highDesID);
            
            int high, low;
            bot b = bots[botSource];
            if (b.chips.size() != 2) {
                continue;
            }
            std::sort(b.chips.begin(), b.chips.end(), sortChips);
            low = b.chips[0].num;
            high = b.chips[1].num;
            if (std::string(lowDes) == "output") {
                collectOutput(outs, lowDesID, low);
            } else {
                bots[lowDesID].chips.push_back({low});
            }
            if (std::string(highDes) == "output") {
                collectOutput(outs, highDesID, high);
            } else {
                bots[highDesID].chips.push_back({high});
            }

            b.chips.clear();
            bots[botSource] = b;
        }
        for (auto bit = bots.begin(); bit != bots.end(); ++bit) {
            if (bit->second.chips.size() != 0) {
                done = false;
                break;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string s;
    std::map<int, bot> bots;
    std::vector<std::string> bot_distribute;
    std::map<int, output> outputs;
    while (std::getline(file, s)) {
        boost::trim(s);
        std::vector<std::string> split;
        boost::split(split, s, boost::is_any_of(" "));
        if (split[0] == "value") {
            int value, botID;
            std::sscanf(s.c_str(), "value %d goes to bot %d", &value, &botID);
            // This is basically the same as collectOutput.
            if (bots.find(botID) == bots.end()) { 
                bot b;
                b.chips = std::vector<chip>{};
                bots[botID] = b;
            }
            bots[botID].chips.push_back({value});
        } else if (split[0] == "bot") {
            bot_distribute.push_back(s);
        }
    }
    performSwaps(bot_distribute, outputs, bots);
    int multy = multiply(outputs[0]) * multiply(outputs[1]) * multiply(outputs[2]);
    std::cout << "Multi output: " << multy << '\n';
}
