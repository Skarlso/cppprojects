#include <vector>
#include <stdio.h>
#include <math.h>

class BuyCar
{
    public:
        static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

// nbMonths
std::vector<int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
    printf("StartOld: %d StartNew: %d savingPerMonth: %d Percentage: %f\n", startPriceOld, startPriceNew, savingperMonth, percentLossByMonth);
    int currentMonthSave = 0;
    int month = 0;
    double currentOldCarPrice = startPriceOld;
    double currentNewCarPrice = startPriceNew;
    while ((currentOldCarPrice + currentMonthSave) < currentNewCarPrice) {
        currentOldCarPrice -= (currentOldCarPrice / 100) * percentLossByMonth;
        currentNewCarPrice -= (currentNewCarPrice / 100) * percentLossByMonth;
        if ((month & 1) == 0) percentLossByMonth += 0.5;
        month++;
        currentMonthSave += savingperMonth;
    }
    int result = round(currentOldCarPrice + currentMonthSave - currentNewCarPrice);
    return {month, result};
}

int main(int argc, char* argv[])
{
    BuyCar buyCar;
    std::vector<int> result = buyCar.nbMonths(1358, 11358, 1000, 1);
    printf("Saving: %d Month: %d\n", result[1], result[0]);

    return 0;
}
