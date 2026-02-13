CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = pacman

.PHONY: all clean

all: $(TARGET)

$(TARGET): pacman.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) pacman.cpp

clean:
	rm -f $(TARGET)
