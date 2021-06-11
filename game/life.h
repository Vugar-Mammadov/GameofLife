/** @file life.h
 *  @brief Function prototypes for the game of life
 *
 *  This contains the prototypes and the macros for the game logic and 
 *  board drawings.
 *
 *  @author Shamil Shukurov
 */


#ifndef _LIFE_H
#define _LIFE_H

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <unistd.h>
#include<time.h>


/** @def NROW_DEF
 * @brief Default number of rows
 * @def NCOL_DEF
 * @brief Default number of columns
 * @def MAX_ITER_DEF
 * @brief Default number of maximum iterations
 * @def TIMEOUT_DEF
 * @brief Default number of timeout between two states of boards
 * @def MIN_NB_ROWS_COLS
 * @brief Minimum width and height
 * **/
#define NROW_DEF 12
#define NCOL_DEF 12
#define MAX_ITER_DEF 100
#define TIMEOUT_DEF 1
#define MIN_NB_ROWS_COLS 4

/** @def MAGB
 * @brief Magenta Background
 * @def CLR_SCR
 * @brief Clear Screen
 * @def reset
 * @brief Reset
 * **/
#define MAGB "\e[45m"
#define CLR_SCR "\x1b[H\x1b[2J"
#define reset "\033[0m"




/**
 *  @enum cellState
 *  @brief Enumeration for cell state
 *  @param DEAD:0
 *  @param ALIVE:1
 **/
typedef enum{DEAD,ALIVE} cellState;

/**
 * @struct board
 * @brief Structure for the game board
 * 
 * @typedef Board
 * @brief Structure for the game board
 **/

typedef struct board{
    int nrow;    /*!< nrow - number of rows in the board */
    int ncol;   /*!< ncol- number of columns in the board */
    int** gameGrid; /*!< gameGrid - 2D matrix as a representative of game board */
}Board;


/**
 *  @brief Creates 2D array and returns the pointer to it
 *
 *  @param nrow: number of rows
 *  @param ncol: number of columns
 *
 *  @return returns: pointer to the 2D integer array
 **/
int ** create_2D_array(int nrow, int ncol);

/**
 * @brief Fills given matrix with the given value
 * @param n : value which will be filled
 * @param matrix : 2D matrix
 * @param nrow: number of rows in the matrix
 * @param ncol: number of columns in the matrix
 * @return void
 **/
void fill_matrix(int n, int** matrix, int nrow, int ncol);

/**
 * @brief Fills given matrix with 0 and 1's randomly
 * @param matrix : 2D matrix
 * @param nrow: number of rows in the matrix
 * @param ncol: number of columns in the matrix
 * @return void
 **/
void fill_matrix_random(int** matrix, int nrow, int ncol);


/**
 * @brief Initialize new game board with the specified width and height
 * @param nrow: number of rows 
 * @param ncol: number of cols
 * @return new Board
 * 
 **/
Board* initBoard(int nrow, int ncol);

/**
 * @brief Prints the board to the console
 * @param Board* b
 * @return void
 * 
 **/
void print_board(Board* b);


/**
 * @brief Fills the given board either randomly or with DEAD cells
 * @param b: Board to fill
 * @param fillRandom: boolean, if true Board will be filled randomly
 * @return void
 **/

void fillBoard(Board* b,bool fillRandom);



/**
 * @brief For a given cell returns the number of alive neighbours
 * 
 * @param row: row number of the cell
 * @param col: col number of the cell
 * @param b: Board in which is the cell in
 * @return number of alive neighbours of the cells, -1 in if b_t is NULL
 **/
int aliveNeighboursCount(int row, int col, Board* b);

/**
 * @brief Returns a next state (state in t+1) of a given cell
 * 
 * @param row: row number of the cell
 * @param col: col number of the cell
 * @param b_t: Board which is the cell in
 * @return next state of the cell: DEAD or ALIVE, -1 in if b_t is NULL
 **/
int nextState(int row, int col, Board* b_t );

/**
 * @brief Reads the current board and returns a board for time t+1
 * 
 * @param board_t : Board with the current states of cells
 * @return : new board which contains the next states of all the cells, if board_t is NULL returns NULL
 * 
 **/
Board* board_t1(Board* board_t);

/**
 * @brief Checks if all of the cells of a board is dead
 * @param Board* b
 * @return true if all the cells of the given board is dead, false otherwise
 **/
bool deadBoard(Board* b);

/**
 * @brief Checks if the next state of board is the same as previous
 * @param Board* b1
 * @param Board* b2
 * @return true if all the cells of the board b1 is same as b2, false otherwise
 **/
bool isSame(Board* b1, Board* b2);

/**
 * @brief Deletes the board and frees the memory
 * @param b: Board which we wanted to delete
 * @return void
 **/
void deleteBoard(Board* b);



#endif