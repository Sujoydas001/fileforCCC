#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nd {
	int data ;
	struct nd *left  ;
	struct nd *right ;
    bool thread  ;
    int height ;  

} Node ;

Node* rightMost(Node *root){
    Node* max = root;            /*iterate until find the last rightmost node of the tree starting from the given root*/
    while(  max->right != NULL ){
        max = max->right ;

    }
    return max ;
}

int max(int a , int b ){
    return a> b ? a : b ; 
}
int height(Node *root ){
    if ( root == NULL ){
        return 0 ; 
    }
    return 1 + max(height(root->left) , height(root->right));
}


Node* getnewnode(int key ){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key ;
    newnode->thread = false ;
	newnode->left = NULL ;
	newnode->right = NULL ;
    newnode->height = 1 ; 
    return newnode ; 
}


int bal_factor(Node *root ){
    if( root == NULL ){
        return 0 ;
    }
    return height(root->left) - height(root->right) ; 
}

Node* leftrotate(Node *root ){
    Node *y = root ; 
    Node *x = y->right ; 
    Node *T = x->left ; 
    x->left = y ; 
    y->right = T ; 
    x->height = height(x);
    y->height = height(y);
    return x ; 
}

Node* rightrotate(Node *root ){
    Node *y = root  ; 
    Node *x = y->left ; 
    Node *T = x->right ; 
    x->right = y ; 
    y->left = T ; 
    x->height = height(x);
    y->height = height(y);

    return x ; 
}

Node *insertBSTwith_balance(Node *root ,  int key ){

    Node *newnode = getnewnode(key);
	 if (root == NULL){
        return(newnode);
    };
    if (key < root->data ){
        root->left  = insertBSTwith_balance(root->left, key);
    }else if (key > root->data ){
        root->right = insertBSTwith_balance(root->right, key);
    }else{ 
        return root;
    };
    
    root->height = height(root);

    int balance = bal_factor(root);
    if ( balance > 1 && key < root->left->data ){
        return rightrotate(root); 
    }
    if ( balance < -1 && key > root->right->data ){
        return leftrotate(root); 
    }
    if ( balance > 1 && key > root->left->data ){
        root->left =  leftrotate(root->left); 
        return rightrotate(root);
    }
    if ( balance <-1 && key < root->right->data ){
        root->right = rightrotate(root->right) ; 
        return leftrotate(root); 
    }
	return root ;




}

Node* deleteNode(Node *root , int key ){
    if ( root == NULL ){
        printf("\nnot found\n");
        return NULL;
    }
    if ( root->data  > key ){
        root->left = deleteNode(root->left, key );
    }else if ( root->data < key ){
        root->right = deleteNode(root->right, key );
    }else{
        if ( root->left == NULL ){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if ( root->right == NULL ){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *nt =  rightMost(root->left);
        root->data = nt->data ; 
        root->left = deleteNode(root->left , nt->data);
    }

    root->height = height(root);

    int balance = bal_factor(root);
    if ( balance > 1 && bal_factor(root->left)>= 0  ){
        return rightrotate(root); 
    }
    if ( balance < -1 && bal_factor(root->right) <= 0  ){
        return leftrotate(root); 
    }
    if ( balance > 1 && bal_factor(root->right) < 0 ){
        root->left =  leftrotate(root->left); 
        return rightrotate(root);
    }
    if ( balance <-1 && bal_factor(root->right) > 0 ){
        root->right = rightrotate(root->right) ; 
        return leftrotate(root); 
    }
    return root ; 
}

void  inorder(Node *root ){
	if ( root == NULL ){
		return  ;
	}
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);

}

void preorder(Node *root ){
    if ( root == NULL ){
        return ; 
    }
    printf("%d,",root->data);
    preorder(root->left);
    
    preorder(root->right);

}

int main(){
    int n = 6 ; 
    Node *root = NULL ; 
    // for (int i = 0 ; i < n ;i++ ){
    //     int m = rand()% 59 ;
    //     printf("%d,",m);
    //     root = insertBSTwith_balance(root, m);

    // }
    root = insertBSTwith_balance(root, 9);
    root = insertBSTwith_balance(root, 5);
    root = insertBSTwith_balance(root, 10);
    root = insertBSTwith_balance(root, 0);
    root = insertBSTwith_balance(root, 6);
    root = insertBSTwith_balance(root, 11);
    root = insertBSTwith_balance(root, -1);
    root = insertBSTwith_balance(root, 1);
    root = insertBSTwith_balance(root, 2);
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    root = deleteNode(root , 10);


    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    
    
    
    return 0 ; 
}