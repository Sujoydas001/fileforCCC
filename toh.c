#include <stdio.h>
#include <math.h>

void toh_reccursion( char src , char dest , char help , int n , int* add ){
    if( n == 0 ){
        return ; 
    }
    (*add)++ ; 
    toh_reccursion( src , help , dest , n-1 , add);
    printf("\nmove %c - %c \n ",src , dest );
    toh_reccursion( help , dest , src , n-1 , add);
    return ; 
}

void toh_iterate( char src , char help , char dest , int n , int *add ){
    int i  = 1 ; 
    int size = pow( 2 , n  ) - 1 ; 
    while( i <= size ){
        if( i % 3 == 1 ){
            printf("\nmove %c - %c \n ",src , help );            
        }else if ( i % 3 == 2 ){
            printf("\nmove %c - %c \n ",src , dest );
        }else if( i % 3 == 0 ){
            printf("\nmove %c - %c \n ",help , dest );
        }
        i++ ; 
        (*add)++ ; 
    }
    return ; 
}

void superset( int input[], int size , int id ){
    if( id == size ){
        printf(" \n ");
        return ; 
    }
    superset( input , size ,id + 1 );
    printf(" %d " , input[id]);
    superset( input , size ,id + 1 );
    return ; 
}

void swap( int *a , int *b ){
    int temp = *a ; 
    *a = *b ; 
    *b = temp ; 
}
void print_permutation( int *array , int size ){
    for( int i = 0 ; i <= size ; i++ ){
        printf("%d " , array[i] );
    }
    printf("\n");
    return ; 
}
void permutation( int *array , int strtIdx  , int endIdx ){
    static int index = 0 ; 
    if( strtIdx == endIdx ){
        print_permutation(array , endIdx);
        index++ ; 
        return ; 
    }
    for( int i = strtIdx ; i <= endIdx ; i++ ){
        swap( (array+index) , (array+strtIdx) );
        permutation(array , strtIdx+1 , endIdx);
        swap( (array+strtIdx) , (array+index) );
    };
    return ; 
    
}


int main(){
    // int count = 0 ; 
    // toh_reccursion('A' , 'B' , 'C' , 3 , &count );
    // printf("\n%d\n" , count );
    // count = 0 ; 
    // toh_iterate('A' , 'B' , 'C' , 3 , &count );
    // printf("\n%d\n" , count );
    int input_set[] = {1,2,3 , 4 };
    int size = 3 ; 
    // superset(input_set , size , 0);
    permutation(input_set , 0 , 3 );


    return 0 ; 
}