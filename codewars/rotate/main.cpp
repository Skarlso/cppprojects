#include <vector>
#include <string>
#include <iostream>

class MaxRotate
{
public:
  static long long maxRot(long long n);
};

long long MaxRotate::maxRot(long long n) {
    long long max = n;
    std::string rotate = std::to_string(n);
    long long decimal = 0;
    while (decimal < rotate.length()) {
        std::string current = rotate.substr(decimal, rotate.length());
        std::rotate(current.begin(), current.begin()+1, current.end());
        rotate = rotate.substr(0, decimal) + current;
        long long stoll = std::stoll(rotate);
        if (stoll > max) max = stoll;
        decimal++;
    }
    return max;
}

int main(int argc, char* argv[])
{
    MaxRotate maxRotate;

    std::cout << maxRotate.maxRot(16130873362142) << "\n";
    return 0;
}
