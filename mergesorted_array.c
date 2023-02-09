#include <stdio.h>
int main(){
    int a1[]  = { 10,20,35,40,50 };
    int a2[] = { 13,23,34,45,65 };
    int res[10] ; 
    int i = 0 ; 
    int j = 0 ; 
    int k = 0 ; 
    int n1 = 5 ; 
    int n2 = 5 ; 
    
    while( i < n1 && j < n2  ){
        if( a1[i] < a2[j] ){
            res[k] = a1[i] ; 
            i++ ; 
        }else{
            res[k] = a2[j] ; 
            j++ ; 
        }
        k++ ; 
    }
    while( i < n1 ){
        res[k] = a1[i] ; 
        i++ ; 
        k++ ; 
    }
    while( j < n2 ){
        res[k] = a2[j] ; 
        j++ ; 
        k++ ; 
    }

    for( int m = 0 ; m < 10 ; m++ ){
        printf("%d , " , res[m]  ) ; 
    }
    




    return 0 ; 
}