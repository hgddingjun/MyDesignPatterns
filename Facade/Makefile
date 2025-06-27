CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra

TARGET := facade_demo

SRCS := main.cpp
HEADS := Facade.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean

