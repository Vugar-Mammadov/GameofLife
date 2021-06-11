/** @file board_drawer.c
 *  @brief Functions for the main loop of the game
 *
 *  @author Shamil Shukurov
 */

#include "board_drawer.h"
#include "life.h"

void game(Board* b_t, int maxIter){
    if(b_t==NULL) return;
    print_board(b_t);
    if(deadBoard(b_t) || maxIter==0) return;
    Board* b_t1 = board_t1(b_t);
    // If it is still life, there is no meaning continue to iterate
    if(isSame(b_t,b_t1)){
        deleteBoard(b_t);
        return;
    }
    deleteBoard(b_t);
    sleep(1);
    return game(b_t1, maxIter-1); 
}