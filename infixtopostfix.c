#include <stdio.h>
#include <string.h>
#include "charstack.h"

int prec(char c ){
    switch(c){
        case '+' :
        case '-' :return 1 ; 
        case '*' :
        case '/' :return 2 ; 
        case '^' :return 3 ; 
        case '(' :return -100 ; 
        case ')' :return -200 ; 
    }
    return -1 ; 
    
}
int main(){
    initiate() ; 
    printf("enter infix \n");
    char str[9898]  ; 
    char res[9898]  ; 
    fgets(str,sizeof(str) , stdin);
    printf("%s", str);
    int i = 0 ; 
    int j = 0 ; 
    int count =  0 ; 
    while( str[i] != '\0'){
        // printstack(); 
        if ( prec(str[i]) == -1 ){
            res[j++] = str[i] ; 
        }
        else if(  prec(str[i]) == -100 ){
            push(str[i]);
        }
        else if(  prec(str[i]) == -200 ){
            while( prec(peek()) != -100  ){
                res[j++] = pop() ; 
            }
            push(str[i]);
            if( isEmpty() == 1 ){
                count = 0 ; 
            }else{
                count = prec(peek());
            }
        }
        else{
            if( prec(str[i]) > count ){
                push( str[i]);
                count = prec(str[i]);
            }else{
                while(!isEmpty() && prec(str[i]) <=  count ){
                    res[j++] = pop() ; 
                }
                push(str[i]);
                count = prec(str[i]);
            }
        }
        i++ ; 
    }
    while( !isEmpty()){
        res[j++] = pop()  ; 
    }
    printf("%s " , res);


    return 0 ; 



}