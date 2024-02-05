
#include "Sodocu_Fun.h"
#include "ANSI-color-codes.h"

 int row , coulmn ;
 int Board[N][N] = {
    {6, 9, 7, 4, 3, 5, 2, 1, 8},
    {8, 5, 1, 7, 9, 2, 4, 6, 3},
    {4, 2, 3, 8, 1, 6, 5, 7, 9},
    {1, 7, 6, 5, 8, 4, 3, 9, 2},
    {9, 3, 4, 1, 2, 7, 8, 5, 6},
    {5, 8, 2, 3, 6, 9, 7, 4, 1},
    {7, 6, 9, 2, 4, 3, 1, 8, 5},
    {2, 4, 8, 9, 5, 1, 6, 3, 7},
    {3, 1, 5, 6, 7, 8, 9, 2, 4}};
 int Solved_Board[N][N] = {
   {6, 9, 7, 4, 3, 5, 2, 1, 8},
    {8, 5, 1, 7, 9, 2, 4, 6, 3},
    {4, 2, 3, 8, 1, 6, 5, 7, 9},
    {1, 7, 6, 5, 8, 4, 3, 9, 2},
    {9, 3, 4, 1, 2, 7, 8, 5, 6},
    {5, 8, 2, 3, 6, 9, 7, 4, 1},
    {7, 6, 9, 2, 4, 3, 1, 8, 5},
    {2, 4, 8, 9, 5, 1, 6, 3, 7},
    {3, 1, 5, 6, 7, 8, 9, 2, 4}};



/********implementations functions********/
Error Suduko(int Board[N][N])
{
    int num, row, col;
    Error error_Row_Col_Block = OK, error = OK;
    Suduko_print_pattern(Board);
    printf(BLU "Enter Row Num: " reset);
    scanf("%d", &row);
    if (row < 0 || row > N)
    {
        error = forbidden;
        return error;
    }

    printf(BLU "Enter Col Num: " reset);
    scanf("%d", &col);
    if (col < 0 || col > N)
    {
        error = forbidden;
        return error;
    }
    if (Board[row][col] != 0)
    {
        error = INVALID;
        return error;   
    }
    printf(WHT "Enter Value: "reset);
    scanf("%d", &num);
    error_Row_Col_Block = Sudoku_check_Row_Col_Block(row, col, Board, num);
    if ((error_Row_Col_Block == OK) && (num == Solved_Board[row][col]))
    {
        Board[row][col] = num;
        Rest_of_empty_Clues--;
    }
    else
    {
        error = WRONG;
    }
    return error;
}
void Suduko_print_pattern(int Board[N][N])
{
    printf(BLUHB " R/C|  0  1  2 |  3  4  5 |  6  7  8 |" reset);
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || i == 3 || i == 6)
        {
            printf(CYN "____|________________________________|\n" reset);
        }
        for (int j = 0; j < N; j++)
        {
            if (j == 0)
            {
                printf(BLUHB " %d " reset, i);
            }

            if (j == 0 || j == 3 || j == 6)
            {
                printf(CYN " |" reset);
            }

            {
                if (Board[i][j] == 0)
                {
                    //printf("\x1b[35m");
                    printf(MAG "%3c" reset, 'X');
                    //printf("\x1b[0m");
                }
                else
                {

                    printf("%3d", Board[i][j]);
                    printf("\a");
                }
            }
        }
        printf(CYN " |" reset);
        printf("\n");
    }
    printf(CYN "____|________________________________|\n" reset);
}

Error Sudoku_check_Row_Col_Block(int r, int c, int Board[N][N], int num)
{
    Error error = OK;
    int StartRow = r / 3 * 3;
    int StartCol = c / 3 * 3;
    int Row_bound = StartRow + 3;
    int Col_bound = StartCol + 3;
    for (int i = StartRow; i < Row_bound; i++)
    {
        for (int j = StartCol; j < Col_bound; j++)
        {
            if (Board[i][j] == num)
            {
                error = WRONG;
                break;
            }
        }
        if (error == WRONG)
        {
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (Board[i][c] == num)
        {
            error = WRONG;
            break;
        }
    }

    for (int j = 0; j < N; j++)
    {
        if (Board[r][j] == num)
        {
            error = WRONG;
            break;
        }
    }

    return error;
}

int Suduko_Generate_pattern(int Board[N][N], int Solved_Board[N][N])
{
    int clues_num;
    srand(time(NULL));
    do
    {
        clues_num = (rand() % (maximum_num_of_clues - minimum_num_of_clues + 1));
    } while (clues_num < minimum_num_of_clues);

    //printf("clues num %d\n", clues_num);

    // initializing board array with zeros
    for (int i = 0; i < clues_num; i++)
    {
        Board[rand() % N][rand() % N] = 0;
    }
    return clues_num;
}
