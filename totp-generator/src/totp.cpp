// Copyright [2016] <Gergely Brautigam>
#include <stdio.h>
#include <string.h>
#include <openssl/hmac.h>
#include <string>
#include <ctime>
#include <cmath>
#include "base64.h"

using std::string;

string generateOTPToken(string token, std::time_t t) {
    int timer = int(floor(t/30));
    printf("Time: %d\n", timer);
    string decoded = base64_decode("YXNkZg==");
    printf("Decoded: %s\n", decoded.c_str());
    return "";
}

int main()
{
    // The key to hash
    char key[] = "012345678";

    // The data that we're going to hash using HMAC
    char data[] = "hello world";

    unsigned char* digest;

    // Using sha1 hash engine here.
    // You may use other hash engines. e.g EVP_md5(), EVP_sha224, EVP_sha512, etc
    digest = HMAC(EVP_sha1(), key, strlen(key), (unsigned char*)data, strlen(data), NULL, NULL);

    // Be careful of the length of string with the choosen hash engine. SHA1 produces a 20-byte hash value which rendered as 40 characters.
    // Change the length accordingly with your choosen hash engine
    char mdString[20];
    for(int i = 0; i < 20; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    printf("HMAC digest: %s\n", mdString);

    std::time_t result = std::time(nullptr);
    generateOTPToken("anyad", result); 

    return 0;
}
