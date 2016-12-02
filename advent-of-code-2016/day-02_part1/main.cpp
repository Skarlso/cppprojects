#include <fstream>
#include <streambuf>
#include <string>
#include <cerrno>
#include <iostream>
#include <vector>

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
    for(char& c : content) {
        switch(c) {
            case 'U' : if (v - 1 >= 0) {
                           v--;
                       }
                       break;
            case 'D' : if (v + 1 < 3) {
                           v++;
                       }
                       break;
            case 'L' : if (h - 1 >= 0) {
                           h--;
                       }
                       break;
            case 'R' : if (h + 1 < 3) {
                           h++;
                       }
                       break;
            case '\n' : combination.push_back(keypad[v][h]);
                        break;
        }
    }
    for (auto i : combination) {
        std::cout << i;
    }
    return 0;
}
