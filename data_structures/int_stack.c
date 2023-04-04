#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 5 
int top = -1 ; 
int stack[MAXSIZE] ; 
bool isEmpty(){
    if( top == -1 ){
        printf("\nempty\n");
        return true ; 
    }
    return false ; 
}
bool isFull(){
    if( top == MAXSIZE - 1 ){
        printf("\nempty\n");
        return true ; 
    }
    return false ; 
}
void push(int data ){
    if( !isFull()){
        stack[++top] = data ; 
    }
    return ; 
}
int pop(){
    if( !isEmpty() ){
       return stack[top--] ; 
    }
    return -96 ; 

}
int peek(){
    if( isEmpty()){
        return -96 ; 
    }
    return stack[top] ; 
}
void display(){
    if( isEmpty()){
        return ; 
    }
    for( int i = 0 ; i <= top ; i++  ){
        printf("%d," , stack[i]) ; 
    }
    printf("\n"); 
}

int main(){
    int exit  = 0 ; 
    char data ; 
    while( !exit ){
        printf("\n1.push\n2.pop\n3.peek\n4.exit\n") ;
        int choice ; 
        scanf("%d", &choice );
        switch (choice){
        case 1:
            printf("\nenter data: ");
            scanf("%d",&data);
            push(data);
            display() ;
            break;
        case 2:
            pop() ; 
            display() ;
            break ; 
        
        case 3:
            printf("peek => %d\n" , peek() );
            display() ;
            break ; 
        case 4:
            exit  = 1 ; 
        }
    }
    return 0 ; 
}