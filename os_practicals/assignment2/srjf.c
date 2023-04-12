#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000 
#define SIZE 12

typedef struct {
    int pid ; 
    int a_time ; 
    int b_time ; 
}process ; 

typedef struct{
    int capacity ; 
    process heap[MAX_SIZE];
    process holder[MAX_SIZE] ; 
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
    int l_idx =( heap->size / 2 ) - 1 ; 
    for( int i = l_idx ; i >= 0 ; i-- ){
        heapify(heap , i  ); 
    };
}
void printHeap(minHeap *heap ){
    printf("printing heap:");
    for( int i = 0 ; i < heap->size ; i++ ){
        printf("(%d , %d)" , heap->heap[i].pid ,heap->heap[i].b_time );
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

void addToHolder(minHeap *heap , process *data , int i  ){
    heap->holder[i].pid = data->pid ; 
    heap->holder[i].a_time = data->a_time ; 
    heap->holder[i].b_time = data->b_time ; 
}




int main(){
    int prev_id = -1 , curr_id = -1 ; 
    minHeap *pq = ( minHeap*)malloc(sizeof(minHeap)) ; 
    int n ; 
    // load(pq , n ) ;

    FILE *ptr = fopen("INPUTFILE.txt" , "r")  ; 
    int pid_ref , a_time_ref , b_time_ref ;
    process *refProcess = ( process*)malloc(sizeof(process)); 
    fscanf(ptr,"%d",&n ) ; 
    if( n == 0 ){
        printf("\n no process \n") ; 
        exit(0) ; 
    }
    for( int i = 0 ; i < n ; i++ ){
        fscanf(ptr, "%d%d%d",&pid_ref ,&a_time_ref, &b_time_ref ) ; 
        refProcess->pid = pid_ref ; 
        refProcess->a_time = a_time_ref ; 
        refProcess->b_time = b_time_ref ; 
        addToHolder(pq,refProcess , i ) ;
    }


    for( int i = 0 ; i < n; i++ ){
        process job = pq->holder[i] ; 
        printf("/ %d %d %d \n" , job.pid , job.a_time , job.b_time ) ;
    }

    // int start = 1 ; 
    // int time = 0 ; 
    // int get ; 
    // int i = 0 ; 
    // process *prev = NULL ; 
    // int prempt_seperation ; 
    // do{
    //     prempt_seperation = 0 ; 
    //     for( int j = 0 ; j < n ; j++ ){
    //         process job = pq->holder[j] ; 
    //         // printf("/ %d %d %d \n" , job.pid , job.a_time , job.b_time ) ;
    //         if( job.a_time == i  ) {
    //             process *c = &job ; 
                 
    //             insert(pq,c ) ; 
    //         }
    //     }
    //     time = i  ; 
    //     printf("time :%d " , time  ) ; 
    //     printHeap(pq) ; 
    //     printf("\n") ; 
    //     if( time == 0 ){
    //         printf("time : %d : process %d starts \n" ,time, pq->heap[0].pid  ) ; 
    //     }
        
    //     process c = extractMin(pq);
    //     process *curr = &c;
    //     curr_id = curr->pid ; 
    //     int b_time_ref_prempt= -1 ; 
    //     for( int j = 0 ; j < n ; j++ ){
    //         if( prev_id == pq->holder[j].pid  ) {
    //             b_time_ref_prempt = pq->holder[j].b_time ; 
    //         }
    //     }
    //     int remaining_one  = -1 ; 
    //     if(( curr_id != prev_id ) &&( b_time_ref_prempt != 0 ) && ( prev_id != -1 )){
    //         // printf("time : %d : process %d prempts( remianing time = %d ) process %d starts \n" ,time, prev_id , b_time_ref_prempt  ,  curr_id  ) ; 
           
    //         for( int j = 0 ; j < n ; j++ ){
    //             if( curr_id == pq->holder[j].pid  ) {
    //                 remaining_one = pq->holder[j].b_time ; 
    //             }
    //         }

    //         prempt_seperation = 1 ; 
    //     }
        
    //     prev_id = curr_id ; 
    //     curr->b_time-- ;
    //     int pid_ref = curr->pid ; 
    //     int flag = 0 ; 
    //     for( int j = 0 ; j < n  && flag == 0 ; j++ ){
    //         if( pid_ref == pq->holder[j].pid ) {
    //             pq->holder[j].b_time-- ; 
    //             flag = 1 ; 
    //         }
    //     }
        
    //     // printf("time %d : running process %d\n",time  ,curr->pid ) ; 
        
    //     if( curr->b_time != 0 ){
    //         insert(pq,curr); 
    //     }else{
    //         if( time != 0  ){
    //             if(pq->size == 0  ){
    //                 printf("time : %d : process %d ends . \n" ,time, curr->pid ) ; 
    //             }else{
    //                 printf("time : %d : process %d ends process %d starts \n" ,time, prev->pid , curr->pid ) ; 
    //             }
    //         }
    //     }
            
            
    //     prev = curr ; 
    //     // printf("going to next \n") ; 
    //     i++ ;  
    //     // scanf("%d", &get) ;

        
    // }while(pq->size != 0 ); 




    int start = 1 ; 
    int time = 0 ; 
    int get ; 
    int i = 0 ; 
    process *prev = NULL ; 
    int prempt_seperation ; 
    do{
        prempt_seperation = 0 ; 
        for( int j = 0 ; j < n ; j++ ){
            process job = pq->holder[j] ; 
            // printf("/ %d %d %d \n" , job.pid , job.a_time , job.b_time ) ;
            if( job.a_time == i  ) {
                process *c = &job ; 
                 
                insert(pq,c ) ; 
            }
        }
        time = i  ; 
        printf("time :%d " , time  ) ; 
        printHeap(pq) ; 
        printf("\n") ; 
        if( time == 0 ){
            printf("time : %d : process %d starts \n" ,time, pq->heap[0].pid  ) ; 
        }
        
        process c = extractMin(pq);
        process *curr = &c;
        curr_id = curr->pid ; 
        int b_time_ref_prempt= -1 ; 
        for( int j = 0 ; j < n ; j++ ){
            if( prev_id == pq->holder[j].pid  ) {
                b_time_ref_prempt = pq->holder[j].b_time ; 
            }
        }
        int remaining_one  = -1 ; 
        if(( curr_id != prev_id ) &&( b_time_ref_prempt != 0 ) && ( prev_id != -1 )){
            printf("time : %d : process %d prempts( remianing time = %d ) process %d starts \n" ,time, prev_id , b_time_ref_prempt  ,  curr_id  ) ; 
           
            // for( int j = 0 ; j < n ; j++ ){
            //     if( curr_id == pq->holder[j].pid  ) {
            //         remaining_one = pq->holder[j].b_time ; 
            //     }
            // }
            // remaining_one = curr->b_time ; 

            prempt_seperation = 1 ; 
        }
        
        
        curr->b_time-- ;
        int pid_ref = curr->pid ; 
        int flag = 0 ; 
        for( int j = 0 ; j < n  && flag == 0 ; j++ ){
            if( pid_ref == pq->holder[j].pid ) {
                pq->holder[j].b_time-- ; 
                flag = 1 ; 
            }
        }
        
        // printf("time %d : running process %d\n",time  ,curr->pid ) ; 
        
        if( curr->b_time != 0 ){
            insert(pq,curr); 
        }else{
            if( time != 0  ){
                if(pq->size == 0  ){
                    printf("time : %d : process %d ends . \n" ,time, curr->pid ) ; 
                }else{
                    if( (prempt_seperation == 0 ) && ( prev->pid != curr->pid  ))  {
                        printf("time : %d : process %d ends process %d starts \n" ,time, prev->pid , curr->pid ) ; 
                    }
                    
                }
            }
        }
            
            
        prev = curr ; 
        prev_id = curr_id ; 
        printf("going to next \n") ; 
        i++ ;  
        scanf("%d", &get) ;

        
    }while(pq->size != 0 ); 








    return 0 ; 
}



/*


do{
    time = i 
    for ( ){   iterate over all jobs in holder array 
        insert in ready queue if time of job is i ;  ( readyQueue ( priority as b_time ))
    }

    a = extract min 
    prev process ends a start 
    run a  == === a.b_time-- ;
     


    
}while( size > 0 ) ; 


*/