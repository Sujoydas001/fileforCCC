#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct nd {
	int data ;
	struct nd *left  ;
	struct nd *right ;
    int thread ;

} Node ;


Node *insertBST(Node *root ,  int key ){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key ;
	newnode->left = NULL ;
	newnode->right = NULL ;
	newnode->thread = 0 ;
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

Node* rightMost(Node *root){
    Node* max = root;
    while(max &&  max.right != NULL ){
        /*max = root ;*/
        max = max->right ;

    }
    return max ;
}

void morris_traversal_inorder(Node *root ){

    Node *curr = root ;
    while( curr != NULL ){
        if ( curr->left == NULL ){
            printf("%d,",curr->data);
            curr = curr->right ;
        }else if( curr->thread == 0 ){

            Node *temp = rightMost(curr->left);
            temp->right = root ;
            curr->thread = 1 ;
            curr = curr->left ;
        }else{
            printf("%d,",curr->data);
            curr = curr->right ;
        }
    }
}

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
    morris_traversal_inorder( root );
}
