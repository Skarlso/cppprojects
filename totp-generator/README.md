# TOTP Generator Implementation

A generator for TOTP based on RFC-6238.

# OpenSSL HMAC

The hmac implementation used to be this:

```c++
string generateOTPToken(string token, std::time_t t) {
    unsigned char buf[8];
    int timer = int(floor(t/30));
    string decoded = base64_decode("YXNkZg==");
    // The key to hash
    char key[] = "";
    // The data that we're going to hash using HMAC
    unsigned char* digest;
    // Using sha1 hash engine here.
    // You may use other hash engines. e.g EVP_md5(), EVP_sha224, EVP_sha512, etc
    digest = HMAC(EVP_sha1(), key, strlen(key), (unsigned char*)token.c_str(), token.length(), NULL, NULL);

    // Be careful of the length of string with the choosen hash engine. SHA1 produces a 20-byte hash value which rendered as 40 characters.
    // Change the length accordingly with your choosen hash engine
    char mdString[20];
    for(int i = 0; i < 20; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    printf("HMAC digest: %s\n", mdString);

    return "";
}
```
