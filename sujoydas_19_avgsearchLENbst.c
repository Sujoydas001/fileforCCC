#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct nd {

    /*creating node of a bst , thread included to perform morris inorder traversal */
	int data ;
	struct nd *left  ;
	struct nd *right ;
    bool thread  ; 

} Node ;

Node *insertBST(Node *root ,  int key ){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key ;
    newnode->thread = false ; 
	newnode->left = NULL ;
	newnode->right = NULL ;
	if ( root == NULL ){      /*creating the first node of the bst*/
		return newnode ;
	}else {
		Node *curr = root ;     /*while inserting new element first check if the key value is*/
                                /* less or grater than the root val and respectively recurse to the corresponding subtree*/
		while ( 1 ){

			if ( key <= curr->data ){
				if ( curr ->left != NULL ){
					curr = curr->left ;            /*until leaf is found , traverse through the tree */
				}else{
					curr->left = newnode ;       /*if leaf found , set the new node and break*/
					break ;
				};
			}else {

				if ( curr ->right != NULL ){       /*until leaf is found , traverse through the tree */
					curr = curr->right ;
				}else{
					curr->right = newnode ;         /*if leaf found , set the new node and break */
					break ;
				};
			};

		};
		return root ;

	};



}



/*recursive function to print the root , its leftsubtree-root , its rightsubtree-root respectively*/
void  inorder(Node *root ){
	if ( root == NULL ){
		return  ;
	}
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);

}


/*searches for a element in the tree recursively and return the nodes path lengthfrom the root */
int search( Node *root , int key , int count ){
    if ( root == NULL ){
        printf("\nnot found \n");
        return 0 ; 
    };
    if ( root->data == key ){
        // printf("%d found__%d\n" , key , count );
        return count; 
    }
    if( root->data < key ){
        // printf("\ngoing right\n");
        count++ ; 
        search(root->right ,key ,count);
        
    }else{
        // printf("\ngoing leftt\n");
        count++ ; 
        search(root->left,key , count );
        
    };
    
}


void avg_search_length(){
        Node *newhead = NULL ; 
        printf("\n/////calculate avg search length in a bst : enter no of numbers to add :");
        int no ; 
        double sum = 0 ; 
        scanf("%d",&no);
        for ( int i = 0 ; i < no ; i++ ){
            int m ; 
            printf("\n/////enter number :");
            scanf("%d",&m);
            newhead = insertBST(newhead, m);
            sum += search(newhead , m , 1 );
            

        }
        inorder(newhead);
        printf("the avg : %lf",sum / no );
        free(newhead);

}
/*this algo cant be used if there are more than one node with same value  cause then the node, nearest to the root(among the nodes with same value ) is considered every time*/
/*driver function */
int main(){
    avg_search_length();
    printf("\n process finished\n");





	return 0 ;
}
