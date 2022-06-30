#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "ai_player.h"
#include "game_board.h"



/* Function prototypes */
void board_print(int board[3][3]);
void print_title();
void get_move(char symbol, int board[3][3]);
bool game_turn(char current_player, int board[3][3]);
void switch_player(char* current_player);


int main(int argc, char const *argv[]) {
    /* code */

    bool is_running = false;
    static int board[3][3] = {
        {X,X,X},
        {SPACE, SPACE, SPACE},
        {O,O,O}
    };
    
    print_title();
    board_print(board);
   
    

    char input;

    
    do {
        printf("\nEnter 'S' to begin... ");
        scanf(" %c", &input);
    }
    while (input != 83);
    is_running = true;
    char current_player = X;
    board_clear(board);
    board_print(board);
    // Game Loop

    while (is_running) {
        

        is_running = game_turn(current_player, board);
        switch_player(&current_player);
        
    }

    return 0;
}

void switch_player(char* current_player) {
    if(*current_player == X) {
        *current_player = O;
    }
    else {
        *current_player = X;
    }
}

bool game_turn(char current_player, int board[3][3]) {

        // Get player 1 input
        get_move(current_player, board);
        board_print(board);
        // Process move
       
        // Check win 
        if (board_check_win(board, current_player)) {
            printf("\nPlayer %c Wins!", current_player);
            return false;
        }
        else if (board_num_free_spaces(board) == 0) {
            printf("\nDRAW!");
            return false;
        }

        printf("\nRemaining spaces %d", board_num_free_spaces(board));

        return true;       

}

void get_move(char symbol, int board[3][3]) {

    int x, y;

    printf("\nPlayer %c: Enter the coordinates of your next move\n", symbol);

    while (true) {
        scanf(" %d %d", &x, &y);
        if (x > 2 || x < 0 || y > 2 ||  x < 0) {
            printf("\nInvalid coordinates, out of bounds.\n");
        }
        else if (board[x][y] != SPACE) {
            printf("\nInvalid coordinates, space already occupied.\n");
        }
        else {
            break;
        }    
    }

    board[x][y] = symbol;

}



void print_title() {
    printf("------------------------------------------------\n");
    printf("Welcome to TicTacToe: The C Edition\n");
    printf("------------------------------------------------\n");
}




