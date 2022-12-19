/*implementation of two stack using 1 single array */



#include <stdio.h>
#include <stdlib.h>
#define size 20 




int *twostack ; 
int top1 = size/2 , top2 = size/2 - 1  ; 

void isFull1(){
    if( top1 == 0 ){
        printf("stack 1 is full ");
        return ; 
    }
}
void isFull2(){
    if( top2 == size - 1){
        printf("stack 2 is full ");
        return ; 
    }
}

void isEmpty1(){
    if( top1 == size /2 ){
        printf("\nstack 1 empty\n");
        return ; 
    }
}

void isEmpty2(){
    if( top2 == size /2 - 1 ){
        printf("\nstack 2 empty\n");
        return ; 
    }
}

void initiate(){
    twostack = (int*)malloc( size * sizeof(int));
    for( int i = 0 ; i < size ; i++ ){
        twostack[i] = -999 ; 
    }
}

void push1(int key ){
    if( top1 >  0 ){
        twostack[--top1] = key ; 
        // printf("%d___", top1);
    }else {
        printf("\nstack overflow1\n");
        isFull1(); 
    }
}

void push2(int key ){
    if( top2 < size -1 ){
        twostack[++top2] = key ; 
    }else {
        printf("\nstack overflow2\n");
        isFull2(); 
    }
}

int pop1(){
    if( top1 < size /2   ) {
        return twostack[top1++];
    }else{
        printf("\nstack underflow1\n");
        isEmpty1(); 
        return -99999 ; 
    }
}


int pop2(){
    if( top2 >= size /2  ) {
        return twostack[top2--];
    }else{
        printf("\nstack underflow2\n");
        isEmpty2(); 
        return -99999  ;
    }
}

void printstack(){
    printf("\n\n");
    for ( int i = top1 ; i < size/2 ; i++ ){
        printf("%d," , twostack[i]);
    };
    printf("\n\n");
    for ( int i = size/2  ; i <= top2 ; i++ ){
        printf("%d," , twostack[i]);
    };
    printf("\n\n");
}
int main(){
    initiate(); 
    printstack(); 
    push1(54);
    push1(4);
    push1(50);
    push1(544);
    push1(74);
    push1(45);
    push1(854);
    push1(20);
    push1(89);
    push1(4);
    // push1(89);
    push2(90);
    push2(54);
    push2(4);
    push2(50);
    push2(544);
    push2(74);
    push2(45);
    push2(854);
    push2(20);
    push2(89);
    // push2(4);
    pop1();
    pop1();
    pop1();
    pop1();
    pop1();
    pop1();
    pop1();
    pop1();
    pop1();
    pop1();
    pop1();
    // // pop1();pop1();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2(); 
    pop2();
    pop2(); 
    printstack(); 
}