#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_int.h"


#define MAX_SIZE 100 

FILE *fptr ; 
char graph_dir ;
int vertice ;
typedef struct ln{
    int val ; 
    struct ln *nextnode ;
    bool BFS_visit ;  
    bool DFS_visit ;  
} listnode ; 

typedef struct nd{
    bool is_visitedBFS ; 
    bool is_visitedDFS ; 
    int vertex ; 
    listnode* next ; 
} ver_node ; 

typedef struct gh{
    int is_directed ; 
    int vtx ; 
    ver_node  vtx_array[MAX_SIZE] ; 
    
} graph ; 

int** creatematrix(int n ){
    int **matrix = ( int** )malloc( n * sizeof(int*) );
    if( matrix == NULL ){
        printf("\nnot enough memory \n");
        exit(1);
    };
    for( int i = 0 ; i < n ; i++ ){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    for( int i = 0 ; i < n ; i++ ){
       for( int j = 0 ; j < n ; j++ ){
            fscanf(fptr , "%d" , &matrix[i][j]);
        } 
    
    }

    return matrix ; 
}

void printmatrix(int **adj_mat){
    printf("%c  %d\n", graph_dir , vertice);
    for( int i = 0 ; i < vertice ; i++ ){
       for( int j = 0 ; j < vertice ; j++ ){
            printf( "%4d" , adj_mat[i][j]);
        } 
        printf("\n");
    }
}

graph* create_graph(int n ){
    graph *newgraph = (graph*)malloc(sizeof(graph));
    newgraph->vtx = n ;  
    newgraph->is_directed = graph_dir ;
    for( int i = 0 ; i < n ; i++ ){
        newgraph->vtx_array[i].is_visitedBFS = false ;
        newgraph->vtx_array[i].is_visitedDFS = false ;
    } 
    return newgraph ; 
}

listnode* newList_node(int key ){
    listnode *newnode = (listnode*)malloc( sizeof( listnode));
    newnode -> val = key ; 
    newnode -> nextnode = NULL ; 

    return newnode ; 
}

listnode* addNode(ver_node v , int i ){
    listnode *tm = v.next ; 
    if ( tm == NULL ){
        tm = newList_node(i);
        return tm ; 
    }else{
        listnode *tmpp = tm ; 
        while( tm -> nextnode != NULL ){
            
            tm = tm -> nextnode ; 
        }
        tm -> nextnode = newList_node(i);
        return tmpp  ; 
    }

    
}

void create_list(graph *graph , int **adj_mat){
    for( int i = 0 ; i < graph->vtx  ;i++ ){
        graph->vtx_array[i].vertex = i ; 
        for( int j = 0 ; j < graph->vtx ; j++ ){
            if ( adj_mat[i][j] == 1 ){
                
                graph->vtx_array[i].next = addNode(graph->vtx_array[i]  , j);
                
            }

        }
    }
    return  ; 
}

void printadj_list(graph* graph){
    printf("\n\nadjacency list : : : \n");
    for( int i = 0 ; i < vertice ; i++ ){
        printf("\n%d\t->", graph->vtx_array[i].vertex );
        listnode *tmplist = graph->vtx_array[i].next ; 
        while( tmplist != NULL ){
            printf("%d\t->", tmplist ->val );
            tmplist = tmplist->nextnode  ; 
        }
        printf("\n");
    }
}

int find_degree(graph *graph , ver_node v ){
    if(graph->is_directed == 'U' ){
        int count = 0 ; 
        listnode *tm = v.next ; 
        if ( tm == NULL ){
            
            return 0 ; 
        }else{
            listnode *tmpp = tm ; 
            while( tm  != NULL ){
                count++;
                tm = tm -> nextnode ; 

            }
            return count  ; 
        }
    }else{
        printf("\n0 ans as classification already made for in and out degree\n");
    };
    return 0 ; 

}

int in_degree(int **adj_mat , int vertex ){
    int count  = 0 ; 
    for( int j = 0 ; j < vertice ; j++ ){
            if ( adj_mat[j][vertex] == 1 ){
                count++ ; 
            }
    }
    return count ; 
        
}

int out_degree(int **adj_mat , int vertex){
    int count  = 0 ; 
    for( int j = 0 ; j < vertice ; j++ ){
            if ( adj_mat[vertex][j] == 1 ){
                count++ ; 
            }
    }
    return count ; 
}

int no_of_edge(graph *graph , int **adj_mat ){
    int count = 0 ; 
    if( graph->is_directed == 'U' ){
        for ( int i = 0 ; i < vertice ; i++ ){
            for ( int j = i ; j < vertice ; j++ ){
                if ( adj_mat[i][j] == 1 ){
                    count++ ; 
                }
            }
        }
    }else{
        for ( int i = 0 ; i < vertice ; i++ ){
            for ( int j = 0 ; j < vertice ; j++ ){
                if ( adj_mat[i][j] == 1 ){
                    count++ ; 
                }
            }
        }
    }
    return count ; 
}

int adj_vertice(ver_node v){
    int count = 0 ; 
    listnode *tm = v . next ; 
    if ( tm == NULL ){
        
        return 0 ; 
    }else{
        listnode *tmpp = tm ; 
        while( tm  != NULL ){
            count++;
            tm = tm -> nextnode ; 

        }
        return count  ; 
    }
}


void check_visitBFS(graph *graph , int val ){
    for( int i = 0 ; i < vertice ; i++ ){
        if( graph->vtx_array[i].vertex == val ){
            graph->vtx_array[i].is_visitedBFS = true ; 
        }
        listnode *nodecheck = graph->vtx_array[i].next ; 
        while( nodecheck != NULL ){
             if( nodecheck->val  == val ){
                nodecheck->BFS_visit = true  ; 
            }
            nodecheck = nodecheck->nextnode ; 
        }
    }

}


void traverse_BFS(graph *graph , int startidx ){
    int *queue = (int*)malloc( 100 * sizeof( int ));
    Enque(queue , startidx );
    while( !isEmpty(queue)){
        int temp = Dequeue(queue);
        printf("%d,," , temp);
        listnode *templist = graph->vtx_array[temp].next;
        // graph->vtx_array[temp].is_visitedBFS = true ; 

        while( templist != NULL ){
            if( templist->BFS_visit == false ){
                Enque(queue , templist->val);
                check_visitBFS(graph  , templist->val ); 
            }
            
            templist = templist->nextnode ; 
        }

        
    }
}


void check_visitDFS(graph *graph , int val ){
    for( int i = 0 ; i < vertice ; i++ ){
        if( graph->vtx_array[i].vertex == val ){
            graph->vtx_array[i].is_visitedDFS = true ; 
        }
        listnode *nodecheck = graph->vtx_array[i].next ; 
        while( nodecheck != NULL ){
             if( nodecheck->val  == val ){
                nodecheck->DFS_visit = true  ; 
            }
            nodecheck = nodecheck->nextnode ; 
        }
    }

}


void traverse_DFS(graph *graph , int startidx ){
    printf("%d,",startidx);
    graph->vtx_array[startidx].is_visitedDFS = true ; 
    
    listnode *temp = graph->vtx_array[startidx].next ; 
    
    check_visitDFS(graph  , temp->val ); 
    while( temp != NULL ){
        if ( temp->DFS_visit == false ){
            printf("]]%d,--",temp->val);
            traverse_DFS(graph , temp->val);  
        }; 
        temp = temp->nextnode  ; 
        
    }
    return ; 
}


int main(){
    fptr = fopen( "graphBFSfile.txt", "r");
    if( fptr == NULL ){
        printf("\nfile not found\n");
    };

     
    fscanf(fptr , "%c" , &graph_dir);
    fscanf(fptr , "%d" , &vertice);

    int **adj_mat ; 
    adj_mat = creatematrix(vertice);
    graph *graph = create_graph(vertice); 
    create_list(graph , adj_mat);
    printadj_list(graph);
    traverse_BFS(graph , 1 );
    printf("\n");
    traverse_DFS(graph , 1);
       
   
   
    
    
    
    
    fclose(fptr);
    return 0  ; 
}