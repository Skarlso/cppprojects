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

    std::cout << generateMD5Checksum(input) << std::endl;
    return 0;
}
