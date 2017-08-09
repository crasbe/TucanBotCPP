CC = g++
CFLAGS = -Wall -std=c++14 -pedantic -Wextra
LDFLAGS =
PROGNAME = TucanBot

SRC = Main.cpp Message.cpp

OBJ = $(SRC:.cpp=.o)


all: $(OBJ)
	$(CC) $(CFLAGS) -o $(PROGNAME) $(LDFLAGS) $(OBJ)

# delete all object files and the binary
clean:
	rm -f $(PROGNAME) *.o
	

# pattern rule to compile .c files into .o files with the same name
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
