CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pthread

TARGET := singleton_demo

SRCS := main.cpp
HEADS := Singleton.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean

