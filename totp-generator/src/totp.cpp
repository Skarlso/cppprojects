// Copyright [2016] <Gergely Brautigam>
#include <iostream>
#include <string>
#include <algorithm>
#include "cryptopp/hmac.h"

using std::string;
using std::cout;
using std::copy;

int main(int argc, char* argv[]) {
    cout << "Number of arguments passed in: " << argc << "\n";
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << argv[i] << "\n";
    // }
    // return 0;
    string token = argv[1];
    unsigned char tokenChar[sizeof(token)];
    // strcpy(static_cast <char*>(tokenChar), token);
    CryptoPP::BitReverse(12);
    copy(token.begin(), token.end(), tokenChar);
    cout << tokenChar << "\n";
}
