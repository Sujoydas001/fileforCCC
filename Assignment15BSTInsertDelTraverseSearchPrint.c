#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nd {
	int data ;
	struct nd *left  ;
	struct nd *right ;

} Node ;

Node *insertBST(Node *root ,  int key ){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = key ;
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

int max(int a , int b ){
    return a>=b ? a : b ;
}
int height( Node *root ){
    if ( root == NULL ){
            return 0 ;
    }
    return max(height(root->left) , height(root->right) ) + 1;
}


void inorder(Node *root ){
	if ( root == NULL ){
		return  ;
	}
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);

}

void check_height_function(){
    int n  ;
    printf("\neter no of random numbers to be generated: \n");
    scanf("%d",&n);
	int m ;
	time_t t ;
    srand(time(&t));
    double sum = 0 ;
    int length = 0 ;
	for ( int j = 0 ; j < 50 ; j++ ){
	    printf("\n\n");
        Node *root = NULL ;
        /*printf("generated random numbers: \t");*/
        for ( int i = 0 ; i < n ; i++ ){
            m = rand() % 99999 ;
            root = insertBST(root , m );
            /*printf("%d,", m );*/
        };
        length = height(root);
        printf("\nheight : %d\n",length);
        sum += length ;
        printf("\tinorder :\t");
        inorder(root);

        free(root);
	};
    double avg = sum / ( 50 );

    printf("\ntotal sum of height : %lf\n" , sum);
    printf("\navarage: %lf\n" , avg);
}
int main(){
    int exit = 0 ;
    while(!exit){
	    check_height_function() ;
        printf("\n1: exit \n 0: do further\n");
        scanf("%d",&exit);

    }




	return 0 ;
}
