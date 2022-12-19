#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int row ;
    int col ;
    int data ;
} node ;

int main(int argc , char *argv[] ){
    int rows, cols, num ;
    FILE *fptr  = fopen(argv[1], "r");
    if ( fptr == NULL ){
        printf("error opening file \n");
        exit(1);
    }
    fscanf(fptr , "%d%d%d" , &rows,&cols,&num);
    node *mat1 = calloc(( num + 1 ) , sizeof(node));  /*dynamically allocate memory for node array where to store the original sparse matrix*/
    node *mat2 = calloc(( num + 1 ) , sizeof(node));  /*dynamically allocate memory for node array where to store the transpose sparse matrix*/
    int *freqtotal = calloc((cols) , sizeof(int));
    int *dataidx = calloc((cols) , sizeof(int));

    mat1[0].row = rows;  /*for both of them at 0 index keep the no of row , column , and data */
    mat1[0].col = cols;
    mat1[0].data = num;
    mat2[0].row = cols ;
    mat2[0].col = rows ;
    mat2[0].data = num ;
    
    for( int i = 1 ; i<= num ; i++ ){
        //take input from file  row , col , val  for original matrix;
        fscanf(fptr , "%d%d%d" , &mat1[i].row, &mat1[i].col ,&mat1[i].data );
        freqtotal[(mat1[i].col)]++;
        

    }
    fclose(fptr);
    printf("\n\n");

    
    dataidx[0] = 1 ;
    for( int i = 1 ; i< cols ; i++ ){
        dataidx[i] = dataidx[i-1] + freqtotal[i-1];
    }

    for ( int i = 1 ; i <= num  ; i++ ){
        int col_no = dataidx[(mat1[i].col)];
        mat2[col_no].row  = mat1[i].col ; 
        mat2[col_no].col  = mat1[i].row ; 
        mat2[col_no].data  = mat1[i].data ; 
        dataidx[(mat1[i].col)]++ ; 
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
    free(dataidx);
    free(freqtotal);
    return 0 ;

}
