#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

const string INPUT = "10010000000110000";
//const int SIZE = 272;
const int SIZE_PART2 = 35651584;


string checksum(string s) {
    string sum = s;
    
    while ((sum.length() & 1) == 0) {
        string newSum = "";
        for (int i = 0; i < sum.length() - 1; i += 2) {
            if (sum[i] == sum[i+1]) {
                newSum += '1';
            } else {
                newSum += '0';
            }
        }
        sum = newSum;
    }
    return sum;
}

string dragoncurve(string a, int size) {
    string dragon = a;

    while (dragon.length() < size) {
        string b = dragon;

        std::reverse(b.begin(), b.end());
        std::for_each(b.begin(), b.end(), [](char& c) { c == '0' ? c = '1' : c = '0'; });
        dragon += "0" + b;
    }
    return dragon.substr(0, size);
}

int main() {
    string dragon = dragoncurve(INPUT, SIZE_PART2);
    cout << checksum(dragon) << endl;
    return 0;
}
