# TOTP Generator Implementation

A generator for TOTP based on RFC-6238.

## Usage

Set `OTP_TOKEN` environment property to your desired otp token than run:

```bash
./bin/totp
```

To immediately put the generated token on the clipboard, run:

```bash
./bin/totp | pbcopy
```
