#include <stdio.h>

void swap( int *a , int *b ){
    int temp = *a ; 
    *a = *b ; 
    *b = temp ; 
}
int partition(int a[] , int l  , int r ){
    int pivot = a[r];
    int i = l - 1 ; 
    for ( int j = l ; j <= r -1; j++ ){
        if ( a[j] <= pivot ){
            i++ ; 
            swap( &a[i] , &a[j] );
        }

    } 
    swap(&a[i+1]  , &a[pivot]);
    return (i+ 1) ;
}
void quickSort(int a[] , int l , int r ){
    if( l < r ){
        int pi = partition(a , l ,r);
        // for( int i = 0 ; i < r ; i++ ){
        //     printf("%d,",a[i]);
        // }
        printf("\n");
        quickSort(a,l,pi-1 );
        quickSort(a,pi+1 , r );
    }
}
int main(){
    // int ar[] = { 1,9,-12,8,6,7,5,4,3,2,1};
    int ar[] = { 10,80,30,90,40,50,70 } ;
    int size = sizeof(ar)/ sizeof(ar[0]);
    quickSort(ar,0 ,  size);
    for( int i = 0 ; i < size ; i++ ){
        printf("%d,",ar[i]);
    }
    
}