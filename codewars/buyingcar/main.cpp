#include <vector>
#include <iostream>
#include <stdio.h>

class BuyCar
{
    public:
        static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

// nbMonths
std::vector<int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
    // month & 1 == 0 -> increase loss percentage.
    // how many months 'till he can buy the car and how much money will be left over.
    std::vector<int> ret;

    if (startPriceOld >= startPriceNew) {
        ret.push_back(0);
        ret.push_back(startPriceOld - startPriceNew);
        return ret;
    }

    return ret;
}

int main(int argc, char* argv[])
{
    BuyCar buyCar;
    std::vector<int> result = buyCar.nbMonths(12000, 8000, 1000, 1.5);
    printf("Saving: %d Month: %d\n", result[1], result[0]);

    return 0;
}
