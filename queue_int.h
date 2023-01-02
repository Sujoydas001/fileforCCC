#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 

int rear= -1  , front = 0 ; 

bool isFull(int *queue){
    if ( rear == MAX_SIZE){
        // printf("full\n");
        return true ; 
    }
    return false ; 
}

bool isEmpty(int *queue){
    if ( rear == front - 1  ){
        // printf("empty\n");
        return true ; 
    }
    return false ; 
}

void Enque(int *queue , int data ){
    if (!isFull(queue)){
        queue[++rear] = data ; 
    }
}

int Dequeue(int *queue ){
    if ( !isEmpty(queue)){
        int a = queue[front]; 
        front++ ; 
        return a ; 
    }
    
}

void printQueue(int *queue){
    if (isEmpty){
        for ( int i = front  ; i<= rear ; i++ ){
            printf("%d , " , queue[i]);
        }
    
    }else{
        printf("empty");
    }
    printf("\n");
}


// int main(){
//     int *queue = (int*)malloc( 100 * sizeof( int ));
//     int idx = 9 ; 
//     Enque(queue , idx++ );
//     Enque(queue , idx++ );
//     Enque(queue , idx++ );
//     Enque(queue , idx++ );
//     Enque(queue , idx++ );
//     Enque(queue , idx++ );
//     Enque(queue , idx++ );
//     printQueue(queue);
//     int emp = Dequeue(queue);
//     printf("%d",emp);
    
// }