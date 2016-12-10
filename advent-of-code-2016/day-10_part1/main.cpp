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

typedef struct output {
    std::vector<chip> chips;
} output;

typedef struct bot {
    int id;
    std::vector<chip> chips;
} bot;

output output1;
output output2;

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string s;
    std::map<int, bot> bots;
    std::vector<std::string> bot_distribute;

    while (std::getline(file, s)) {
        boost::trim(s);
        std::vector<std::string> split;
        boost::split(split, s, boost::is_any_of(" "));
        if (split[0] == "value") {
            int value, botID;
            std::sscanf(s.c_str(), "value %d goes to bot %d", &value, &botID);
            chip c = { value };
            std::map<int, bot>::iterator it = bots.find(botID);
            if (it == bots.end()) {
                // Bot is not yet known
                bot b;
                b.id = botID;
                std::vector<chip> chips;
                chips.push_back(c);
                b.chips = chips; 
                bots[botID] = b;
            } else {
                // Bot is known
                std::vector<chip> chips = it->second.chips;
                chips.push_back(c);
                it->second.chips = chips;
            }
        } else if (split[0] == "bot") {
            bot_distribute.push_back(s);
        }
    }

    for(auto it = bots.begin(); it != bots.end(); ++it) {
        std::cout << "BOT ID: " << it->second.id << '\n';
        for(auto cit = it->second.chips.begin(); cit != it->second.chips.end(); ++cit) {
            std::cout << "Chip ID: " << cit->num << '\n';
        } 
    }


    for(auto it = bot_distribute.begin(); it != bot_distribute.end(); ++it) {
        std::cout << *it << '\n';
    }
}
