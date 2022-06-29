
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SPACE 32
#define X 88
#define O 79

/* Function prototypes */
void print_board(int board[3][3]);
void print_title();
void get_move(char symbol, int board[3][3]);


int main(int argc, char const *argv[]) {
    /* code */

    bool is_running = false;
    static int board[3][3] = {
        {X,X,X},
        {SPACE, SPACE, SPACE},
        {O,O,O}
    };
    
    print_title();
    print_board(board);
    

    char input;

    
    do {
        printf("\nEnter 'S' to begin... ");
        scanf(" %c", &input);
    }
    while (input != 83);
    is_running = true;

    // Game Loop
    while (is_running) {

        // Get player 1 input
        get_move(X, board);
        print_board(board);
        // Process move
        
        // Check win 

        // Repeat for player 2. 
        is_running = true;
    }

    return 0;
}



void get_move(char symbol, int board[3][3]) {

    int x, y;

    printf("\nPlayer %c: Enter the coordinates of your next mode\n", symbol);

    while (true) {
        scanf(" %d %d", &x, &y);
        if (x > 2 || x < 0 || y > 2 ||  x < 0) {
            printf("\nInvalid coordinates, out of bounds. \n");
        }
        else if (board[x][y] != SPACE) {
            printf("\nInvalid coordinates, space already occupied. \n");
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

void print_board(int board[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("| \n");

    }
    
    
}
