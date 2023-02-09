#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 
#define SIZE 12

typedef struct{
    int capacity ; 
    int heap[MAX_SIZE];
    int size ; 
} maxHeap ; 

void swap( int *a  , int *b ){
    int temp  = *a ; 
    *a = *b  ; 
    *b = temp ; 
}
void heapify( maxHeap *heap , int idx ){
    int parent = idx ; 
    int l_child = (2 * parent ) +  1; 
    int r_child = (2 * parent ) +  2; 
    if( l_child < heap->size && heap->heap[parent] < heap->heap[l_child] ){
        parent = l_child  ; 
    }
    if( r_child < heap->size && heap->heap[parent] < heap->heap[r_child] ){
        parent = r_child  ; 
    }
    if( parent != idx ){
        swap(&(heap->heap[parent]) ,  &(heap->heap[idx]));
        heapify(heap , parent );
    }

}
void buildHeap(maxHeap *heap ){
    printf("\nddd\n");
    int l_idx =( heap->size / 2 ) - 1 ; 
    printf("\n%d \n " , heap->size);
    for( int i = l_idx ; i >= 0 ; i-- ){
        heapify(heap , i  ); 
    };
}
void printHeap(maxHeap *heap ){
    printf("\n\n");
    for( int i = 0 ; i < heap->size ; i++ ){
        printf("%d , " , heap->heap[i] );
    }
}
void insert( maxHeap *heap , int data ){
    
    heap->heap[heap->size] = data ; 
    heap->size ++ ; 
    buildHeap(heap);
    
}
void delete( maxHeap *heap ){
    swap(&(heap->heap[0]) ,  &(heap->heap[heap->size-1]));
    heap->size -- ; 
    heapify(heap , 0 );
}
void heapsort( maxHeap *heap ){
    printf("\n\nheapsort\n\n");
    int numofDEl = heap->size ; 
    for( int i = 0 ; i < numofDEl ; i++ ){
        delete(heap);
    }
    printf("\n\n");
    for( int i = 0 ; i < numofDEl; i++ ){
        printf("%d , " , heap->heap[i] );
    };

}

int main(){
    int numarray[SIZE] = { 65 , 91 , 3 , 10 , 40 , 1 , 2 , 9 , 8 , 100 ,  5 , 0  };
    maxHeap *heap = ( maxHeap*)malloc(sizeof(maxHeap));
    heap->size = 0 ; 
    heap->capacity = MAX_SIZE ; 
    for( int i = 0 ; i < SIZE ; i++ ){
        heap->heap[i] = numarray[i] ; 
        heap->size ++ ; 
    }
    printHeap(heap);
    buildHeap(heap);
    printHeap(heap);
    insert(heap , 105);
    // buildHeap(heap);
    printHeap(heap);
    delete(heap);
    printHeap(heap);
    delete(heap);
    printHeap(heap);
    delete(heap);
    printHeap(heap);
    heapsort(heap);


    return 0 ; 
}