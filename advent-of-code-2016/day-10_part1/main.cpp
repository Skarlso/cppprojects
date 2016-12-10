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
    int id;
    std::vector<chip> chips;
} output;

typedef struct bot {
    int id;
    std::vector<chip> chips;
} bot;

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
        std::cout << "BOT ID: " << it->first << '\n';
        for(auto cit = it->second.chips.begin(); cit != it->second.chips.end(); ++cit) {
            std::cout << "Chip ID: " << cit->num << '\n';
        } 
    }

    // Vegtelen ciklus, ami addig megy, amig meg nincs a compare. 
    // Egy bot csak akkor hasonlit, ha ket chipje van, addig skip,
    // es johet a koveketzo instructio.
    bool botfound = false;
    while (!botfound) {
        for(auto it = bot_distribute.begin(); it != bot_distribute.end(); ++it) {
            int botSource, highDesID, lowDesID;
            char lowDes[10];
            char highDes[10];
            std::sscanf(it->c_str(), "bot %d gives low to %s %d and high to %s %d", &botSource, lowDes, &lowDesID, highDes, &highDesID);
            //std::printf("Bot: %d; LowBot: %d; High bot: %d \n", botSource, botLow, botHigh);
            // I'm assuming here that botSource exists, ERIC.
            // Perform Compare operation here, and give save which chip was compared to which by what bot.
            int high, low;
            bot b = bots[botSource];
            if (b.chips.size() != 2) {
                continue;
            }
            std::sort(b.chips.begin(), b.chips.end(), sortChips);
            low = b.chips[0].num;
            high = b.chips[1].num;
            std::printf("Bot: %d is comparing low: %d to high: %d. \n", botSource, low, high);
            if (high == 61 && low == 17) {
                std::cout << "Bot comparing : " << botSource << '\n';
                botfound = true;
                break;
            }
            if (std::string(lowDes) == "output") {
                if (outputs.find(lowDesID) == outputs.end()) {
                    output o;
                    o.chips = std::vector<chip>{};
                    outputs[lowDesID] = o;
                }
                outputs[lowDesID].chips.push_back({low});
            } else {
                bots[lowDesID].chips.push_back({low});
            }
            
            if (std::string(highDes) == "output") {
                if (outputs.find(highDesID) == outputs.end()) {
                    output o;
                    o.chips = std::vector<chip>{};
                    outputs[highDesID] = o;
                }
                outputs[highDesID].chips.push_back({high});
            } else {
                bots[highDesID].chips.push_back({high});
            }

            b.chips.clear();
            bots[botSource] = b;
        }
    }
}
