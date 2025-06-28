CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra

TARGET := proxy_demo

SRCS := main.cpp
HEADS := Image.h BankAccount.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean

