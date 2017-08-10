CC = g++
CFLAGS = -Wall -std=c++14 -pedantic -Wextra
LDFLAGS =

INC_DIRS = -ITest/googletest/googletest/include

PROGNAME = TucanBot

SRC = TucanClient.cpp Message.cpp

OBJ = $(SRC:.cpp=.o)


all: $(OBJ)
	$(CC) $(CFLAGS) -o $(PROGNAME) $(LDFLAGS) $(OBJ)

# delete all object files and the binary
clean:
	rm -f $(PROGNAME) *.o

test: all
	cd Test && $(MAKE) all

# pattern rule to compile .c files into .o files with the same name
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
