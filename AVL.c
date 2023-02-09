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

/*function to get the predecessor of a node */
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
/*function to get the height of a node */
int height(Node *root ){
    if ( root == NULL ){
        return 0 ; 
    }
    return 1 + max(height(root->left) , height(root->right));
}
/*using height() function print the height of a node with given key if exists */
void findheight(Node *root ,  int key ){
    if ( root == NULL ){
        return  ;
    }
    if ( key < root->data ){
        findheight(root->left , key );
    }else if ( key > root->data ){
        findheight(root->right , key );
    }else if( key == root->data ){
        printf("\nheight of Key :%d : %d\n " ,key , height(root));
        return ; 
    }else{
        printf("\n not found \n");
        return ; 
    }
    return ; 
}
/*return the balance factor of a node */
int bal_factor(Node *root ){
    if( root == NULL ){
        return 0 ;
    }
    return height(root->left) - height(root->right) ; 
}
/*usng the function print the balance factor of a node with the given key if exists */
void print_bal_factor(Node *root  , int key ){
    if ( root == NULL ){
        return  ;
    }
    if ( key < root->data ){
        print_bal_factor(root->left , key );
    }else if ( key > root->data ){
        print_bal_factor(root->right , key );
    }else if( key == root->data ){
        printf("\balance factor of Key  node :%d : %d\n " ,key , bal_factor(root));
        return ; 
    }else{
        printf("\n not found \n");
        return ; 
    }
    return ;
}
/*return a newnode with the given key */
Node* getnewnode(int key ){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key ;
    newnode->thread = false ;
	newnode->left = NULL ;
	newnode->right = NULL ;
    newnode->height = 1 ; 
    return newnode ; 
}


/*LL rotation */
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
/*RR rotation */
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
/*insert node and balance the whole tree upto the root via recurrsion*/
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
/*delete node and balance the whole tree upto the root via recurrsion*/
Node* deleteNodewith_balance(Node *root , int key ){
    if ( root == NULL ){
        printf("\nnot found\n");
        return NULL;
    }
    if ( root->data  > key ){
        root->left = deleteNodewith_balance(root->left, key );
    }else if ( root->data < key ){
        root->right = deleteNodewith_balance(root->right, key );
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
        root->left = deleteNodewith_balance(root->left , nt->data);
    }

    root->height = height(root);

    int balance = bal_factor(root);
    if ( balance > 1 && bal_factor(root->left) > 0  ){
        return rightrotate(root); 
    }
    if ( balance < -1 && bal_factor(root->left) < 0  ){
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
/*print the inorder traversal */
void  inorder(Node *root ){
	if ( root == NULL ){
		return  ;
	}
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);

}

int main(){
    Node *root = NULL ; 
    int exit = 0 ; 
    while( !exit ){
        printf("\n1) Insert a node in AVL tree\n2) Delete a node in AVL tree\n3) Display the AVL tree by inorder traversal \n4) Report the height of any node in AVL tree\n5) Report the balance factor of any node in AVL tree\n6) exit \n");
        int count  , key ; 
        scanf("%d",&count);
        switch (count ){
            case 1 : printf("\nenter no to insert : \n"); 
                    scanf("%d" , &key ); 
                    root = insertBSTwith_balance(root , key );
                    break ; 
            case 2 :printf("\nenter no to delete : \n");
                    scanf("%d" , &key ); 
                    root = deleteNodewith_balance(root , key );
                    break ;  
            case 3 : printf("\ninorder traversal : \n");
                    inorder(root);
                    break ; 
            case 4 : printf("\nheight of a node enter node value : \n");
                    scanf("%d" , &key );
                    findheight(root , key );
                    break ; 
            case 5 : printf("\nbalance factor of a node enter node value : \n");
                    scanf("%d" , &key );
                    print_bal_factor(root , key );
                    break ; 

            case 6 : exit = 1 ; 
                    break ; 
        }
    };

    
    
    return 0 ; 
}