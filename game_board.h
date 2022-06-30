#ifndef game_board   /* Include guard */
#define game_board

#define SPACE 32
#define X 88
#define O 79

#include <stdbool.h>
#include <stdio.h>

bool board_check_win(int board[3][3], char symbol);
void board_print(int board[3][3]);
void board_clear(int board[3][3]);


#endif /* board */