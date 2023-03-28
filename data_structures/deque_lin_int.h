//  Deque using doubly linked list//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node of a doubly linked list
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;

} Node;

typedef struct {
    Node *front; // front refers to the front node of the deque
    Node *rear ;	// rear refers to the rear node of the deque
    int size ;

} deQueue ; 

deQueue* initiate(){
	deQueue *deq = (deQueue*)malloc( sizeof(deQueue));
    deq->size = 0 ; 
    deq->front = NULL ; 
    deq->rear = NULL ; 
    return  deq ; 
}
// Function to check whether deque is empty or not
bool isEmpty(deQueue *deq )
{
	if (deq->front == NULL)
	{
		printf("\ndequeue is empty \n");
		return true;
	}
	else
	{
		return false;
	};
}

// Function to insert an element at the front end
void frontAdd(deQueue *deq , int data )
{
	
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	// If deque is empty
	if (deq->front == NULL)
		deq->rear = deq->front = newnode;

	// Inserts node at the front end
	else
	{
		newnode->next = deq->front;
		deq->front->prev = newnode;
		deq->front = newnode;
	}

	// increase size of deque when new element added
	deq->size++;
}

void utility_frontAdd( deQueue *deq ){
    int data;
	printf("enter data to add : \n ");
	scanf("%d", &data);
    frontAdd(deq , data );
    return ; 
}

// Function to insert an element  at the rear end
void rearAdd(deQueue *deq , int data )
{

	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	// If deque is empty
	if (deq->rear == NULL)
		deq->front = deq->rear = newnode;

	else
	{
		newnode->prev = deq->rear;
		deq->rear->next = newnode;
		deq->rear = newnode;
	}
	// increase size of deque when new element added
	deq->size++;
}

void utility_rearAdd( deQueue *deq  ){
    int data;
	printf("enter data to add : \n ");
	scanf("%d", &data);
    rearAdd(deq , data );
    return ; 
}

// Function to insert an element  at given index
void addAtIdx(deQueue *deq)
{
	int data;
	printf("enter data to add : \n ");
	scanf("%d", &data);
	int idx;
	printf("enter idx : \n ");
	scanf("%d", &idx);
	if (idx == 0)
	{
		frontAdd(deq , data);
		return;
	}
	if (idx == deq->size)
	{
		rearAdd(deq , data);
		return;
	}
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	// printf("font : %d",front->data);
	Node *temp = deq->front;
	int count = 0;
	while (count < idx - 1 && temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	newnode->next = temp->next;
	temp->next->prev = newnode;
	newnode->prev = temp;
	temp->next = newnode;
}

// Function to delete the element  from the front end
void frontDel(deQueue *deq)
{
	if (isEmpty(deq))
	{
		printf("nothing to delete \n");
	}
	else
	{
		Node *temp = deq->front;
		deq->front = deq->front->next;

		// If only one element was present
		if (deq->front == NULL)
		{
			deq->rear = NULL;
		}
		else
		{
			deq->front->prev = NULL;
		}
		free(temp);
		// Decrease size of deque when elemnt deleted 
		deq->size--;
	}
}

// Function to delete the element from the rear end
void rearDel(deQueue *deq)
{
	
	if (isEmpty(deq)){
		printf("noting to delete \n");

	}
	else
	{
		Node *temp = deq->rear;
		deq->rear = deq->rear->prev;

		if (deq->rear == NULL)
		{
			deq->front = NULL;
		}
		else
		{
			deq->rear->next = NULL;
		};
		// Decrease size of deque when elemnt deleted 
		free(temp);
		deq->size--;
	}
}

// Function to delete the element from the given index
void deleteAtidx(deQueue *deq)
{
	int idx;
	printf("enter index : \n ");
	scanf("%d", &idx);
	if (idx == 0)
	{
		frontDel(deq);
		return;
	}
	if (idx == deq->size - 1)
	{
		rearDel(deq);
		return;
	}
	Node *temp = deq->front;
	int count = 0;
	while (count < idx - 1 && temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	Node *toDel = temp->next;
	temp->next = temp->next->next;
	temp->next->prev = temp;
	free(toDel);
}

// Function to check if given data is in the list
bool isContains(deQueue *deq)
{
	int data;
	printf("enter data to search: \n ");
	scanf("%d", &data);
	Node *temp = deq->front;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			printf("data found \n");
			return true;
		};
	};
	printf("data not found \n");
	return false;
}

// print the deque
void printdeque(deQueue *deq)
{
	Node *temp = deq->front;
    if( deq->front == NULL ){
        printf("nothing");
        return ; 
    }
	while (temp != deq->rear->next)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
