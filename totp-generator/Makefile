#------------------------------------------------------------------------------

SOURCE=src/totp.cpp
MYPROGRAM=totp
MYINCLUDES=lib
CC=g++
#------------------------------------------------------------------------------

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) -std=c++11

clean:
	rm -f $(MYPROGRAM)
