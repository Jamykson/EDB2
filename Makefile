EXEC = comparador

CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2


SRCS = main.cpp algoritmos_ordenação.cpp gerador_vetores.cpp
HDRS = algoritmos_ordenação.h gerador_vetores.h


all: $(EXEC)

$(EXEC): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

clean:
	rm -f $(EXEC)
