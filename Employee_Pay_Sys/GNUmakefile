CXX = clang++
CXXFLAGS = -Wall -std=c++23 -Iinclude

SRCS = $(wildcard src/*.cpp)

OBJS = $(SRCS:.cpp=.o)

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f main src/*.o
