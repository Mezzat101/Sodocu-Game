
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Sodocu_Fun.h"

int main()
{
  system("cls");
    Error e;
    // Suduko_Generate_pattern(Board);
    Num_of_clues = Suduko_Generate_pattern(Board, Solved_Board);
    Rest_of_empty_Clues = Num_of_clues;
    while (1)
    {
        e = Suduko(Board);
        if (e == OK)
        {

            system("cls");
            //printf("\x1b[32m");
            printf(GRNB "Well Done" reset);
            printf("\n");
            //printf("\x1b[0m");
        }
        else if (e == WRONG)
        {
            system("cls");
            //printf("\x1b[31m");
            printf(REDB "Wrong Input" reset);
            printf("\n");
            //printf("\x1b[0m");
        }
        else if (e == INVALID)
        {
            system("cls");
            //printf("\x1b[31m");
            printf(REDB "Invalid Place" reset);
            printf("\n");
            //printf("\x1b[0m");
        }
        else if (e == forbidden)
        {
            system("cls");
            //printf("\x1b[31m");
            printf(REDB "Forbidden Input" reset);
            printf("\n");
            //printf("\x1b[0m");
        }
        else
        {
            system("cls");
            //printf("\x1b[31m");
            printf(REDB "Error" reset);
            printf("\n");
            //printf("\x1b[0m");
            break;
        }


        if (Rest_of_empty_Clues == 0)
        {
            //printf("\x1b[32m");
            printf(GRNB "Congratulations Suduko Solved Successfully" reset);
            printf("\n");
            //printf("\x1b[0m");

            break;
        }
    }
    return 0;
}