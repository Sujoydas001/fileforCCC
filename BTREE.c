#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



#define WAY 5
int max_present = WAY - 1 ; 

typedef struct {
    int val ; 
    bool empty ; 
} array ; 


typedef struct nd{
    array num_arr[WAY - 1]; 
    bool is_leaf ; 
    int num_present ; 
    struct nd *nextnodes[WAY] ; 

} node ; 

node *newnode(){
    node *newnode = (node*)malloc(sizeof(node));
    for( int i = 0 ; i < max_present  ; i++ ){
        newnode->num_arr[i].empty  = true  ; 
        newnode->is_leaf = true ; 
        for( int j= 0 ; j < WAY ; j++ ){
            newnode->nextnodes[j] = NULL ; 
        }
        
        newnode->num_present = 0 ; 
    };
    return newnode ; 
}

node* insert_node(node *head , int element ){
    static int idx  = 0 ; 
    node* temp_head = head ; 
    if ( temp_head == NULL ){
        node *newNode = newnode();
        newNode->num_arr[idx].empty  = false ; 
        newNode->num_arr[idx++].val = element ; 
        newNode->num_present += 1 ; 
        return newNode ; 
    } ; 

    if( temp_head->num_present < max_present ){
        for( int j = 0 ; j < temp_head->num_present ; j++ ){
            if ( element < temp_head->num_arr[j].val ){
                int k = temp_head->num_present; 
                for ( int l = k ; l > j ; l-- ){
                    temp_head->num_arr[l].val = temp_head->num_arr[l-1].val ; 
                     temp_head->num_arr[l].empty = temp_head->num_arr[l-1].empty ; 
                }
                temp_head->num_arr[j].val = element ; 
                temp_head->num_arr[j].empty  = false ; 
                idx++ ; 
                break ; 
            }else{
                temp_head->num_arr[idx].val = element ; 
                temp_head->num_arr[idx++].empty  = false ; 
            }
        }
        temp_head->num_present += 1 ; 
        return head ; 
    };
    
    // idx = 0 ; 
    // int meadian = (int)(max_present + 1 ) /  2 ; 
    // node *temp_new = newnode() ;
    // temp_new->num_arr[idx] = temp_head->num_arr[meadian];
    node *newhead = NULL ; 
    head = insert_node( head , element );



    


    return head ; 







}



int main(){
    printf("\nhell\n");
    node *head = NULL ; 
    head = insert_node(head, 300 ) ; 
    head = insert_node(head, 205 ) ;
    head = insert_node(head, 2 ) ;
    head = insert_node(head, 200 ) ; 
    for( int i = 0 ; i < max_present ; i++ ){
        if( head->num_arr[i].empty == true ){
                printf(" E," );
        }else{
                printf("%d, " , head->num_arr[i].val);
        }
        
    }

    return 0 ; 
}