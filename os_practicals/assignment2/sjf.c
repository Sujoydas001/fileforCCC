#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000 
#define SIZE 12

typedef struct {
    int pid ; 
    int b_time ; 
}process ; 

typedef struct{
    int capacity ; 
    process heap[MAX_SIZE];
    int size ; 
} minHeap ; 

void swap( process *a  , process *b ){
    process temp  = *a ; 
    *a = *b  ; 
    *b = temp ; 
}
void heapify( minHeap *heap , int idx ){
    int parent = idx ; 
    int l_child = (2 * parent ) +  1; 
    int r_child = (2 * parent ) +  2; 
    if( l_child < heap->size && heap->heap[parent].b_time > heap->heap[l_child].b_time ){
        parent = l_child  ; 
    }
    if( r_child < heap->size && heap->heap[parent].b_time > heap->heap[r_child].b_time ){
        parent = r_child  ; 
    }
    if( parent != idx ){
        swap(&(heap->heap[parent]) ,  &(heap->heap[idx]));
        heapify(heap , parent );
    }

}
void buildHeap(minHeap *heap ){
    printf("\nddd\n");
    int l_idx =( heap->size / 2 ) - 1 ; 
    printf("\n%d \n " , heap->size);
    for( int i = l_idx ; i >= 0 ; i-- ){
        heapify(heap , i  ); 
    };
}
void printHeap(minHeap *heap ){
    printf("\n\n");
    for( int i = 0 ; i < heap->size ; i++ ){
        printf("%d , " , heap->heap[i].b_time );
    }
}
void insert( minHeap *heap , process *data ){
    
    heap->heap[heap->size].pid = data->pid ; 
    heap->heap[heap->size].b_time = data->b_time ; 
    heap->size ++ ; 
    buildHeap(heap);
    
}
process extractMin( minHeap *heap ){
    process temp = heap->heap[0] ; 
    swap(&(heap->heap[0]) ,  &(heap->heap[heap->size-1]));
    heap->size -- ; 
    heapify(heap , 0 );
    return temp ; 
}
bool isLast(minHeap *heap ){
    if( heap->size == 1 ){
        return true ; 
    }
    return false ; 
}

int main(){
    FILE *ptr = fopen("INPUTFILE.txt" , "r")  ; 
    int n  , pid_ref , b_time_ref ;
    process *refProcess = ( process*)malloc(sizeof(process)); 
    fscanf(ptr,"%d",&n ) ; 
    if( n == 0 ){
        printf("\n no process \n") ; 
        exit(0) ; 
    }
    minHeap *pq = ( minHeap*)malloc(sizeof(minHeap)) ; 
    for( int i = 0 ; i < n ; i++ ){
        fscanf(ptr,"%d%d",&pid_ref , &b_time_ref ) ; 
        refProcess->pid = pid_ref ; 
        refProcess->b_time = b_time_ref ; 
        insert(pq,refProcess) ; 
    }
    int i = 0 ;
    int time = 0 ; 
    printf("time %d :process %d start\n" ,time , pq->heap[0]  ) ; 
    while( !isLast(pq)){
        process curr = extractMin(pq) ; 
        process next = pq->heap[0] ; 
        time += curr.b_time ; 
        printf("time %d :process %d end , process %d start\n" ,time ,  curr.pid , next.pid ) ; 
          
    }
    time+= pq->heap[0].b_time ; 
    printf("time %d :process %d start\n" ,time , pq->heap[0].pid ) ; 






    return 0 ; 
}