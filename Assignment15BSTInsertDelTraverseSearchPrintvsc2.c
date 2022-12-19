#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct nd {
	int data ;
	struct nd *left  ;
	struct nd *right ;
    bool thread  ; 

} Node ;

Node* rightMost(Node *root){
    Node* max = root;
    while(  max->right != NULL ){
        /*max = root ;*/
        max = max->right ;

    }
    return max ;
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
    return root ; 
}



Node *insertBST(Node *root ,  int key ){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key ;
    newnode->thread = false ;
	newnode->left = NULL ;
	newnode->right = NULL ;
	if ( root == NULL ){
		return newnode ;
	}else {
		Node *curr = root ;
		while ( 1 ){

			if ( key <= curr->data ){
				if ( curr ->left != NULL ){
					curr = curr->left ;
				}else{
					curr->left = newnode ;
					break ;
				};
			}else {

				if ( curr ->right != NULL ){
					curr = curr->right ;
				}else{
					curr->right = newnode ;
					break ;
				};
			};

		};
		return root ;

	};



}
void  inorder(Node *root ){
	if ( root == NULL ){
		return  ;
	}
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);

}


// void morris_traversal_inorder(Node *root ){
    
//     Node *curr = root ; 
//     while( curr != NULL ){
//         if ( curr->left == NULL ){
//             printf("%d,",curr->data);
//             curr = curr->right ; 
//         }else if( curr->thread == false ){
            
//             Node *temp = rightMost(curr->left);
//             temp->right = curr ; 
//             curr->thread = true ; 
//             curr = curr->left ; 
//         }else{
//             printf("%d,",curr->data);
//             curr = curr->right ; 
//         }
//     }
// }

int main(){
    int n = 10 ; 
    Node *root = NULL ; 
    for (int i = 0 ; i < n ;i++ ){
        int m = rand()% 59 ;
        printf("%d,",m);
        root = insertBST(root, m);

    }
    printf("\n");
    inorder(root);
    printf("\n");
    // morris_traversal_inorder( root );
    printf("neter");
    int key ; 
    scanf("%d" , &key);
    deleteNode(root,key);
    inorder(root);
    // morris_traversal_inorder( root );
}