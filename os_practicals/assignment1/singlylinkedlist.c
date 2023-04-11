#include <stdio.h>
#include <stdlib.h>



typedef struct nd{
    int data;
    struct nd *next;
} Node;

// create first node of the linked list
Node *getNewNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// returns the size of the sll
int size(Node *head)
{
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

// set new node at the given index

Node *setElement(Node *head , int data, int idx ){
    if (idx >= 0 && idx <= size(head))
    {
        Node *newnode = getNewNode(data) ; 
        if (head == NULL)
        {
            head = newnode ; 
        }
        else if (idx == 0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *temp = head;
            Node *prev = head;
            int i = 0;
            while (i < idx - 1 && temp->next != NULL) // iterate until the node after which new node is to be inserted
            {
                temp = temp->next;
                prev = prev->next;
                i++;
            };
            temp = temp->next;
            newnode->data = data;
            newnode->next = temp;
            prev->next = newnode;
        }
    }
    else
    {
        printf("out of index\n");
    };
    return head;
}
Node *setElementUtil(Node *head)
{
    int data;
    printf("enter to add: ");
    scanf("%d", &data);
    int idx;
    printf("enter index : ");
    scanf("%d", &idx);
    return setElement(head,data, idx );

}

// insert new node at the end
Node *insertLast(Node *head)
{
    int data;
    printf("enter to add: ");
    scanf("%d", &data);
    Node *newnode = getNewNode(data);
    if (head == NULL)
    {
        return newnode ; 
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        };
        temp->next = newnode;
    }
    return head;
}

// insert new node at the beginning
Node *insertFirst(Node *head)
{
    int data;
    printf("enter to add: ");
    scanf("%d", &data);
    Node *newnode = getNewNode(data);
    if (head == NULL)
    {
        return newnode ;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    return head;
};

// print the linked list data
void printList(Node *head)
{
    Node *temp = head;
    if( temp == NULL ){
        printf("\nlist empty\n");
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return ; 
}

// delete the beginning node
Node *deleteFirstNode(Node *head)
{

    Node *temp = head;
    if (temp == NULL)
    {
        printf("nothing\n");
        return NULL ;
    }

    Node *todel = temp;
    head = temp->next;
    printf("\n%d deleted\n", todel->data);
    free(temp);
    return head;
}

// delete the end node
Node *deleteLastNode(Node *head)
{
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *todel = temp->next;
    temp->next = temp->next->next;
    printf("\n%d deleted\n", todel->data);
    free(todel);

    return head;
}

// delete node at a given index
Node *deleteAtPos(Node *head)
{
    int idx;
    printf("enter index : ");
    scanf("%d", &idx);
    if (idx >= 0 && idx < size(head))
    {
        Node *temp = head;
        if (idx == 0)
        {
            return deleteFirstNode( head );
        }
        else
        {
            int i = 0;

            while ( i < idx - 1 && temp->next != NULL )
            {
                temp = temp->next;
                i++;
            };
            Node *todel = temp->next;
            temp->next = temp->next->next;
            free(todel);
        };
    }
    else
    {
        printf("out of index\n");
    };
    return head;
}

// checks if the element is in the linked list or not
// void contains(Node *head)
// {
//     int data;
//     int idx = 0;
//     printf("enter no: ");
//     scanf("%d", &data);
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == data)
//         {
//             printf("data found at index : %d \n", idx);
//             return;
//         }
//         temp = temp->next;
//     };
//     printf("data not found\n");
//     return;
// }

int main()
{
    Node *head = NULL;

    int exit = 0;
    while (!exit)
    {
        printf("0:Exit\n1: Insert at  begining \n2. Insert at the end\n3. Insert at position \n4.delete at beginning\n5. delete at end\n6. Delete at position\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit  = 1 ;
            break;
        case 1:
            head = insertFirst(head);
            printList(head);
            break;
        case 2:
            head = insertLast(head);
            printList(head);
            break;
        case 3:
            head = setElementUtil(head);
            printList(head);
            break;
        case 4:
            head = deleteFirstNode(head);
            printList(head);
            break;
        case 5:
            head = deleteLastNode(head);
            printList(head);
            break;
        case 6:
            head = deleteAtPos(head);
            printList(head);
            break;
       
        };
    };

    return 0;
}