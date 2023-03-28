#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 7

typedef struct {
    int front ; 
    int rear ; 
    int size ; 
    int capacity ; 
    int queue[MAXSIZE];
} circular_queue_int ; 

circular_queue_int*  initiate(){
    circular_queue_int *queue = (circular_queue_int*)malloc(sizeof(circular_queue_int)) ;
    queue->capacity = MAXSIZE ; 
    queue->size = 0 ; 
    queue->rear = -1 ; 
    queue->front = -1 ; 
    return queue ; 
}

bool isEmpty(circular_queue_int *cirque){
    if ( cirque->rear  == cirque->front ){
        printf("\ncircular queue is empty \n");
        return true ; 
    }
    return false ;
    
}

bool isFull(circular_queue_int *cirque){
    if(( cirque->rear  == cirque->capacity - 1 && cirque->front == -1 )||( cirque->rear < cirque->front &&  cirque->rear == cirque->front - 1 )){
        printf("\ncircular queue is full \n");
        return true ; 
    }
    return false ; 
}


void enqueue(circular_queue_int *cirque , int data ){
    if( !isFull(cirque) ){
        int r = ( cirque->rear + 1 ) % cirque->capacity ; 
        cirque->queue[r] = data ; 
        cirque->rear = r ; 
        cirque->size ++ ; 
        return ; 
    }
}
void utilityEnque(circular_queue_int *cirque){
    int data;
	printf("enter data to add : \n ");
	scanf("%d", &data);
    enqueue(cirque,data);
    return ; 
}
int dequeue(circular_queue_int *cirque){
    if ( !isEmpty(cirque) ){
        int f = ( cirque->front + 1 )% cirque->capacity ; 
        cirque->front = f ; 
        return cirque->queue[f] ; 
        cirque->size -- ; 
    } ; 
    return -999999999 ; 
}
int utilityDeque( circular_queue_int *cirque ){
    return dequeue(cirque);
}
void print_cirQueue(circular_queue_int *cirque){
    if( isEmpty(cirque)){
        return ; 
    }
    if ( cirque->rear > cirque->front ){
        for( int i = cirque->front+ 1  ; i<= cirque->rear ; i++ ){
            printf("%d , " , cirque->queue[i] );
        };
    }else {
        for( int i = cirque->rear ; i< cirque->front ; i++ ){
            printf("%d , " , cirque->queue[i] );
        };
        for( int i = cirque->front ; i< cirque->capacity ; i++ ){
            printf("%d , " , cirque->queue[i] );
        };
    }
    printf("\n");
    return ; 
}


// void print_cirQueue(circular_queue_int *cirque){
//     if( isEmpty(cirque)){
//         return ; 
//     }
//     for( int i = 0 ; i < cirque->capacity ; i++ ){
//         printf("%d,",cirque->queue[i]);
//     }
//     printf("\n");
//     return ; 
// }
