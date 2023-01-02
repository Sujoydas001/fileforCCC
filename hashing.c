#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int iosize  ; 
#define SIZE 100 



void insert( int a[] , int k){
    int m = SIZE ; 
    
        int x = k % m ; 
        int i = 0 ; 
        int p = 1 ; 
        while( p ){
            int old = (int)( x + pow(i , 2) ) % m  ; 
            if ( a[old] == k ){
                return ; 
            }
            if ( a[old] != -1 ){
                x = old ; 
                i++ ; 
            }else{
                a[old] = k ; 
                p = 0 ; 
            }

        }      ; 
    return ; 
}

void print(int a[] ){ 
    for( int i = 0 ; i < SIZE ; i++ ){
        printf("%d, " , a[i] );
    }
    printf("\n");
}

void Hash_search(int a[] , int k ){
    int m = SIZE ; 
    if ( a[ k % m ] == k ){
        printf(" found\n\n");
        return ; 
    }else{
        int x = k % m ; 
        int i = 1 ; 
        int p = 1 ; 
        while( p){
            int old = (int)( x + pow(i , 2) ) % m  ; 
            if ( a[old] != -1 ){
                x = old ; 
                i++ ; 
            }else{
                
                printf("found\n");
                return ; 
                
            }
            if ( old >= SIZE){
                p = 0 ; 
            }

        }     
    } ; 
    printf("not found\n\n");
    return ; 
}

int main(){

    int iosize = SIZE ; 
    int count[iosize] ;
    for ( int i = 0 ; i < iosize ;i++ ){
        count[i] = -1 ; 
    }

    insert(count , 12 ); 
    // insert(count , 112 ); 
    // insert(count , 113 ); 
    // insert(count , 114 ); 
    // insert(count , 115 ); 
    // insert(count , 124 ); 
    insert(count , 212 ); 
    // insert(count , 213 ); 
    insert(count , 112 ); 
    insert(count , 212 ); 
    // insert(count , 10000 ,size ); 
    print(count);
    Hash_search(count, 112 );

}