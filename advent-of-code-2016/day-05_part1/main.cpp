#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "cryptopp/md5.h"
#include "cryptopp/hex.h"
#include <string>
#include <iostream>

const std::string input = "reyedfim";

//std::string generateMD5Checksum(std::string message) {
//    byte digest[ CryptoPP::Weak::MD5::DIGESTSIZE ];
//
//    CryptoPP::Weak::MD5 hash;
//    hash.CalculateDigest( digest, (const byte*)message.c_str(), message.length() );
//
//    CryptoPP::HexEncoder encoder;
//    std::string output;
//
//    encoder.Attach( new CryptoPP::StringSink( output ) );
//    encoder.Put( digest, sizeof(digest) );
//    encoder.MessageEnd();
//
//    return output;
//}

std::string generateMD5ChecksumWithFilter(std::string message) {
    CryptoPP::Weak::MD5 hash;
    std::string digest;
    CryptoPP::StringSource s(message, true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest))));
    return digest;
}

int main() {
    std::string password = "";
    int count = 1;
    for(;;) {
        std::string temp = input;
        temp += std::to_string(count);
        auto sum = generateMD5ChecksumWithFilter(temp);
        if (sum.substr(0, 5) == "00000") {
            std::cout << "Found letter: " << sum[5] << std::endl;
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
