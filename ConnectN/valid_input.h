#ifndef VALID_INPUT_H
    #define VALID_INPUT_H
    
    #include <stdbool.h>
    
    bool play_is_valid(int numArgsRead, int numArgsNeed, char** board, int rows, int cols, int num_of_cols);
    bool valid_format(int numArgsRead, int numArgsNeed);
    bool moveConstraints(char** board, int rows, int cols, int num_of_cols);
    bool place_piece(int cols, int num_of_cols);
    bool is_blank_space(char piece);
    void get_play(char** board, int* cols, int* rows, int num_of_cols);
    void player_turn(char** board, int rows, int cols, int turn, int num_of_rows, int num_of_cols);
    void next_turn(int* turn);
    

#endif