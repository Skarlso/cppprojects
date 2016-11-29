#------------------------------------------------------------------------------
SOURCE=src/totp.cpp
MYPROGRAM=totp
MYINCLUDES=lib
MYLINKS=cryptopp
CC=g++
#------------------------------------------------------------------------------

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) -l$(MYLINKS) -std=c++11

clean:
	rm -f $(MYPROGRAM)
