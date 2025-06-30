CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra

TARGET := component_demo

SRCS := main.cpp
HEADS := Component.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean

