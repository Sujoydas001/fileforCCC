#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100 
#define GRAPHDIR true  
#define SIZEOFGRAPH 10 



typedef struct lnode{
    int destination ; 
    struct lnode *nextNode ; 
} listNode ; 
typedef struct vnode{
    listNode *next ; 
} verNode ;
typedef struct grp{
    bool direction ;
    int noofVertex ; 
    verNode vertexArray[MAXSIZE] ;   

} graph ; 
graph* createGraph(int noofvertex ){
    graph* newgrp = (graph*)malloc(sizeof(graph));
    newgrp->direction = GRAPHDIR ; 
    newgrp->noofVertex = noofvertex ; 
    for( int i = 0 ; i < noofvertex ; i++ ){
        newgrp->vertexArray[i].next = NULL ;
    }
    return newgrp ; 
    
}
listNode* addNewNode( int value ){
    listNode *temp = (listNode*)malloc(sizeof(listNode));
    temp->destination = value ; 
    temp->nextNode = NULL ; 
    return temp ; 
}
graph* insertEdge( graph *grp , int src , int dst ){
    verNode tempvertex = grp->vertexArray[src];
    listNode *templistNode = tempvertex.next ; 
    if( templistNode == NULL ){
        
        templistNode = addNewNode(dst);
        
        printf("%d", templistNode->destination);
        printf("hes");
    }else{
        while( templistNode->nextNode != NULL ){
            templistNode = templistNode->nextNode ; 
        }
        templistNode->nextNode = addNewNode(dst);
        printf("%d", templistNode->nextNode->destination);
    }
    printf("%d\n", grp->noofVertex);
    return grp ; 
}
void printAdjList( graph *grp ){
    int size  = grp->noofVertex  ; 
    for( int i = 0  ; i < size ; i++ ){
        printf("%d----",i );
        listNode *temp = grp->vertexArray[i].next ; 
        
        while( temp != NULL ){
            printf("%d->>",temp->destination );
            temp = temp->nextNode ; 
        }
        printf("\n");
    }
    
}


int main(){
    printf("hell\n");
    graph *graph = createGraph(SIZEOFGRAPH);
    printAdjList(graph);
    printf("hell\n");
    graph = insertEdge(graph,1,2);
    // printf("%d" , graph->noofVertex);
    if(  graph->vertexArray[1].next == NULL ){
        printf("not");
    }
    printf("%d" , graph->vertexArray[1].next->destination);
    
    // graph = insertEdge(graph , 1,4);
    // graph = insertEdge(graph , 2,3);
    // graph = insertEdge(graph , 2,1);
    // graph = insertEdge(graph , 2,8);
    // graph = insertEdge(graph , 2,5);
    // graph = insertEdge(graph , 3,2);
    // graph = insertEdge(graph , 3,4);
    // graph = insertEdge(graph , 3,10);
    // graph = insertEdge(graph , 3,9);
    // graph = insertEdge(graph , 4,1);
    // graph = insertEdge(graph , 4,3);
    // graph = insertEdge(graph , 5,2);
    // graph = insertEdge(graph , 5,7);
    // graph = insertEdge(graph , 5,8);
    // graph = insertEdge(graph , 5,6);
    // graph = insertEdge(graph , 6,5);
    // graph = insertEdge(graph , 7,8);
    // graph = insertEdge(graph , 7,2);
    // graph = insertEdge(graph , 7,5);
    // graph = insertEdge(graph , 8,2);
    // graph = insertEdge(graph , 8,7);
    // graph = insertEdge(graph , 8,5);
    // graph = insertEdge(graph , 9,3);
    // graph = insertEdge(graph , 10,3);
    // printAdjList(graph);
    

    return 0 ; 
}