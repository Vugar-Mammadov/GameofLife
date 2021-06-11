#include"life.h"

/**
 *  @brief creates 2D array and returns the pointer to it
 *
 *  @param nrow: number of rows, ncol: number of columns
 *
 *  @return returns: pointer to the 2D integer array
 **/
int ** create_2D_array(int nrow, int ncol){
    int **arr = (int **)calloc(nrow, sizeof(int *));
    for (int i=0; i<nrow; i++)
         arr[i] = (int *)calloc(ncol, sizeof(int));
    return arr;
}

/**
 * @brief fills given matrix with the given value
 * @param n : value which will be filled
 * @param matrix : 2D matrix
 * @param nrow: number of rows in the matrix
 * @param ncol: number of columns in the matrix
 * @returns void
 **/
void fill_matrix(int n, int** matrix, int nrow, int ncol){
    for(int i=0; i<nrow; i++){
        for(int j=0;j<ncol;j++){
            matrix[i][j]=n;
        }
    }
}

/**
 * @brief prints the given matrix in the console
 * 
 **/
void print_matrix(int** matrix, int nrow, int ncol){
    for(int i=0; i<nrow; i++){
        for(int j=0;j<ncol;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<ncol*2;i++){
        printf("=");
    }
    printf("\n");
}

/**
 * @brief initialize new game board with the specified width and height
 * @param nrow: number of rows, ncol:number of cols
 * 
 **/
Board* initBoard(int nrow, int ncol){
    Board* b = (Board*) malloc(sizeof(Board));
    b->ncol = ncol;
    b->nrow = nrow;
    b->gameGrid = create_2D_array(nrow,ncol);
    return b;
}

/**
 * @brief prints board using ANSI
 * 
 **/
void print_board(Board* b){
    printf("\x1b[H");
    printf("\x1b[2J");
    for(int i=0; i<b->nrow; i++){
        for(int j=0;j<b->ncol;j++){
            
            if(b->gameGrid[i][j]==ALIVE){
                
                printf("\x1b[2;37;40m- \033[0m");
            }
            if(b->gameGrid[i][j]==DEAD){
                printf("\x1b[41m  \033[0m");
            }
            
        }
        printf("\n");
    }
}

/**
 * @brief fills the given board with DEAD cells 
 * 
 **/
void fillBoard(Board* b){
    fill_matrix(DEAD,b->gameGrid,b->nrow,b->ncol);
}


/**
 * @brief for a given cell returns the number of alive neighbours
 * 
 **/

int aliveNeighboursCount(int row, int col, Board* b){
    int count=0;
    // Check all of the neighbours and add them up
    if(row+1 < b->nrow) {
        count += b->gameGrid[row+1][col];
    }

    if(row-1 >0){
        count += b->gameGrid[row-1][col];
    } 

    if(col+1<b->ncol){
        count += b->gameGrid[row][col+1];
    }

    if(col-1>0){
        count += b->gameGrid[row][col-1];
    }

    if((row+1)< b->nrow && (col+1) < b->ncol){
        count += b->gameGrid[row+1][col+1];
    }
    if((row+1)< b->nrow && (col-1) > 0){
        count += b->gameGrid[row+1][col-1];
    }
    if((row-1)> 0 && (col+1) < b->ncol){
        count += b->gameGrid[row-1][col+1];
    }
    if((row-1)> 0 && (col+1) > 0){
        count += b->gameGrid[row-1][col-1];
    }
    return count;
}

/**
 * @brief returns a next state (state in t+1) of a given cell
 * 
 **/

int nextState(int row, int col, Board* b_t ){
    int n_alive_neighbours = aliveNeighboursCount(row,col,b_t);
    int cell_state = b_t->gameGrid[row][col];

    if(cell_state==ALIVE && n_alive_neighbours==2) return ALIVE;
    if(n_alive_neighbours==3) return ALIVE;
    return DEAD;
}

/**
 * @brief Reads the current board and returns a board for time t+1
 * 
 **/
Board* board_t1(Board* board_t){
    int nrow = board_t->nrow;
    int ncol = board_t->ncol;
    Board* board_t_plus_1 = initBoard(nrow,ncol);
    for(int i=0;i<nrow; i++){
        for(int j=0;j<ncol;j++){
            int state_t1 = nextState(i,j,board_t);
            board_t_plus_1->gameGrid[i][j] = state_t1;
        }
    }
    return board_t_plus_1;
}


/**
 * @brief Checks if all of the cells of a board is dead
 * 
 **/
bool deadBoard(Board* b){
    for(int i=0;i<b->nrow;i++){
        for(int j=0;j< b->ncol; j++){
            if(b->gameGrid[i][j]==ALIVE) return false;
        }
    }
    return true;
}

/**
 * @brief Checks if the next state of board is the same as previous
 * 
 **/
bool isSame(Board* b1, Board* b2){
    if(b1==NULL || b2==NULL) return false;
    if(b1->ncol!=b2->ncol || b1->nrow!=b2->nrow) return false;
    int ncol = b1->ncol;
    int nrow = b1->nrow;
    for(int i=0;i<nrow;i++){
        for(int j=0;j<ncol;j++){
            if(b1->gameGrid[i][j] != b2->gameGrid[i][j]){
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Deletes the board and frees the memory
 * 
 **/
void deleteBoard(Board* b){
    if(b==NULL) return;
    for(int i=0;i<b->nrow;i++){
        free(b->gameGrid[i]);
    }
    free(b->gameGrid);
    free(b);
}

/**
 * @brief Game loop
 * 
 **/
void game(Board* b_t, int maxIter){
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