#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int iosize  ; 
#define SIZE 10 

typedef struct nd{
    int data ; 
    struct nd *next ; 
}node ; 

typedef struct ht{
    node *nextnode ; 
}hashtable  ;

node *newnode(int k ){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k ; 
    newnode->next = NULL ; 
    return newnode ; 
}

void insert( hashtable h[] , int k){
    int pos = k % SIZE ; 
    node *temp = h[pos].nextnode ; 
    if(temp == NULL ){
        h[pos].nextnode = newnode(k); 
    }else{
        while(temp->next != NULL  ){
            temp = temp->next ; 
        }
        temp->next = newnode(k);
    }

}

void print(hashtable h[] ){
    printf("\nhashtable\n");
    for( int i = 0 ; i < SIZE ; i++ ){
        printf("%d : " , i );
        node *tmep = h[i].nextnode ; 
        while( tmep != NULL ){
            printf("%d -> " , tmep->data );
            tmep = tmep->next ; 
        }
        printf("\n");
    }
    printf("\n\n");
}


// void Hash_search(hashtable h[] , int k );



int main(){

    int iosize = SIZE ; 
    hashtable h_table[SIZE];
    for ( int i = 0 ; i < SIZE ; i++ ){
        h_table[i].nextnode = NULL ; 
    }

   

    insert(h_table , 12 ); 
    insert(h_table , 112 ); 
    insert(h_table , 113 ); 
    insert(h_table , 114 ); 
    insert(h_table , 115 ); 
    insert(h_table , 124 ); 
    insert(h_table , 212 ); 
    insert(h_table , 213 ); 
    insert(h_table , 112 ); 
    insert(h_table , 212 ); 
    insert(h_table , 10000); 
    print(h_table);
    // Hash_search(h_table, 112 );



    return 0 ;

}