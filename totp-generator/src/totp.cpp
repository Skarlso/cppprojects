// Copyright [2016] <Gergely Brautigam>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <string>
#include <ctime>
#include <cmath>
#include "base64.h"

using std::string;

string generateOTPTokenV2(string token, std::time_t t) {
    unsigned char buf[8];
    int timer = int(floor(t/30));
    string decoded = base64_decode("YXNkZg==");

    const unsigned char *ibuf = (const unsigned char *)token.c_str();
    unsigned char obuf[20];

    SHA1(ibuf, token.length(), obuf);

    char mdString[20];
    for(int i = 0; i < 20; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)obuf[i]);

    printf("SHA1 digest: %s\n", mdString);
    return "";
}

int main()
{
    std::time_t result = std::time(nullptr);
    generateOTPTokenV2("anyad", result);
    return 0;
}
