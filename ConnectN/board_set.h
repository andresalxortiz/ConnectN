#ifndef BOARD_H
    #define BOARD_H
    
    
    void setup(char*** board, int* turn, int num_of_rows, int num_of_cols);
    char** create_board();
    void show_board(char** board, int num_of_rows, int num_of_cols);
    void destroy_board(char*** board, int num_of_rows);
    
    
#endif