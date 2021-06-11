/** @file life.c
 *  @brief Functions for the logic of the game and drawing the board
 *
 *  This file contains the functions for the game logic and 
 *
 *  @author Shamil Shukurov
 */

#include"life.h"


int ** create_2D_array(int nrow, int ncol){
    int **arr = (int **)calloc(nrow, sizeof(int *));

    if(arr==NULL){
        printf("Overflow!");
        exit(0);
    }

    for (int i=0; i<nrow; i++)
         arr[i] = (int *)calloc(ncol, sizeof(int));
    return arr;
}


void fill_matrix(int n, int** matrix, int nrow, int ncol){
    for(int i=0; i<nrow; i++){
        for(int j=0;j<ncol;j++){
            matrix[i][j]=n;
        }
    }
}


void fill_matrix_random(int** matrix, int nrow, int ncol){
    if(matrix==NULL || (*matrix)==NULL) return;
    srand(time(0));
    for(int i=0; i<nrow; i++){
        for(int j=0;j<ncol;j++){
            matrix[i][j]= rand() % 2;
        }
    }  
}


Board* initBoard(int nrow, int ncol){
    if(nrow< MIN_NB_ROWS_COLS) nrow= MIN_NB_ROWS_COLS;
    if(ncol < MIN_NB_ROWS_COLS) ncol = MIN_NB_ROWS_COLS;
    Board* b = (Board*) malloc(sizeof(Board));
    
    if(b==NULL){
        printf("Overflow!");
        exit(0);
    }

    b->ncol = ncol;
    b->nrow = nrow;
    b->gameGrid = create_2D_array(nrow,ncol);
    return b;
}

void print_board(Board* b){
    if(b==NULL) return;

    printf(CLR_SCR);
    for(int i=0; i<b->nrow; i++){
        for(int j=0;j<b->ncol;j++){
            
            if(b->gameGrid[i][j]==ALIVE){
                
                printf("%s  %s",MAGB,reset);
            }
            if(b->gameGrid[i][j]==DEAD){
                printf("  ");
            }
            
        }
        printf("\n");
    }
}


void fillBoard(Board* b,bool fillRandom){
    if(b==NULL) return;
    if(fillRandom){
        fill_matrix_random(b->gameGrid,b->nrow,b->ncol);
    }
    else{
        fill_matrix(DEAD,b->gameGrid,b->nrow,b->ncol);
    }
}



int aliveNeighboursCount(int row, int col, Board* b){
    if(b==NULL) return -1;

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


int nextState(int row, int col, Board* b_t ){
    if(b_t==NULL) return -1;

    int n_alive_neighbours = aliveNeighboursCount(row,col,b_t);
    int cell_state = b_t->gameGrid[row][col];

    if(cell_state==ALIVE && n_alive_neighbours==2) return ALIVE;
    if(n_alive_neighbours==3) return ALIVE;
    return DEAD;
}

Board* board_t1(Board* board_t){
    if(board_t==NULL) return NULL;

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


bool deadBoard(Board* b){
    if(b==NULL) return true;

    for(int i=0;i<b->nrow;i++){
        for(int j=0;j< b->ncol; j++){
            if(b->gameGrid[i][j]==ALIVE) return false;
        }
    }
    return true;
}


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


void deleteBoard(Board* b){
    if(b==NULL) return;
    for(int i=0;i<b->nrow;i++){
        free(b->gameGrid[i]);
    }
    free(b->gameGrid);
    free(b);
}


