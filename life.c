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

void fill_matrix(int n, int** matrix, int nrow, int ncol){
    for(int i=0; i<nrow; i++){
        for(int j=0;j<ncol;j++){
            matrix[i][j]=n;
        }
    }
}

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