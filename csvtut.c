#include <stdio.h>
int main(){
    FILE *ptr ; 
    ptr = fopen("csvtut.csv" , "a") ; 
    for( int i = 0 ; i < 68 ; i++ ){
        fprintf(ptr , "%d,%d\n" , i , i + 10 ); 
    }
    fclose(ptr); 
    
}