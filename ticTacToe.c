/**
 * @file ticTacToe.c
 * A simple tic-tac-toe game
 * 
 * @author Justin Schwab (github.com/jgschwab)
 */

#include "ticTacToe.h"


int main( void ){
  system("clear");
  Grid gridExample = {
  {"\u2554","\u2550","\u2564","\u2550","\u2564","\u2550","\u2557"},
  {"\u2551","Q","\u2502","W","\u2502","E","\u2551"},
  {"\u255F","\u2500","\u253C","\u2500","\u253C","\u2500","\u2562"},
  {"\u2551","A","\u2502","S","\u2502","D","\u2551"},
  {"\u255F","\u2500","\u253C","\u2500","\u253C","\u2500","\u2562"},
  {"\u2551","Z","\u2502","X","\u2502","C","\u2551"},
  {"\u255A","\u2550","\u2567","\u2550","\u2567","\u2550","\u255D"} };
  
  Grid grid;
  memcpy(grid, gridExample, sizeof(gridExample));
  clearGrid(&grid);
    
  printf("\e[33m"
         "The keys Q,W,E,A,S,D,Z,X,C correspond to the cells of the game grid."
         "\nUse the corresponding key to select a cell when it's your turn."
         "\n\e[1mKey Map:\e[0m\n");
  
  int alt = 2;
  int xGamesWon = 0;
  int oGamesWon = 0;
  
  // gameStatus is 0 if nobody has won, 1 if player 1 has won,
  // and 2 if player 2 has won.
  int gameStatus = 0;
  bool playAgain = true;
  
  while(playAgain){
    while(!gameStatus){
      printGrid(&gridExample, false);
      printGrid(&grid, true);
      printf("Player %d, place an %c: ", alt % 2 + 1, alt % 2 == 0 ? 'X' : 'O');
      char ch[100] = "";
      scanf("%s", ch);
      while(strlen(ch) != 1 || !strpbrk("qweasdzxc", ch) ){
        printf("Not a valid key. Try again: ");
        scanf("%s", ch);
      }
      
      
      switch(ch[0]){
        case 'q':
          if(strcmp(grid[1][1], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[1][1] = alt % 2 == 0 ? "X" : "O";
          break;
        case 'w':
          if(strcmp(grid[1][3], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[1][3] = alt % 2 == 0 ? "X" : "O";
          break;
        case 'e':
          if(strcmp(grid[1][5], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[1][5] = alt % 2 == 0 ? "X" : "O";
          break;
        case 'a':
          if(strcmp(grid[3][1], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[3][1] = alt % 2 == 0 ? "X" : "O";
          break;
        case 's':
          if(strcmp(grid[3][3], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[3][3] = alt % 2 == 0 ? "X" : "O";
          break;
        case 'd':
          if(strcmp(grid[3][5], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[3][5] = alt % 2 == 0 ? "X" : "O";
          break;
        case 'z':
          if(strcmp(grid[5][1], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[5][1] = alt % 2 == 0 ? "X" : "O";
          break;
        case 'x':
          if(strcmp(grid[5][3], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[5][3] = alt % 2 == 0 ? "X" : "O";
          break;
        case 'c':
          if(strcmp(grid[5][5], " ")){
            system("clear");
            printf("That cell is already taken\n");
            continue;
          }
          grid[5][5] = alt % 2 == 0 ? "X" : "O";
          break;
        default:
          printf("\e[91mERROR::grid switch\e[0m\n");
      }
      alt++;
      gameStatus = checkForWin(&grid);
      system("clear");
    }
    
    gameStatus == 1 ? xGamesWon++ : oGamesWon++;
    gameStatus = 0;
    clearGrid(&grid);
    system("clear");
    //display stats
    printf("\e[31m                Win Ratio:\e[0m\n");
    printf("\e[33m Player 1 (X's)            \e[36mPlayer 2 (O's)\n");
    printf("\e[0m[\e[33m");
    int total = xGamesWon + oGamesWon;
    for(int i = 0; i < xGamesWon * 1.0 / total * 40; i++){
      printf("-");
    }
    printf("\e[36m");
    for(int i = 0; i < oGamesWon * 1.0 / total * 40; i++){
      printf("-");
    }
    printf("\e[0m]\n");
    
    
    char in[100] = "x";
    printf("play again? (y/n): ");
    scanf("%s", in);
    while(tolower(in[0]) != 'y' && tolower(in[0]) != 'n'){
      printf("I didn't understand that.\nplay again? (y/n): ");
      scanf("%s", in);
    }
    if(tolower(in[0]) == 'n'){
      playAgain = false;
      system("clear");
    }  
  }
}

void printGrid( Grid * grid, bool bright ){
  printf(bright ? "\e[0m" : "\e[90m");
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      printf( "%s", (*grid)[i][j] ); 
    }
    printf("\n");
  }
  printf("\e[0m");
}

int checkForWin( Grid * grid ){
  int xCounter = 0;
  int oCounter = 0;
  //check rows
  for(int i = 1; i < 6; i += 2){
    for(int j = 1; j < 6; j += 2){
      if(!strcmp((*grid)[i][j], "X"))
        xCounter++;
      if(!strcmp((*grid)[i][j], "O"))
        oCounter++;
    }
    if(xCounter == 3)
      return 1;
    if(oCounter == 3)
      return 2;
    xCounter = 0;
    oCounter = 0;
  }
  
  //check columns
  for(int i = 1; i < 6; i += 2){
    for(int j = 1; j < 6; j += 2){
      if(!strcmp((*grid)[j][i], "X"))
        xCounter++;
      if(!strcmp((*grid)[j][i], "O"))
        oCounter++;
    }
    if(xCounter == 3)
      return 1;
    if(oCounter == 3)
      return 2;
    xCounter = 0;
    oCounter = 0;
  }
  //check diagonals
  for(int i = 1; i < 6; i += 2){
    if(!strcmp((*grid)[i][i], "X"))
      xCounter++;
    if(!strcmp((*grid)[i][i], "O"))
      oCounter++;
  }
  if(xCounter == 3)
    return 1;
  if(oCounter == 3)
    return 2;
  xCounter = 0;
  oCounter = 0;
  
  for(int i = 1; i < 6; i += 2){
    if(!strcmp((*grid)[i][6 - i], "X"))
      xCounter++;
    if(!strcmp((*grid)[i][6 - i], "O"))
      oCounter++;
  }
  if(xCounter == 3)
    return 1;
  if(oCounter == 3)
    return 2;
    
  return 0;
}

void clearGrid(Grid * grid){
  for(int i = 1; i < 6; i += 2){
    for(int j = 1; j < 6; j += 2){
      (*grid)[i][j] = " ";
    }
  }
}
