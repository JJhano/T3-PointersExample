CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = basico.cpp main.cpp
EXEC1 = basico
EXEC2 = main

.PHONY: all clean

all: $(EXEC1) $(EXEC2)

# Compilación de basico.cpp
$(EXEC1): basico.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilación de main.cpp
$(EXEC2): main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXEC1) $(EXEC2)
