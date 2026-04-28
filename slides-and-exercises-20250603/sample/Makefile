PROGRAM = sample
OBJS = sample.o svg.o

CXX = g++
CFLAGS = -Wall -O2 -std=c++11
LFLAGS = -Wall -lm

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
