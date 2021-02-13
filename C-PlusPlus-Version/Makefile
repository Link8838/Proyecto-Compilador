CXX=g++
BIN=recursive_parser
INC=headers

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.c)

all: flex fin

fin: tokens.h lex.yy.c main.cpp simbolo.h tipo.h parser.cpp parser.h returntipes.h
	$(CXX) -I$(INC) -g -o $(BIN) $^ 

%.o: %.c
	$(CXX) $@ -c $<

.PHONY: clean
clean :
	rm -f $(BIN) *.o lex.yy.c

.PHONY: flex
flex:
	flex lexer.lex
