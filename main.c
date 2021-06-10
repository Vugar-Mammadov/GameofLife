#include "life.h"
#define NROW 12
#define NCOL 12
int main(int argc, char const *argv[])
{
    Board * board_t = initBoard(NROW,NCOL);
    fillBoard(board_t);
    print_matrix(board_t->gameGrid,board_t->nrow,board_t->ncol);
    return 0;
}