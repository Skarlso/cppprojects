// Copyright [2016] <Gergely Brautigam>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments passed in: " << argc << "\n";
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << "\n";
    }
    return 0;
}
