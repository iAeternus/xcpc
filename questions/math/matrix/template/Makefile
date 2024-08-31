CXX=g++
CXXFLAGS=-std=c++2a -Wall -Wextra -pedantic

TARGET=test1

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	del $(OBJS) $(TARGET).exe

.PHONY: all clean