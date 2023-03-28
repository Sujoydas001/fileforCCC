#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 10 

typedef struct stn{
    char data ; 
    int index ; 
    struct stn *nextnode ;
    struct stn *prevnode ;  
}stackNode_char ; 

typedef struct st{
    int size ; 
    struct stn *top ; 
    int capacity ; 
}stack_char ; 

bool isFull(stack_char *st ){
    if( st->size == st->capacity ){
        printf("\nstack overflow\n");
        return true ; 
    };
    return false ; 
}
bool isEmpty( stack_char *st ){
    if( st->size == 0 || st->top == NULL ){
        printf("\nstack empty\n");
        return true ; 
    }
    return false ; 
}
stack_char* initiate(){
    stack_char *st = (stack_char*)malloc(sizeof(stack_char));
    st->capacity = MAXSIZE ; 
    st->size = 0 ; 
    st->top = NULL ; 
    return st ; 
} ; 
stackNode_char* newnode(char element ){
    stackNode_char *new_node = (stackNode_char*)malloc(sizeof(stackNode_char));
    new_node->data = element ; 
    new_node->nextnode = NULL ; 
    new_node->prevnode = NULL ; 
    return new_node ; 
}
void push(stack_char *st , char element ){
    if( !isFull(st ) ){
        if( st->top == NULL ){
            st->top = newnode(element) ; 
            st->top->index = 0 ; 
            st->size = 1 ; 
        }else{
            st->top->nextnode = newnode(element) ; 
            st->top->nextnode->index = (st->top->index) + 1 ; 
            st->top->nextnode->prevnode = st->top ;   
            st->top = (st->top)->nextnode  ; 
            (st->size)++ ; 
        }
        return ; 

    }
    printf("\nstack overflow\n");
    return ; 
};
char pop(stack_char *st){
    if( !isEmpty(st)){
        stackNode_char *todel = st->top ; 
        st->top = (st->top)->prevnode ; 
        st->size-- ; 
    }
    return '😟' ; 
} ; 
char peek(stack_char *st){
    if( !isEmpty(st)){
        return st->top->data ; 
    }
    return '😒'; 
} ; 
void printStack(stack_char *st){
    if( isEmpty(st)){
        return ; 
    }
    stackNode_char *temp = st->top ; 
    for( int i = 0 ; i < st->size ; i++ ){
        printf("%c\t" , temp->data ) ; 
        temp = temp->prevnode ; 
    };
    printf("\n");
    return ; 
} ; 



// int main(){
//     // int idx = 0 ; 
//     stack_char *stack = initiate() ; 
//     isEmpty(stack);
//     push(stack,'a');
//     push(stack,'b');
//     push(stack,'c');
//     push(stack,'d');
//     push(stack,'e');
//     push(stack,'f');
//     push(stack,'g');
//     push(stack,'h');
//     push(stack,'i');
//     push(stack,'j');
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     printf("\n%c\n" , peek(stack));
//     pop(stack);
//     printStack(stack);
//     return 0 ; 
// }

