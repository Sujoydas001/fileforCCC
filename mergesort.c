#include <stdio.h>
void merge(int a[] , int l , int m, int r ){
    int n1  = m - l + 1 ; 
    int n2 = r - m ; 
    int L[n1];
    int R[n2];
    for ( int i  = 0 ; i < n1 ; i++ ){
        L[i] = a[l+ i]  ; 
    }
    for ( int i  = 0 ; i < n1 ; i++ ){
        R[i] = a[m + 1 + i]  ; 
    }
    int i = 0 ; 
    int j = 0 ; 
    int k = l ; 
    while( i < n1 && j < n2 ){
        if ( L[i] <= R[j] ){
            a[k] = L[i];
            i++ ; 
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while( i < n1 ){
        a[k] = L[i] ; 
        i++ ; 
        k++ ; 
    }
    while( j < n2 ){
        a[k] = R[j] ; 
        j++ ; 
        k++ ; 
    }
}
void mergesort(int a[] , int l , int r ){
    if ( l < r ){
        int mid  = l + ( r - l )/ 2 ; 
        mergesort(a , l , mid );
        mergesort( a , mid + 1 , r );
        merge( a , l , mid ,  r );
    }

}
int main(){
    int ar[] = { 1,9,-12,8,6,7,5,4,3,2,1};
    int size = sizeof(ar)/ sizeof(ar[0]);
    mergesort(ar,0 ,  size);
    for( int i = 0 ; i < size ; i++ ){
        printf("%d,",ar[i]);
    }
    
}