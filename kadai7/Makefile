PROGRAM = main
OBJS = population.o main.o

CXX = g++
CFLAGS = -Wall -g -O0 -std=c++11
LFLAGS = -Wall -g -O0 -lm

.PHONY: all
all: clean $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(LFLAGS) -o $(PROGRAM) $^

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)
