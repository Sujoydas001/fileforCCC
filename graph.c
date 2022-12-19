#include <stdio.h>
#include <stdlib.h>


typedef struct lnde{
    int dest ;
    struct lnde *nextnode ;
}listnode ;

typedef struct vtxnde{
    int visited ;
    int vertexval ;
    listnode  *next ;
}vertexnode ;

typedef struct grp{
    int v ;
    vertexnode *struct_arrObj;
}graph ;

graph* create_graph(int v){
    graph *newgraph = (graph*)malloc(v * sizeof(graph));
    newgraph -> v = v ;
    for( int i = 0 ; i < v ; i++ ){
        newgraph -> struct_arrObj[i].visited = 0 ;
        newgraph -> struct_arrObj[i].vertexval = -9 ;
        newgraph -> struct_arrObj[i].next = NULL  ;
    }
    return newgraph ;
}

listnode* addNode(int dest ){
    listnode *newlistnode = (listnode*)malloc(sizeof(listnode));
    newlistnode -> dest = dest ;
    newlistnode -> nextnode = NULL ;

    return newlistnode ;
}
graph* add_edge(graph *graph , int src , int dest ){
    listnode *newedge = addNode(dest);
    listnode *temp = graph ->struct_arrObj[src].next ;

    while( temp != NULL ){
        temp = temp -> nextnode ;
    }
    temp -> nextnode = newedge ;
    return graph ;

}

void print_adjacentlist( graph *graph ){
    printf("ad");
    int vertice = graph->v ;
    for ( int i = 0 ; i < vertice ; i++ ){
        printf("%d \t " , graph->struct_arrObj[i].vertexval);
        listnode *temp = graph->struct_arrObj[i].next ;
        while( temp != NULL ){
            printf("%d ->  " , temp->dest );
            temp = temp->nextnode ;
        }
        printf("\n");
    }
}

int main(){
    graph *graph1 = create_graph(5);

    print_adjacentlist(graph1);
    printf("d");
    print_adjacentlist(graph1);
    graph1 = add_edge(graph1, 0, 1);
    print_adjacentlist(graph1);
    add_edge(graph1, 0, 4);
    add_edge(graph1, 1, 2);
    add_edge(graph1, 1, 3);
    add_edge(graph1, 1, 4);
    add_edge(graph1, 2, 3);
    add_edge(graph1, 3, 4);

    print_adjacentlist(graph1);

    return 0 ;
}
