
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
bool check_win(int board[3][3], char symbol);


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
    char current_player = X;
    clear_board(board);
    print_board(board);

    // Game Loop
    while (is_running) {

        // Get player 1 input
        get_move(current_player, board);
        print_board(board);
        // Process move
       
        // Check win 
        if (check_win(board, current_player)) {
            is_running = false;
            printf("\nPlayer %c Wins!", current_player);
            break;

        }

        switch (current_player) {
        case X:
            current_player = O;
            break;
        case O:
            current_player = X;
            break;
        
        default:
            current_player = X;
            break;
        }

        // Repeat for player 2. 
        is_running = true;
    }

    return 0;
}

bool check_win(int board[3][3], char symbol) {
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

void get_move(char symbol, int board[3][3]) {

    int x, y;

    printf("\nPlayer %c: Enter the coordinates of your next move\n", symbol);

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
    printf("    0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            
            printf("| %c ", board[i][j]);
        }
        printf("| \n");

    }
    
    
}

void clear_board(int board[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = SPACE;
        }

    }

}
