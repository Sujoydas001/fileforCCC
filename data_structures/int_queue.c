#include <stdbool.h>
#include <stdio.h>
#define MAXSIZE 5  

int queue[MAXSIZE] ; 
int rear = -1 ; 
int front = -1 ; 

bool isFull(){
    if( rear == MAXSIZE - 1 ){
     printf("\nfull\n");
        return true ; 
    }
    return false ; 
}
bool isEmpty(){
    if( rear == front ){
        printf("\nempty\n");
        return true ; 
    }
    return false ; 
}
void enque(int data ){
    if( !isFull() ){
        queue[++rear] = data ; 
    }
}
int deque(){
    if( !isEmpty()){
        return  queue[++front] ; 
    }
    return -101 ; 
}
int getFront(){
    if( !isEmpty()){
        return  queue[front+1] ; 
    }
    return -101 ; 

}
void display(){
    if( isEmpty() ){
        return ; 
    }
    for ( int i = front + 1 ; i <= rear ; i++ ){
        printf("%d , " , queue[i] );
    };
    printf("\n");
}

int main(){
    int exit  = 0 ; 
    char data ; 
    while( !exit ){
        printf("\n1.enque\n2.deque\n3.front\n4.exit\n") ;
        int choice ; 
        scanf("%d", &choice );
        switch (choice){
        case 1:
            printf("\nenter data: ");
            scanf("%d",&data);
            enque(data) ; 
            display() ;
            break;
        case 2:
            deque() ; 
            display() ;
            break ; 
        
        case 3:
            printf("peek => %d\n" , getFront() );
            display() ;
            break ; 
        case 4:
            exit  = 1 ; 
        }
    }
    return 0 ; 
}

