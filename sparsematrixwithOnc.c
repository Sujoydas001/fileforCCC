#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int row ;
    int col ;
    int data ;
} node ;
int main(int argc , char *argv[]){
    int rows, cols, num ;
    FILE *fptr  = fopen(argv[1] , "r");
    fscanf(fptr , "%d%d%d" , &rows,&cols,&num);
    node *mat1 = calloc(( num + 1 ) , sizeof(node));  /*dynamically allocate memory for node array where to store the original sparse matrix*/
    node *mat2 = calloc(( num + 1 ) , sizeof(node));  /*dynamically allocate memory for node array where to store the transpose sparse matrix*/
    mat1[0].row = rows;  /*for both of them at 0 index keep the no of row , column , and data */
    mat1[0].col = cols;
    mat1[0].data = num;
    mat2[0].row = rows;
    mat2[0].col = cols;
    mat2[0].data = num;
    for( int i = 1 ; i<= num ; i++ ){
        //take input from file  row , col , val  for original matrix;
        fscanf(fptr , "%d%d%d" , &mat1[i].row, &mat1[i].col ,&mat1[i].data);
        

    }
    fclose(fptr);
    printf("\n\n");
    int m = 0,n = 1 ;
    while ( n <= num ){
        for ( int j = 1 ; j<= num ; j++ ){         /* loop with O(n^2) to sort the transpose along with swapping the row and column */
            if ( mat1[j].col == m ){
                mat2[n].row = mat1[j].col ;
                mat2[n].col = mat1[j].row ;
                mat2[n].data = mat1[j].data ;
                n++ ;
            }
        }
        m++;
    }
    printf("Original matrix: \nrow -- column -- data\n\n");
    for ( int i = 0 ; i < num ; i++ ){
        printf("%d\t%d\t%d\n" , mat1[i].row, mat1[i].col, mat1[i].data );
    }
    printf("Transpose of the matrix: \nrow -- column -- data\n\n");
    for ( int i = 0 ; i < num ; i++ ){
        printf("%d\t%d\t%d\n" , mat2[i].row, mat2[i].col, mat2[i].data );
    }

    free(mat1);
    free(mat2);
    return 0 ;

}
