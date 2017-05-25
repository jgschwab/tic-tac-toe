#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 7

typedef char * (Grid[SIZE][SIZE]);
void printGrid( Grid * grid, bool bright);
int checkForWin(Grid * grid);
void clearGrid(Grid * grid);
