#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 
FILE *fptr ; 
char graph_dir ;
int vertice ;
typedef struct ln{
    int val ; 
    struct ln *nextnode ; 
} listnode ; 

typedef struct nd{
    int is_visited ; 
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
        newgraph->vtx_array[i].is_visited = 0 ; 
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

int main(int argc , char *argv[] ){
    fptr = fopen(argv[1] , "r");
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

    if( graph->is_directed == 'U' )
    { 
        int key ; 
        printf("\ncheck degree of a node \nenter vertex :\n");
        scanf("%d",&key);
        printf("\ndegree of node %d : %d\n" , key , find_degree( graph , graph->vtx_array[key]));
    }

    if( graph->is_directed == 'D' )
    {    int key1 ; 
        printf("\ncheck in degree of a node \nenter vertex :\n");
        scanf("%d",&key1);
        printf("\nin - degree of node %d : %d\n" , key1 , in_degree( adj_mat , key1));
        
        int key2 ; 
        printf("\ncheck out degree of a node \nenter vertex :\n");
        scanf("%d",&key2);
        printf("\nout - degree of node %d : %d\n" , key2 , out_degree( adj_mat , key2));

    }
    printf("no of edges  : %d\n" , no_of_edge( graph , adj_mat));


    int key3 ; 
    printf("\ncheck adjancent vertices \nenter vertex :\n");
    scanf("%d",&key3);
    printf("\nno of adjacent vertices  %d : %d\n" , key3 , adj_vertice( graph->vtx_array[key3]));
    
   
   
    
    
    
    
    fclose(fptr);
    return 0  ; 
}