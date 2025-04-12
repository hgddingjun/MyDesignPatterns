CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra

TARGET := factory_method_demo

SRCS := main.cpp
HEADS := FactoryMethod.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean

