#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 10 

typedef struct stn{
    int data ; 
    int index ; 
    struct stn *nextnode ;
    struct stn *prevnode ;  
}stackNode_int ; 

typedef struct st{
    int size ; 
    struct stn *top ; 
    int capacity ; 
}stack_int  ; 

bool isFull(stack_int *st ){
    if( st->size == st->capacity ){
        printf("\nstack overflow\n");
        return true ; 
    };
    return false ; 
}
bool isEmpty( stack_int *st ){
    if( st->size == 0 || st->top == NULL ){
        printf("\nstack empty\n");
        return true ; 
    }
    return false ; 
}
stack_int* initiate(){
    stack_int *st = (stack_int*)malloc(sizeof(stack_int));
    st->capacity = MAXSIZE ; 
    st->size = 0 ; 
    st->top = NULL ; 
    return st ; 
} ; 
stackNode_int* newnode(int element ){
    stackNode_int *new_node = (stackNode_int*)malloc(sizeof(stackNode_int));
    new_node->data = element ; 
    new_node->nextnode = NULL ; 
    new_node->prevnode = NULL ; 
    return new_node ; 
}
void push(stack_int *st , int element ){
    if( !isFull(st ) ){
        if( st->top == NULL ){
            st->top = newnode(element) ; 
            st->size = 1 ; 
            st->top->index = 0 ; 
        }else{
            st->top->nextnode = newnode(element) ; 
            st->top->nextnode->index = (st->top->index) + 1  ; 
            st->top->nextnode->prevnode = st->top ;   
            st->top = (st->top)->nextnode  ; 
            (st->size)++ ; 
        }
        return ; 

    }
    printf("\nstack overflow\n");
    return ; 
};
int pop(stack_int *st){
    if( !isEmpty(st)){
        stackNode_int *todel = st->top ; 
        st->top = (st->top)->prevnode ; 
        free(todel);
        st->size-- ; 
    }
    return -1 ; 
} ; 
int peek(stack_int *st){
    if( !isEmpty(st)){
        return st->top->data ; 
    }
    return -1; 
} ; 
void printStack(stack_int *st){
    if( isEmpty(st)){
        return ; 
    }
    stackNode_int *temp = st->top ; 
    for( int i = 0 ; i < st->size ; i++ ){
        printf("%d\t" , temp->data ) ; 
        temp = temp->prevnode ; 
    }
    printf("\n");
    return ; 
} ; 



// int main(){
//     int idx = 0 ; 
//     stack_int *stack = initiate() ; 
//     isEmpty(stack);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     push(stack,++idx);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%d\n" , peek(stack));
//     return 0 ; 
// }

