CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra

TARGET := flyweight_demo

SRCS := main.cpp
HEADS := Flyweight.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean

