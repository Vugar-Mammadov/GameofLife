/** @file board_drawer.h
 *  @brief Function prototypes for the main loop of the game
 *
 *  @author Shamil Shukurov
 */

#ifndef _BOARD_DRAWER_H
#define _BOARD_DRAWER_H


#include "life.h"


/**
 * @brief Game loop
 * It is a recursive function : in every call of this function board will be printed and the next 
 * state of the board is calculated. 
 * Then the function calls itself with the new state and with 1 less iterations.
 * @param maxIter : maximum number of iterations. After maxIter time game will stop automatically
 * @return void
 * 
 **/
void game(Board* b_t, int maxIter);





#endif