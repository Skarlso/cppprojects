#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

const string INPUT = "10010000000110000";
//const int SIZE = 272;
const int SIZE_PART2 = 35651584;


string checksum(string s) {
    if ((s.length() & 1) == 1) {
        return s;
    }
    string sum;
    for (int i = 0; i < s.length() - 1; i += 2) {
        if (s[i] == s[i+1]) {
            sum += '1';
        } else {
            sum += '0';
        }
    }
    return checksum(sum);
}

string dragoncurve(string a, int size) {
    if (a.length() >= size) {
        return a.substr(0, size);
    }

    string b = a;
    std::reverse(b.begin(), b.end());
    std::for_each(b.begin(), b.end(), [](char& c) { c == '0' ? c = '1' : c = '0'; });
    a += "0" + b;
    return dragoncurve(a, size);
}

int main() {
    string dragon = dragoncurve(INPUT, SIZE_PART2);
    cout << checksum(dragon) << endl;
    return 0;
}
