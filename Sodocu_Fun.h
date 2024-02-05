#ifndef SODOCU_FUN_H_
#define SODOCU_FUN_H_

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ANSI-color-codes.h"

#define N 9
#define minimum_num_of_clues 17
#define maximum_num_of_clues 77

 extern int row , coulmn ;
 extern int Board[N][N] ;
 extern int Solved_Board[N][N] ;

 int Num_of_clues;
 int Rest_of_empty_Clues;

/*to define error state*/
typedef enum Error
{
    OK,
    WRONG,
    INVALID,
    forbidden,

}Error;

typedef enum Bool
{
    FALSE,
    TRUE,

}Bool;

/******prototype******/
Error Suduko(int Board[N][N]);
void Suduko_print_pattern(int Board[N][N]);
Error Sudoku_check_Row_Col_Block(int r, int c, int Board[N][N], int num);
int Suduko_Generate_pattern(int Board[N][N], int Solved_Board[N][N]);

#endif /**/