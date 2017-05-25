CC=gcc
CFLAGS=-Wall -std=c99 -g

ticTacToe: ticTacToe.o

clean:
	rm -f ticTacToe.o ticTacToe
