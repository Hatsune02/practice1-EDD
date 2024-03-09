CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRCS = board/Board.cpp cards/Card.cpp cards/Deck.cpp cards/Node.cpp cards/LinkedList.cpp cards/Queue.cpp cards/Stack.cpp main.cpp
OBJS = $(addprefix objects/, $(SRCS:.cpp=.o))
TARGET = output/solitaire-game

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | output
	$(CXX) $(CXXFLAGS) $^ -o $@

objects/%.o: %.cpp | objects
	$(CXX) $(CXXFLAGS) -c $^ -o $@

objects:
	mkdir -p objects/board
	mkdir -p objects/cards

output:
	mkdir -p output

clean: 
	rm -f $(OBJS) $(TARGET)