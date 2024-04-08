CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = basico.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = basico

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
