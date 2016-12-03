#------------------------------------------------------------------------------
CFLAGS=-g -Wall -std=c++11 -stdlib=libc++ -pthread
SOURCE=src/totp.cpp
MYPROGRAM=totp
MYLIBS=lib
MYLINKS=cryptopp
CC=g++
#------------------------------------------------------------------------------

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) $(CFLAGS) -L$(MYLIBS) $(SOURCE) -o$(MYPROGRAM) -l$(MYLINKS)

clean:
	rm -f $(MYPROGRAM)
	rm -fr $(MYPROGRAM).*
