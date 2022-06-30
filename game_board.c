#include "game_board.h"

bool board_check_win(int board[3][3], char symbol) {
    // Check horizontal and vertical wins 
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }

        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }

    // Check diagnoal wins

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }


    return false;

}

void board_print(int board[3][3]) {
    printf("    0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            
            printf("| %c ", board[i][j]);
        }
        printf("| \n");

    }
    
    
}

void board_clear(int board[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = SPACE;
        }

    }

}