CXX=gcc
BIN=recursive_parser
INC=headers

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.c)

all: flex fin

fin: lex.yy.c parser.c main.c tokens.c simbolo.c tipo.c lista.c pila.c
	$(CXX) -I$(INC) -g -o $(BIN) $^ 

%.o: %.c
	$(CXX) $@ -c $<

.PHONY: clean
clean :
	rm -f $(BIN) *.o lex.yy.c

.PHONY: flex
flex:
	flex lexer.lex
