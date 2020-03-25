#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#include "valid_input.h"
#include "board_set.h"


void get_play(char** board, int* rows, int* cols, int num_of_cols){
    
    int numArgsRead;
    
    do{
        
        printf("Enter a column between 0 and %d to play in: ", num_of_cols - 1);
        
        numArgsRead = scanf("%d", cols);
        
    }while(!play_is_valid(numArgsRead, 1 , board, *rows, *cols, num_of_cols));
    
}



bool play_is_valid(int numArgsRead, int numArgsNeed, char** board, int rows, int cols, int num_of_cols){
    
    return valid_format(numArgsRead, numArgsNeed) && moveConstraints(board, rows, cols, num_of_cols);
    
}



bool valid_format(int numArgsRead, int numArgsNeed){
    
    bool isValid = true;
    char lastChar;
    
    if(numArgsRead != numArgsNeed){
        
        isValid = false;
        
    }
    
    
    do{
        
        scanf("%c", &lastChar);
        
        if(!isspace(lastChar)){
            isValid = false;
        }
        
    }while(lastChar != '\n');
    
    
    return isValid;
    
}



bool moveConstraints(char** board, int rows, int cols, int num_of_cols){
    
    return place_piece(cols, num_of_cols) && is_blank_space(board[rows][cols]);
    
}



bool place_piece(int cols, int num_of_cols){
    
    return cols >= 0 && cols < num_of_cols;
    
}



bool is_blank_space(char piece){
    
    return piece == '*';
    
}


void player_turn(char** board, int rows, int cols, int turn, int num_of_rows, int num_of_cols){
    
    int i;
    char pieces[] = {'X', 'O', '\0'};
    
    
    for(i = 1; i <= num_of_rows; ++i){

        if(board[num_of_rows - i][cols] == '*'){
            
            board[num_of_rows - i][cols] = pieces[turn];
            break;
            
        }
        
        else{
            
            continue;
            
        }
    }
}




void next_turn(int* turn){
    
    *turn = (*turn + 1) % 2;
    
}