#include <openssl/md5.h>
#include <string>
#include <iostream>

using std::string;

const string input = "zpqevtbw";
//const string input = "abc";

string generateMD5Checksum(string input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.length(), (unsigned char*)&digest);
    char mdString[33];
    for(int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    return mdString;
}

bool checkQuadruplet(char c, string sum) {
    for(int i = 0; i < sum.length(); ++i) {
        if (i+4 < sum.length()) {
            if (sum[i] == c) {
                if (sum[i] == sum[i+1] && sum[i] == sum[i+2] && sum[i] == sum[i+3] && sum[i] == sum[i+4]) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool checkNextThousandHashes(char c, int num) {
    int inc = num+1;
    for (int i = 0; i < 1000; ++i) {
        string temp = input;
        temp += std::to_string(inc);
        string sum = generateMD5Checksum(temp);
        if (checkQuadruplet(c, sum)) {
            return true;
        }
        inc++;
    }
    return false;
}

char checkTriplet(string sum) {
    for(int i = 0; i < sum.length(); ++i) {
        if (i+2 < sum.length()) {
            if (sum[i] == sum[i+1] && sum[i] == sum[i+2]) {
                return sum[i];
            }
        }
    }

    return '!';
}

bool validateHash(string sum, int num) {
    char c = checkTriplet(sum);
    if (c != '!') {
        return checkNextThousandHashes(c, num);
    }
    return false; 
} 

int main(int argc, char* argv[])
{
    bool done = false;
    int num = 0;
    int padkeycount = 0;
    while (!done) {
        string temp = input;
        temp += std::to_string(num);
        string sum = generateMD5Checksum(temp);
        if (validateHash(sum, num)) {
            padkeycount++;
            if (padkeycount == 64) {
                std::cout << "64th hash index is: " << num << std::endl;
                done = true;
            }
        }
        num++;
    }

    return 0;
}
