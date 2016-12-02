#include <fstream>
#include <streambuf>
#include <string>
#include <cerrno>
#include <iostream>
#include <vector>

struct coord_t {
    int v;
    int h;
} coord;

std::string get_file_contents(const char *filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    return(std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
  }
  throw(errno);
}

int main(int argc, char* argv[]) {
    int keypad[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int v = 1;
    int h = 1;
    std::vector<int> combination;
    std::string content = get_file_contents(argv[1]);
    for(auto c : content) {
        if (c == 'U') {
            coord.v = -1;
            coord.h = 0;
        } else if (c == 'D') {
            coord.v = 1;
            coord.h = 0;
        } else if (c == 'R') {
            coord.v = 0;
            coord.h = 1;
        } else if (c == 'L') {
            coord.v = 0;
            coord.h = -1;
        } else if (c == '\n') {
            combination.push_back(keypad[v][h]);
            continue;
        }

        if (v + coord.v >= 0 && v + coord.v < 3) {
            v += coord.v;
        }
        if (h + coord.h >= 0 && h + coord.h < 3) {
            h += coord.h;
        }
    }

    for (auto i : combination) {
        std::cout << i;
    }
}

