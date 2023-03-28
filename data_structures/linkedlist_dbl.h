#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    int data;
    struct nd *nextnode ;
    struct nd *prevnode ; 
}Node ;

typedef struct dll{
    int size ; 
    Node *head ; 
    Node *tail ; 

}doubly_linked_list ; 

doubly_linked_list* initiate(){
    doubly_linked_list *list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    list->head = NULL ; 
    list->tail = NULL ; 
    list->size = 0 ; 
    return list ;
}

Node* newnode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->nextnode = NULL;
    newnode->prevnode = NULL;
    return newnode;
}

// insert new node at the end
void iLast(doubly_linked_list *list , int data )
{
    
    if (list->head == NULL)
    {
        list->head = newnode(data);
        list->tail = list->head ; 
    }
    else
    {
        list->tail->nextnode = newnode(data);
        list->tail->nextnode->prevnode = list->tail ; 
        list->tail = list->tail->nextnode ; 
    }
    list->size ++ ; 
    return ; 
}

void insertLast(doubly_linked_list *list ){
    int data;
    printf("enter to add: ");
    scanf("%d", &data);
    iLast(list,data);
    return ; 
}
// insert new node at the beginning
void iFirst(doubly_linked_list *list , int data )
{
    if (list->head == NULL)
    {
        list->head = newnode(data);
        list->tail = list->head ; 
        
    }
    else
    {   list->head->prevnode = newnode(data);
        list->head->prevnode->nextnode = list->head ; 
        list->head = list->head->prevnode ; 
    }
    list->size++ ; 
    return ; 
    
    
};

void insertFirst(doubly_linked_list *list ){
    int data;
    printf("enter to add: ");
    scanf("%d", &data);
    iFirst(list,data);
    return ; 
}

// set new node at the given index
void setElement(doubly_linked_list *list)
{
    int data;
    printf("enter to add: ");
    scanf("%d", &data);
    int idx;
    printf("enter index : ");
    scanf("%d", &idx);
    if( idx < 0  || idx >= list->size ){
        return ; 
    }
    if( idx == 0 ){
        iFirst(list, data);
        return ; 
    }
    if( idx == list->size - 1 ){
        iLast(list, data);
        return ; 
    }
    int i = 0 ; 
    Node *temp = list->head ;  
    while( i < idx - 1 ){
        temp = temp->nextnode ; 
        i++ ; 
    };
    Node *newNode = newnode(data);
    newNode->nextnode = temp->nextnode ; 
    newNode->nextnode->prevnode = newNode ; 
    temp->nextnode = newNode ; 
    newNode->prevnode = temp ; 
    return ; 
}


// print the linked list data
void print_dll(doubly_linked_list *list )
{

    Node *temp = list->head;
    printf("\nfrom biginning\n") ; 
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->nextnode ;
    }
    printf("\n");
    Node *nexttemp = list->tail;
    printf("\nfrom ending\n") ; 
    while (nexttemp != NULL)
    {
        printf("%d -> ", nexttemp->data);
        nexttemp = nexttemp->prevnode ;
    }
    printf("\n");
    return ; 
}

// delete the beginning node
void del_first_node(doubly_linked_list *list )
{

    Node *temp = list->head ;
    if (temp == NULL)
    {
        printf("\n nothing to delete \n");
        return ; 
        
    }
    if( list->head == list->tail ){
        list->head = NULL ; 
        list->tail = NULL ; 
        list->size = 0 ; 
        return ; 
    }

    list->head = temp->nextnode  ;
    list->head->prevnode = NULL ; 
    free(temp);
    list->size -- ; 
    return ; 
}

// delete the end node
void del_last_node(doubly_linked_list *list )
{
    Node *temp = list->tail ;
    if( temp == NULL ){
        printf("\n nothing to delete \n");
        return ; 
    }
    if( list->head == list->tail ){
        list->head = NULL ; 
        list->tail = NULL ; 
        list->size = 0 ; 
        return ; 
    }
    list->tail = list->tail->prevnode ; 
    list->tail->nextnode = NULL ; 
    free(temp);
    list->size --  ;
    return ;
}

// delete node at a given index
void del_at_index(doubly_linked_list *list )
{
    int idx;
    printf("\nenter index to delete\n: ");
    scanf("%d", &idx);

    if( idx < 0  || idx >= list->size ){
        return ; 
    }
    if( idx == 0 ){
        del_first_node(list);
        return ; 
    }
    if( idx == list->size - 1 ){
        del_last_node(list);
        return ; 
    }
    int i = 0 ; 
    Node *temp = list->head ; 
    while( i < idx ){
        temp = temp->nextnode ; 
        i++ ; 
    }

    temp->prevnode->nextnode = temp->nextnode ; 
    temp->nextnode->prevnode = temp->prevnode ; 
    free(temp);
    list->size -- ; 

    return ; 
}

// // checks if the element is in the linked list or not
// void contains(doubly_linked_list *list ){   
//     int data;
//     printf("enter data to find : ");
//     scanf("%d", &data);
//     Node *head_ref = list->head ; 
//     Node *tail_ref = list->tail ; 
//     if( head_ref == NULL ){
//         printf("\nnot found \n");
//         return  ; 
//     }
//     if( head_ref == tail_ref ){
//         if( head_ref->data == data ){
//             printf("\nfound\n");
//             return  ; 
//         };
//     };
//     do{
//         if( head_ref->data == data ){
//             printf("\nfound\n");
//             return  ; 
//         }else if(tail_ref->data == data ){
//             printf("\nfound\n");
//             return  ; 
//         }else{
//             head_ref = head_ref->nextnode ; 
//             tail_ref = tail_ref->prevnode ; 
//         };
//     }while( head_ref->prevnode == tail_ref || head_ref->prevnode->prevnode == tail_ref );
//     printf("\nnot found \n");
//     return  ;
// }

// int main(){
//     doubly_linked_list *dll  = initiate() ;
//     int i = 1;
//     while (i)
//     {
//         printf("0:Exit\n");
//         printf("1: Insert a node  in the begining of the linked list\n");
//         printf("2. Insert a node  at the end of the linked list\n");
//         printf("3. Insert a node  at the kth position of the linked list\n");
//         printf("4. Search a node containing a given value\n");
//         printf("5. Print the entire linked list\n");
//         printf("6. Delete a node from the begining of the linked list\n");
//         printf("7. Dele a node  at the end of the linked list\n");
//         printf("8.Delete  a node  at the kth position of the linked list\n");
//         printf("9. Continue\n");
//         int choice;
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 0:
//             i = 0;
//             break;
//         case 1:
//            insertFirst(dll);
//            print_dll(dll);
//             break;
//         case 2:
//             insertLast(dll);
//             print_dll(dll);
//             break;
//         case 3:
//             setElement(dll);
//             print_dll(dll);
//             break;
//         case 4:
//             // contains(dll);
//             print_dll(dll);
//             break;
//         case 5:
//             print_dll(dll);
//             break;
//         case 6:
//             del_first_node(dll);
//             print_dll(dll);
//             break;
//         case 7:
//             del_last_node(dll);
//             print_dll(dll);
//             break;
//         case 8:
//             del_at_index(dll);
//             print_dll(dll);
//             break;
//         case 9:
//             printf("ok continue\n");
//             break;
//         };
//     };
//     return 0;
// }


