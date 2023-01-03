#include <stdio.h>
#include <stdlib.h>

#define SIZE 31
#define NUMBER 100 

typedef struct nd{
	int data ; 
	struct nd *next ; 
} node ;
typedef struct ht{
	node *nextnode ;  
} hash_table ;
node* newNode(int data ){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data ; 
	newnode->next = NULL ; 
	return newnode ; 
}
void hash_insert(hash_table table[] , int element ){
	int loc = element % SIZE ; 
	node *temp = table[loc].nextnode; 
	if ( temp == NULL ){
		table[loc].nextnode = newNode(element);
		return ;
	}else{
		while( temp->next != NULL ){
			temp = temp->next ; 
		}
		temp->next = newNode(element);
	};
	return ; 
}
void print(hash_table table[] ){
	for( int i = 0 ; i < SIZE ; i++ ){
		printf("%d :" , i);
		node *temp = table[i].nextnode ;
		while( temp != NULL ){
			printf(" %d ->" , temp->data);	
			temp = temp->next ; 
		} 
		printf("\n");
	}
}
void avg_length(hash_table table[] ){
	double sum = 0 ; 
	for ( int i = 0 ; i < SIZE ; i++ ){
		node *temp = table[i].nextnode ; 
		while( temp != NULL ){
			sum++ ; 
			temp = temp->next ; 
		}
	}
	printf("average : %lf,",sum / SIZE );	
}
int main(){
	hash_table table[SIZE];
	for( int i = 0 ; i < SIZE ; i++ ){
		table[i].nextnode = NULL ; 
	}
	printf("hell\n");
	for( int i = 0 ; i < NUMBER ; i++ ){
		int m = rand() % 1000 ; 
		hash_insert(table, m);
	}
	print(table);
	avg_length(table);
	return 0 ; 
}
