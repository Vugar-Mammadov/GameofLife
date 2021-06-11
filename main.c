#include "life.h"

int main(int argc, char const *argv[])
{
    Board * board_t = initBoard(NROW_DEF,NCOL_DEF);
    fillBoard(board_t);
    // Glider
    board_t->gameGrid[1][2] = ALIVE;
    board_t->gameGrid[2][3] = ALIVE;
    board_t->gameGrid[3][3] = ALIVE;
    board_t->gameGrid[3][2] = ALIVE;
    board_t->gameGrid[3][1] = ALIVE;

    game(board_t,MAX_ITER_DEF);

    return 0;
}