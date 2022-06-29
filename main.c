
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

int main(int argc, char const *argv[]) {
    /* code */

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



    return 0;
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
