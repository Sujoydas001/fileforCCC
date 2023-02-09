/* PROGRAM TO BUILD BINARY TREE FROM INORDER AND PREORDER TRAVERSAL */
/* TRAVERSE THE PREORDER ARRAY ELEMENTS ONE BY ONE , CREATE A NEW NODE FOR THE VALUE , FIND THE ELEMENTS BEFORE THE ELEMENT AND RECURSIVELY CALL THE FUNCTION "function()" 
UNTIL REACH A CONDITION FOR EMPTY ARRAY */

#include <stdio.h>
#include <stdlib.h>




typedef struct nd{
    char val ; 
    struct nd *lch ; 
    struct nd *rch ; 
} node ; 

node* newnode(char c ){
    node *next = malloc(sizeof(node));
    next->val = c ; 
    next->lch = NULL ; 
    next->rch = NULL ; 
    return next ; 
}

int searchval(char in[] , int strt , int end , char c){
    int i  ; 
    for( int i = strt ; i< end ; i++ ){
        if( in[i] == c){
            return i ; 
        }
    }

}

node* function(char pre[] , char in[], int l , int r ){
    if( l > r  ){
        return NULL ; 
    }

    static int idx  = 0 ; 
    char find = pre[idx++];
    node *rootnode = newnode(find);
    if ( l == r ){
        return rootnode ; 
    };

    int findidx = searchval(in , l ,  r , rootnode->val );
    rootnode->lch = function(pre,in , l , findidx - 1  );
    rootnode->rch = function(pre,in , findidx + 1  , r   );

    return rootnode ; 

}



void inorderTraverse(node *root ){
    if ( root == NULL ){
        return ; 
    };
    inorderTraverse(root->lch);
    printf("%c,",root->val );
    inorderTraverse(root->rch);
}
int main(){
    char preorder[] = "abdhicefg" ;
    char inorder[] = "hidbaecfg" ;
    int size = sizeof(inorder) / sizeof(inorder[0]);
    node *root = function(preorder , inorder , 0 , size - 1 );

    inorderTraverse(root);


    return 0 ;
}