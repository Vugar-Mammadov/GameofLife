
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
        printf("Default values will be used...\n");
    }
    else{
        ncol = atoi(argv[1]);
        nrow = atoi(argv[2]);
        nb_iterations = atoi(argv[3]);

        if(ncol<MIN_NB_ROWS_COLS){
            printf("Too small value for the number of columns,default value will be used\n");
        } 
        if(nrow<MIN_NB_ROWS_COLS){
            printf("Too small value for the number of rows, default value will be used\n");
        } 
    }

    int version = 1;
    bool isCircular = false;
    printf("1.Clipped\n2.Circular\nChoose version:");
    scanf("%d",&version);
    if(version==2){
        isCircular=true;
    }

    Board * board_t = initBoard(nrow,ncol);
    fillBoard(board_t,true);
    // Glider
    // board_t->gameGrid[1][2] = ALIVE;
    // board_t->gameGrid[2][3] = ALIVE;
    // board_t->gameGrid[3][3] = ALIVE;
    // board_t->gameGrid[3][2] = ALIVE;
    // board_t->gameGrid[3][1] = ALIVE;

    // Block -Still life example
    // board_t->gameGrid[1][1] = ALIVE;
    // board_t->gameGrid[1][2] = ALIVE;
    // board_t->gameGrid[2][1] = ALIVE;
    // board_t->gameGrid[2][2] = ALIVE;

    // Beacon
    // board_t->gameGrid[1][1] = ALIVE;
    // board_t->gameGrid[1][2] = ALIVE;
    // board_t->gameGrid[2][1] = ALIVE;
    // board_t->gameGrid[2][2] = ALIVE;
    // board_t->gameGrid[3][3] = ALIVE;
    // board_t->gameGrid[3][4] = ALIVE;
    // board_t->gameGrid[4][3] = ALIVE;
    // board_t->gameGrid[4][4] = ALIVE;
    
    // Toad
    // board_t->gameGrid[2][3] = ALIVE;
    // board_t->gameGrid[2][4] = ALIVE;
    // board_t->gameGrid[2][5] = ALIVE;
    // board_t->gameGrid[3][2] = ALIVE;
    // board_t->gameGrid[3][3] = ALIVE;
    // board_t->gameGrid[3][4] = ALIVE;

    game(board_t,nb_iterations,TIMEOUT_DEF,isCircular);

    return 0;
}