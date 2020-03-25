#include <stdio.h>
#include <stdlib.h>


#include "board_set.h"
#include "valid_input.h"


void show_board(char** board, int num_of_rows, int num_of_cols) {
    
    int rows, cols;
    int total_rows = num_of_rows - 1;


    for(rows = 0; rows < num_of_rows; ++rows){
        printf("%d ", total_rows);

        for(cols = 0; cols < num_of_cols; ++cols){
            
            printf("%c ", board[rows][cols]);
            
        }

        printf("\n");
        --total_rows;
    }


    printf("  ");
    for(cols = 0; cols < num_of_cols; ++cols){
        
        printf("%d ", cols);
        
    }
    printf("\n");
    
}



char** create_board(int num_of_rows, int num_of_cols){

    char** board = (char**)malloc(num_of_rows * sizeof(char*));
    int i, j;
    
    
    for(i = 0; i < num_of_rows; ++i){
        
        board[i] = (char*)malloc(num_of_cols * sizeof(char));
        
    }
    
    for(i = 0; i < num_of_rows; ++i){
        for(j = 0; j < num_of_cols; ++j){
            
            board[i][j] = '*';
            
        }
    }
    
    
    return board;
}



void setup(char*** board, int* turn, int num_of_rows, int num_of_cols){
    
    *board = create_board(num_of_rows, num_of_cols);
    
    *turn = 0;
    
}



void destroy_board(char*** board, int num_of_rows){
    
    int rows;
    
    for(rows = 0; rows < num_of_rows; ++rows){
        
        free((*board)[rows]);
        
    }
    
    free(*board);
    
    *board = NULL;
    
}

