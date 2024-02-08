# Sudoku-Game
## Vedio to show How play this Game

<video controls src="Sodocu Game-1.mp4" title=""></video>

## Sudoku Game Documentation
This documentation provides an overview and explanation of the Sudoku game project implemented in C programming language. The project consists of three files:

* *Sodocu_Fun*.h: 
   This header file contains function declarations, constants, and structure definitions necessary for the Sudoku game.

* *Sodocu_Fun.c*: This source file contains the implementations of functions declared in Sodocu_Fun.h. These functions are responsible for various functionalities of the Sudoku game, such as generating the Sudoku pattern, checking the validity of user input, and solving the Sudoku puzzle.

* *main.c*: This source file contains the main function that drives the execution of the Sudoku game. It handles user input, displays the Sudoku board, and checks for game completion.

### 1. Sodocu_Fun.h

* Header Guards: The #ifndef, #define, and #endif directives are used to prevent multiple inclusions of the header file.

* Include Directives: Includes necessary standard C libraries (stdio.h, conio.h, stdlib.h, time.h) and a custom header file (ANSI-color-codes.h).

* Constants: Defines constants such as the size of the Sudoku grid (N), minimum and maximum number of clues, and enumeration for error and boolean states.

* External Declarations: Declares external variables row, column, Board[N][N], and Solved_Board[N][N].

* Function Prototypes: Declares function prototypes for functions implemented in Sodocu_Fun.c.

### 2. Sodocu_Fun.c

* Include Directives: Includes necessary standard C libraries (stdio.h, conio.h, stdlib.h) and the custom header file (Sodocu_Fun.h).

* Global Variables: Defines global variables row, column, Board[N][N], and Solved_Board[N][N].

* Function Definitions: Provides implementations of functions declared in Sodocu_Fun.h, including Suduko(), Suduko_print_pattern(), Sudoku_check_Row_Col_Block(), and Suduko_Generate_pattern().

### 3. main.c

* Include Directives: Includes necessary standard C libraries (stdio.h, conio.h, stdlib.h) and the custom header file (Sodocu_Fun.h).

* Main Function: The main() function serves as the entry point of the program. It initializes the Sudoku game, handles user input, and displays messages based on the game's progress.
* Functionality Overview:

    * The Sudoku game initializes with a pre-filled Sudoku grid.
    * The user is prompted to input row, column, and value for each move.
    * The game checks if the input is valid and updates the Sudoku grid accordingly.
    * If the Sudoku puzzle is solved successfully, a congratulations message is displayed.
    * The game continues until the puzzle is solved or an error occurs.


