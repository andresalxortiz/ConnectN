#ifndef OUTPUT_H
    #define OUTPUT_H
    
    #include <stdbool.h>
    
    bool game_over(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    bool game_won(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    bool row_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    bool check_row(char* ar, char used_piece, int num_of_cols, int pieces_in_a_row);
    bool col_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    bool diag_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    bool left_diag_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    bool right_diag_win(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    bool game_tied(char** board, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    void game_winner(char** board, int turn, int num_of_rows, int num_of_cols, int pieces_in_a_row);
    
    
#endif