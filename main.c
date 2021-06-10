#include "life.h"
#define NROW 12
#define NCOL 12
int main(int argc, char const *argv[])
{
    Board * board_t = initBoard(NROW,NCOL);
    fillBoard(board_t);

    // Glider configuration
    board_t->gameGrid[1][2] = ALIVE;
    board_t->gameGrid[2][3] = ALIVE;
    board_t->gameGrid[3][3] = ALIVE;
    board_t->gameGrid[3][2] = ALIVE;
    board_t->gameGrid[3][1] = ALIVE;
    print_matrix(board_t->gameGrid,board_t->nrow,board_t->ncol);
    // cell in pos (1,2) should die because of loneliness :(
    printf("Next state: %d\n",nextState(1,2,board_t));
    // And new cell will be born in (4,2)
    printf("Next state: %d\n",nextState(4,2,board_t));

    return 0;
}