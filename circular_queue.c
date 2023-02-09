#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int front = -1 ; 
int rear = -1 ; 

int *queue ; 
#define __EMPTY -999999

int capacity  = 5 ; 

void  init(){
    queue = (int*)calloc( capacity , sizeof(int)) ;
    // return queue ; 
}

bool isEmpty(){
    if ( rear == front ){
        return true ; 
    }
    return false ;
    
}

bool isFull(){
    if(( rear  == capacity - 1 && front == -1 )||( rear < front &&  rear == front - 1 )){
        return true ; 
    }
    return false ; 
}


void enqueue(int data ){
    if( !isFull(queue) ){
        int r = ( rear + 1 ) % capacity ; 
        queue[r] = data ; 
        rear = r ; 
        return ; 
    }
}

void printQueue(){
    if ( rear > front ){
        for( int i = front ; i<= rear ; i++ ){
            printf("%d , " , queue[i] );
        };
    }else {
        for( int i = rear ; i<= front ; i++ ){
            printf("%d , " , queue[i] );
        };
        for( int i = front ; i< capacity ; i++ ){
            printf("%d , " , queue[i] );
        };
    }
}
int dequeue(){
    if ( !isEmpty(queue) ){
        int f = ( front + 1 )% capacity ; 
        return queue[f] ; 
    } ; 
    return __EMPTY ; 
}
int main(){
    printf("hell\n");
    init() ; 
    printQueue() ; 



    return 0 ; 
}