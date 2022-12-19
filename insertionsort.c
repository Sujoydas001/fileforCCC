#include <stdio.h>
void insertion_Sort(int a[] , int size ){
    for( int i = 1 ; i< size ; i++ ){
        int key = a[i] ; 
        int j = i - 1 ; 
        while( j >= 0 && a[j] >  key ){
            a[j+1] = a[j] ; 
            j-- ;  
        }
        a[j+1] = key ; 
    }
    // for( int i = 0 ; i < size ; i++ ){
    //     printf("%d,",a[i]);
    // }
}
int main(){
    int ar[] = { 1,9,-12,8,6,7,5,4,3,2,1};
    int size = sizeof(ar)/ sizeof(ar[0]);
    insertion_Sort(ar, size);
    for( int i = 0 ; i < size ; i++ ){
        printf("%d,",ar[i]);
    }
    
}