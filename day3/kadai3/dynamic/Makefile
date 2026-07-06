PROGRAM = main
STATIC_PROGRAM = main_static
STATIC_LIB = libMessage.a
OBJS = Message.o main.o

CXX = g++
CFLAGS = -Wall -g -O0 -std=c++11
LFLAGS = -Wall -g -O0 -lm

.PHONY: all
all: clean $(PROGRAM) $(STATIC_PROGRAM)

# 従来の実行ファイルの生成
$(PROGRAM): $(OBJS)
	$(CXX) $(LFLAGS) -o $(PROGRAM) $^

# 1. 静的リンクライブラリの生成
$(STATIC_LIB): Message.o
	ar rcs $@ $<

# 2. 静的リンクライブラリをリンクしたプログラムの生成
$(STATIC_PROGRAM): main.o $(STATIC_LIB)
	$(CXX) $(LFLAGS) -o $@ main.o -L. -lMessage

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(STATIC_PROGRAM) $(STATIC_LIB) $(OBJS)