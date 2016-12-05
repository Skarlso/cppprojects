#CC=g++
#CFLAGS=-g -Wall -std=c++11 -stdlib=libc++ -L. -lcryptopp
#SOURCES= main.cpp
#INCLUDES= -I.
#OBJECTS= $(SOURCES:.cpp=.o)
#TARGET= solution
#
#all: $(SOURCES) $(TARGET)
#
#$(TARGET): $(OBJECTS)
#	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
#
#.cpp.o:
#	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
#
#clean:
#	rm -rf $(OBJECTS) $(TARGET)
#	rm -fr main.o.*
#------------------------------------------------------------------------------
CFLAGS=-g -Wall -std=c++14 -stdlib=libc++ -pthread
SOURCE=main.cpp
MYPROGRAM=solution
MYLINKS=cryptopp
CC=g++
#------------------------------------------------------------------------------

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) $(CFLAGS) -l$(MYLINKS) $(SOURCE) -o$(MYPROGRAM)

clean:
	rm -f $(MYPROGRAM)
	rm -fr $(MYPROGRAM).*
