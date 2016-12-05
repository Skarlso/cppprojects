#include <openssl/md5.h>
#include <string>
#include <iostream>

std::string generateMD5Checksum(std::string input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.length(), (unsigned char*)&digest);
    char mdString[33];
    for(int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    return mdString;
}

int main(int argc, char* argv[])
{
    std::string input = "reyedfim";
    std::string password = "";
    for(int count = 1; password.length() < 8; count++) {
        std::string temp = input;
        temp += std::to_string(count);
        std::string sum = generateMD5Checksum(temp);
        if (sum.substr(0, 5) == "00000") {
            std::cout << "Found letter: " << sum[5] << std::endl;
            password += sum[5];
        }
    }
    std::cout << password << "\n";
    return 0;
}
