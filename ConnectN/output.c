#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#include "output.h"
#include "valid_input.h"


bool game_over(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    return game_won(board, num_of_rows, num_of_cols, pieces_in_a_row) || game_tied(board, num_of_rows, num_of_cols, pieces_in_a_row);
    
}



bool game_won(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    return row_win(board, num_of_rows, num_of_cols, pieces_in_a_row) || col_win(board, num_of_rows, num_of_cols, pieces_in_a_row) || diag_win(board, num_of_rows, num_of_cols, pieces_in_a_row);
}



bool row_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    int rows;
    
    for(rows = 0; rows < num_of_rows; ++rows){
        
        if(check_row(board[rows], 'X', num_of_cols, pieces_in_a_row) || check_row(board[rows], 'O', num_of_cols, pieces_in_a_row)){
            
            return true;
            
        }
    }
    
    
    return false;
}

bool check_row(char* ar, char used_piece, int num_of_cols, int pieces_in_a_row){
    
    int i;
    int count;
    
    for(i = 0; i < num_of_cols; ++i){
        for(count = 0; count < num_of_cols; ++count){
            
            if(count == pieces_in_a_row){
                return true;
            }
            
            if(ar[i + count] != used_piece){
                break;
            }
            
            else{
                continue;
            }
        }
    }
    
    
    return false;
}



bool col_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    int rows;
    int count;
    int cols;
    int first_piece;
    
    for(rows = 0; rows < num_of_rows; ++rows){
        for(cols = 0; cols < num_of_cols; ++cols){
            first_piece = board[rows][cols];
        
        
            if(first_piece == '*'){
                continue;
            }
        
            else{
                for(count = 0; count < num_of_rows; ++count){
                    if(count == pieces_in_a_row){
                        return true;
                    }
                    
                    if(board[rows - count][cols] != first_piece){
                        break;
                    }
                }
            }
            
        }
    }
    
    
    return false;
}


bool diag_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    return left_diag_win(board, num_of_rows, num_of_cols, pieces_in_a_row) || right_diag_win(board, num_of_rows, num_of_cols, pieces_in_a_row);
    
}



bool left_diag_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    
    int i, j, count;
    char first_piece;
    

    for(i = num_of_rows - 1; i >= 0; --i){
        for(j = num_of_cols - 1; j >= 0; --j){
            first_piece = board[i][j];
        
            if(first_piece == '*'){
                continue;
            }
            
            else{
                for(count = 0; count < num_of_rows; ++count){
                    
                    if(count == pieces_in_a_row){
                        return true;
                    }
                
                    if(board[i - count][j - count] != first_piece){
                        break;
                    }   
                    
                    else{
                        continue;
                    }
                }
                
            }        
                    
        }
    }
    
    
    return false;
}



bool right_diag_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    int i, j, count;
    char first_piece;
    

    for(i = num_of_rows - 1; i >= 0; --i){
        for(j = num_of_cols - 1; j >= 0; --j){
            first_piece = board[i][j];
        
            if(first_piece == '*'){
                continue;
            }
            
            else{
                for(count = 0; count < num_of_rows; ++count){
        
                
                    if(count == pieces_in_a_row){
                        return true;
                    }
                    
                    if(board[i - count][j + count] != first_piece){
                        break;
                    }   
                    
                    else{
                        continue;
                    }
                    
                }
            }        
                    
        }
    }
    
    return false;
    
}



bool game_tied(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    
    int rows, cols;
    
    for(rows = 0; rows < num_of_rows; ++rows) {
        for(cols = 0; cols < num_of_cols; ++cols) {
            
            if(board[rows][cols] == '*'){
                
                return false;
                
            }
        }
    }
    
    
    return !game_won(board, num_of_rows, num_of_cols, pieces_in_a_row);
    
}



void game_winner(char** board, int turn, int num_of_rows, int num_of_cols, int pieces_in_a_row){
    if(game_won(board, num_of_rows, num_of_cols, pieces_in_a_row)){
        
        if(turn == 1){
            printf("Player 1 Won!\n");
        }
        
        else{
            printf("Player 2 Won!\n");
        }
    }

    else{
        printf("Tie game!\n");
    }
    
}