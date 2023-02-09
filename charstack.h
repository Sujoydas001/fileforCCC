#include <stdio.h>
#include <stdlib.h>
/*pointer variable 'stack' is an array on which push() pop() and other operations are done*/
/*bound is the initial size of stack */
/*top variable points to the last item entered in the stack */
int top = -1 ; 
int bound = 200 ; 
char *stack ;
/* initiate() function creates the stack of size 2 at first */
void initiate(){
    stack = (char*)malloc(bound * sizeof(char)); 
    // printf("stack initiated ...\n");
}

/* isEmpty() checks if the stack is empty or not */
int isEmpty(){
    if ( top == -1 ){
        printf("stack is empty ");
        return 1 ; 
    }else{
        return 0 ;
    }
}
/* isfull() checks if the stack is full or not , if full then calls the createnew() function  */
int isfull(){
    if ( top == bound - 1 ){
        printf("stack is full "); 
        return 1 ;
    }else {
        return 0 ; 
    };
}
/* push() function pushes new int to the stack */
void push( char item ){
    if ( top == bound - 1 ){
        isfull(item);
        return ; 
    }else{
        stack[++top] = item ; 
        // printf("pushed : %d \n",item);
    } 
}
/* pop() function pops new int to the stack */
char pop(){
    if ( !isEmpty()){
        return stack[top--];
    }else{
        isEmpty();          
    }
}
char peek(){
    if(!isEmpty()){
        return stack[top];
    }else{
        isEmpty();          
    }
}
/* printstack() prints the elemnts of the stack */
void printstack(){
    for ( int i = 0 ; i <= top ; i++){
        printf("%c\n" , stack[i] );
    }
    printf("\n");
}
