#ifndef _LIFE_H
#define _LIFE_H

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <unistd.h>

/**
 *  enum for cell state : 0-dead, 1-alive
 **/
typedef enum{DEAD,ALIVE} cellState;

/**
 * Structure for the game board:
 * nrow - number of rows in the board
 * ncol- number of columns in the board
 * gameGrid - 2D matrix as a representative of game board
 **/

typedef struct board{
    int nrow;
    int ncol;
    int** gameGrid;
}Board;


/**
 *  @brief creates 2D array and returns the pointer to it
 *
 *  @param nrow: number of rows, ncol: number of columns
 *
 *  @return returns: pointer to the 2D integer array
 **/
int ** create_2D_array(int nrow, int ncol);
void fill_matrix(int n, int** matrix, int nrow, int ncol);
void print_matrix(int** matrix, int nrow, int ncol);





#endif