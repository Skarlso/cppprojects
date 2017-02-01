// Copyright [2016] <Gergely Brautigam>
#include <stdio.h>
#include <string.h>
#include <openssl/hmac.h>
#include <string>
#include <ctime>
#include <cmath>
#include "base64.h"

using std::string;

//string generateOTPToken(string token, std::time_t t) {
//    unsigned char buf[8];
//    string timer = std::to_string(int(floor(t/30)));
//    string decoded = base64_decode(token);
//    // The key to hash
//    char key[timer.length()];
//    strcpy(key, timer.c_str());
//    char data[token.length()];
//    strcpy(data, token.c_str());
//    // The data that we're going to hash using HMAC
//    unsigned char* digest;
//    // Using sha1 hash engine here.
//    // You may use other hash engines. e.g EVP_md5(), EVP_sha224, EVP_sha512, etc
//    digest = HMAC(EVP_sha1(), key, strlen(key), (unsigned char*)data, strlen(data), NULL, NULL);
//    printf("Digest len: %lu\n", sizeof(digest));
//    // Be careful of the length of string with the choosen hash engine. SHA1 produces a 20-byte hash value which rendered as 40 characters.
//    // Change the length accordingly with your choosen hash engine
//    char mdString[20];
//    for(int i = 0; i < 20; i++)
//         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
//
//    printf("HMAC digest: %s\n", mdString);
//    return "";
//}

//int main()
//{
//    std::time_t result = std::time(nullptr);
//    generateOTPToken("anyad", result);
//    printf("What\n");
//    return 0;
//}
int main()
{
    // The key to hash
    string key= "012345678";
    printf("Key len: %zu\n", strlen(key.c_str())); 
    // The data that we're going to hash using HMAC
    string data = "hello world";
    printf("Data len: %zu\n", strlen(data.c_str())); 
    unsigned char* digest;
    char data2[1024];
    strcpy(data2, data.c_str()); 
    // Using sha1 hash engine here.
    // You may use other hash engines. e.g EVP_md5(), EVP_sha224, EVP_sha512, etc
    digest = HMAC(EVP_sha1(), key.c_str(), strlen(key.c_str()), (unsigned char*)data2, strlen(data.c_str()), NULL, NULL);    
 
    // Be careful of the length of string with the choosen hash engine. SHA1 produces a 20-byte hash value which rendered as 40 characters.
    // Change the length accordingly with your choosen hash engine
    char mdString[20];
    for(int i = 0; i < 20; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
 
    printf("HMAC digest: %s\n", mdString);
 
    return 0;
}
