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

/*return the max value among two numbers*/
int max(int a , int b ){
    return a>=b ? a : b ;
}
/*returns the height of the tree */
int height( Node *root ){
    if ( root == NULL ){
            return 0 ; 
    }
    return max(height(root->left) , height(root->right) ) + 1;
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
/*searches for a element in the tree recursively*/
void search( Node *root , int key ){
    
    if ( root == NULL ){
        printf("\nnot found \n");
        return  ; 
    };
    if ( root->data == key ){
        printf("%d found\n" , key );
        return ; 
    }
    if( root->data < key ){
        search(root->right ,key);
    }else{
        search(root->left,key);
    };
    
}

Node* rightMost(Node *root){
    Node* max = root;            /*iterate until find the last rightmost node of the tree starting from the given root*/
    while(  max->right != NULL ){
        max = max->right ;

    }
    return max ;
}

Node* deleteNode(Node *root , int key ){
    if ( root == NULL ){                        /*if root == null i.e reached the leaf node but did not find the element , print not found*/
        printf("\nnot found\n");
        return NULL;
    }
    if ( root->data  > key ){                           /*recursively reach the node to be deleted */
        root->left = deleteNode(root->left, key );
    }else if ( root->data < key ){                          
        root->right = deleteNode(root->right, key );
    }else{
        if ( root->left == NULL ){                        /*if left node of the root is null , return right subtree and viceversa*/
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if ( root->right == NULL ){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *nt =  rightMost(root->left);              /*if root node has both child,, then find the rightmost element */
                                                        /*of the left subtree and replace with the current node 
                                                        and recursively call the delete function for that subtree */
        root->data = nt->data ; 
        root->left = deleteNode(root->left , nt->data);
    }
    return root ; 
}

void morris_traversal_inorder(Node *root ){
    
    Node *curr = root ;                       /*iterate over the tree , while insertion of a new node thread of that node is initialized to false .
                                                if the left child of the NODE is null that means in inorder traversal that NODE is to be treated first.
                                                now if left child of the NODE is not null but thread == false i.e. we have to cover the left subtree 
                                                first but to make a pointer to the predecessor go to the rightmost node of the left subtree of the NODE 
                                                and make the thread to true for that NODE and go to left to cover the left subtree.
                                                else condition:::: if left node of the NODE is not null and the NODE has thread to true --> i.e 
                                                its left subtree covered, now print the node value and go to right child. here the right child will 
                                                point to the predecessor of that NODE */
    while( curr != NULL ){
        if ( curr->left == NULL ){
            printf("%d,",curr->data);
            curr = curr->right ; 
        }else if( curr->thread == false ){
            
            Node *temp = rightMost(curr->left);
            temp->right = curr ; 
            curr->thread = true ; 
            curr = curr->left ; 
        }else{
            printf("%d,",curr->data);
            curr = curr->right ; 
        }
    }
}

void check_function(){
    int n  ;
    printf("\neter no of random numbers to be generated: \n");
    scanf("%d",&n);
	int m ;
	time_t t ;
    srand(time(&t));
    double sum = 0 ; 
    int length = 0 ; 
	for ( int j = 0 ; j < 50 ; j++ ){         /*fifty times new numbers generated and inserted in the bst*/
	    printf("\n\n");
        Node *root = NULL ;
        printf("generated random numbers: \t");
        for ( int i = 0 ; i < n ; i++ ){
            m = rand() % 99999 ;                   /*random numbers generated from 0 to 99998 and inserted in the bst*/
            root = insertBST(root , m );
            printf("%d,", m );
        };
        length = height(root);         /*height measured*/
        printf("\nheight : %d\n",length);
        sum += length ;               
        printf("\tinorder :\t");
        inorder(root);

        free(root);
	};
    double avg = sum / ( 50 );
    
    printf("\ntotal sum of height : %lf\n" , sum);
    printf("\navarage: %lf\n" , avg);                /*avarage height calculated */
}

void search_function(){
        Node *newhead = NULL ; 
        printf("\n/////search an element in a bst : enter no of numbers to add (random) to the new BST :");
        int no ;
        scanf("%d",&no);
        for ( int i = 0 ; i < no ; i++ ){
            newhead = insertBST(newhead, rand() % 100);                    /*created new bst and numbers ranging from 0 to 99 are inserted randomly */

        }
        printf("\nthe new created tree has elements in inorder traversal: ");
        inorder(newhead);                       /*inorder traversal shown */
        printf("\nenter no to search : ");
        int key ; 
        scanf("%d", &key);
        search(newhead , key);
        free(newhead);

}

void del_function(){
    Node *newhead = NULL ; 
    printf("\n/////delete an element in a bst : enter no of numbers to add (random) to the new BST first :");
    int no ;
    scanf("%d",&no);
    for ( int i = 0 ; i < no ; i++ ){
        newhead = insertBST(newhead, rand() % 100);          /*created new bst and numbers ranging from 0 to 99 are inserted randomly */

    }
    printf("\nthe new created tree has elements in inorder traversal: ");
    inorder(newhead);
    printf("\nenter no to delete : ");
    int key ; 
    scanf("%d", &key);
    newhead = deleteNode(newhead , key);
    inorder(newhead);
    free(newhead);
}

void iterative_inorder(){
    Node *newhead = NULL ; 
        printf("\n/////iterative inorder traversal: in a bst : enter no of numbers to add (random) to the new BST :");
        int no ;
        scanf("%d",&no);
        for ( int i = 0 ; i < no ; i++ ){
            newhead = insertBST(newhead, rand() % 100);

        }
        printf("\nthe new created tree has elements in inorder traversal: \n");
        morris_traversal_inorder(newhead);
        free(newhead);
}

/*driver function */
int main(){
    int exit1 = 0 ; 
    while(!exit1){
        int choice ; 
        printf("\n1:exit:\n2:check for height : \n3: search element\n4: delete element\n5:iterative inorder traversal ");
        scanf("%d",&choice);
        switch(choice){
            case 2:check_function() ; 
            break ; 
            case 3:search_function(); 
            break ; 
            case 4: del_function(); 
            break ;
            case 5: iterative_inorder(); 
            break ;
            default:
            exit1= 1 ;
        }
	    
        


        
        
        

    }
    printf("\n process finished\n");





	return 0 ;
}
