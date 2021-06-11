
/** @file main.c
 *  @brief main function for the game
 *
 *  This file contains the main function for the game
 *
 *  @author Shamil Shukurov
 */

#include "life.h"
#include "board_drawer.h"

int main(int argc, char const *argv[])
{
    int nrow = NROW_DEF;
    int ncol =NCOL_DEF;
    int nb_iterations = MAX_ITER_DEF;

    if(argc != 4){
        printf("\nUsage : %s <width> <height> <nb_iterations>\n",argv[0]);
        printf("Default values will be used\n");
    }
    else{
        ncol = atoi(argv[1]);
        nrow = atoi(argv[2]);
        nb_iterations = atoi(argv[3]);
    }

    Board * board_t = initBoard(nrow,ncol);
    fillBoard(board_t,true);


    game(board_t,nb_iterations,TIMEOUT_DEF);

    return 0;
}