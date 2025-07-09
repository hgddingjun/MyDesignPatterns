CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra

TARGET := command_demo

SRCS := main.cpp
HEADS := Command.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean

