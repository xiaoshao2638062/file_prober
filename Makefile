CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = main.cpp reader.cpp writer.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = run

all: $(EXEC) clean

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ)

clean_all:
	rm -rf $(OBJ) $(EXEC)