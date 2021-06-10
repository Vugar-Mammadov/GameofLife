#include "life.h"
#define NROW 12
#define NCOL 12
int main(int argc, char const *argv[])
{
    Board * board_t = initBoard(NROW,NCOL);
    fillBoard(board_t);
    // Glider
    board_t->gameGrid[1][2] = ALIVE;
    board_t->gameGrid[2][3] = ALIVE;
    board_t->gameGrid[3][3] = ALIVE;
    board_t->gameGrid[3][2] = ALIVE;
    board_t->gameGrid[3][1] = ALIVE;

    game(board_t,30);

    return 0;
}