#include <stdio.h>
#include <stdlib.h>


#include "board_set.h"
#include "valid_input.h"
#include "output.h"


void play_connect_n(int num_of_rows, int num_of_cols, int pieces_in_a_row) {
    
    char** board = NULL;
    int turn;
    int rows, cols;
    
    
    setup(&board, &turn, num_of_rows, num_of_cols);
    
    while(!game_over(board, num_of_rows, num_of_cols, pieces_in_a_row)) {
        
        show_board(board, num_of_rows, num_of_cols);
        
        get_play(board, &rows, &cols, num_of_cols);
        
        player_turn(board, rows, cols, turn, num_of_rows, num_of_cols);
        
        next_turn(&turn);
    }
    
    
    show_board(board, num_of_rows, num_of_cols);
    
    game_winner(board, turn, num_of_rows, num_of_cols, pieces_in_a_row);
    
    destroy_board(&board, num_of_rows);
    
}


int validArgc(int argc) {

    
    if(argc < 4){
        
        printf("Not enough arguments entered\n");
        
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        
        exit(0);
    }
    
    else if(argc > 4){
        
        printf("Too many arguments entered\n");
        
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        
        exit(0);
    }
    
    return 0;
}


int main(int argc, char* argv[]) {
    
    int num_of_rows, num_of_cols, pieces_in_a_row;
    
    validArgc(argc);
    
    num_of_rows = atoi(argv[1]);
    
    num_of_cols = atoi(argv[2]);
    
    pieces_in_a_row = atoi(argv[3]);
    
    play_connect_n(num_of_rows, num_of_cols, pieces_in_a_row);
    
    return 0;
}