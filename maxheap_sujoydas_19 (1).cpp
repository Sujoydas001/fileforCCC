#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *num1 , int *num2){
	int temp = *num1 ; 
	*num1 = *num2 ; 
	*num2 = temp ; 
}

void heapify( int *arr , int size , int i ){
	int large = i ;
	int left = 2 * i + 1 ;  
	int right = 2 * i + 2 ; 
	if ( left < size && arr[left] > arr[large] ){
		large = left ; 
	};
	if ( right < size && arr[right] > arr[large] ){
		large = right ; 
	};
	if ( large != i ){
		swap(&arr[i] , &arr[large]);
		heapify(arr, size ,large);
	};
	
}

void buildHeap(int *arr , int size){
	int lastintNodeIdx = ( size / 2 ) - 1 ;
//	printf("%d\n", arr[lastintNodeIdx] ); 
	for ( int i = lastintNodeIdx ; i >= 0 ; i-- ){
		 heapify(arr , size , i );
		 
	}
}

void printMaxheap(int *arr  ,int size){
	for ( int i = 0 ; i < size ; i++ ){
		printf("%d , ",arr[i]);
	};
	printf("\n\n");
}

int number ; 
void insert(int *arr){
	int key ; 
	printf("enter key to add: ");
	scanf("%d", &key);
	arr[number++] = key ; 
	int lastNON = number/2 -1 ; 
	heapify(arr , number , lastNON );
}


void printlevelorder(int *arr , int size ){
	int j  = 0 ; 
	int idx = 0 ; 
	printf("level order traversal: \n");
	while(j < size ){
		int c = 0 ; 
		int k = pow(2,j);
		for ( int i = 0 ; i < k ; i++ ){
			printf("%d ", arr[idx++]);
			if ( idx == number ){
				c = 1 ; 
				break ; 
			}
		};
		printf("\n");
		if ( c == 1 ){
			return ; 
		}
		
		j++;
	};
}

int main(){

	printf("hell\nenter no of random numbers  (maximum 1000 elements can be inserted in the empty array) \n");
	
	scanf("%d" , &number );
	int *numarray = (int*)calloc(1000 , sizeof( int ));
	
	for ( int i = 0 ; i < number ; i++ ){
		int a = rand() % 100 ; 
		numarray[i] = a ; 
	};
	
	printf("original array heap:\n");
	printMaxheap(numarray , number );
	buildHeap(numarray , number );
	printf("modified array maxheap:\n ");
	printMaxheap(numarray , number );
	insert(numarray);
	printf("modified array maxheap: after insertion\n");
	printMaxheap(numarray , number );
	int randidx = number  ; 
	printlevelorder(numarray , randidx);
	
	
	
	return 0 ;
}
