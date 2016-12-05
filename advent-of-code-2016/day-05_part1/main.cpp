#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "cryptopp/md5.h"
#include "cryptopp/hex.h"
#include <string>
#include <iostream>

const std::string input = "reyedfim";

std::string generateMD5Checksum(std::string message) {
    byte digest[ CryptoPP::Weak::MD5::DIGESTSIZE ];

    CryptoPP::Weak::MD5 hash;
    hash.CalculateDigest( digest, (const byte*)message.c_str(), message.length() );

    CryptoPP::HexEncoder encoder;
    std::string output;

    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    return output;
}

int main() {
    std::string password = "";
    int count = 1;
    for(;;) {
        std::string temp = input;
        temp += std::to_string(count);
        auto sum = generateMD5Checksum(temp);
        std::cout << sum.substr(0, 5) << std::endl;
        if (sum.substr(0, 5) == "00000") {
            password += sum[5];
        }
        if (password.length() == 8) {
            break;
        }
        count++;
    }
    std::cout << password << std::endl;
    return 0;
}
