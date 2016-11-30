#------------------------------------------------------------------------------
CFLAGS=-g -c -Wall -std=c++0x -stdlib=libc++ -pthread
SOURCE=src/totp.cpp
MYPROGRAM=totp
MYINCLUDES=lib
MYLINKS=cryptopp
CC=g++
#------------------------------------------------------------------------------

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) $(CFLAGS) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) -l$(MYLINKS) -std=c++11

clean:
	rm -f $(MYPROGRAM)
