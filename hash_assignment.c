
#include <stdio.h>
#include <stdlib.h>

// #define Lfactor 0.25 
int NUMBER = 10;
// double a = (NUMBER / Lfactor) ; 
// int SIZE 


#define init_garbage -1

typedef struct {
	int data ; 
	int empty ; 
} hash_table ; 

typedef struct nd{
    int data ; 
    struct nd *next ; 
}node ; 

typedef struct ht{
    node *nextnode ; 
}hashtable  ;



void lin_hash_insert(hash_table table[] , int element ,int SIZE ){
	int i = 0 ; 
	int loc = (element % SIZE)  ; 
    if(  table[loc].empty == 0 && table[loc].data == element ){
        printf("\nelement repeats ... so no insertion\n");
        return ;
    }
	
	while( table[loc].empty != 1 ){
		i++ ;
		loc = ((element % SIZE) + i) % SIZE   ; 
		if ( i >= SIZE ){
			printf("\nno place to input \n");
			return ; 
		}
	}

	table[loc].data = element  ;
	table[loc].empty = 0  ;
	return ; 
}

void lin_hash_search(hash_table table[] , int element ,int SIZE ){
	int i = 0 ; 
	int loc = (element % SIZE)  ; 
	
	while( table[loc].data != element ){
		
		i++ ;
		loc = ((element % SIZE) + i) % SIZE   ; 
		if ( i >= SIZE ){
			printf("\nnot found \n");
			return ; 
		}
	}
	printf("\n found %d %d\n", table[loc].data );

	return ; 
}


int hashprobe(int elem,int SIZE ){
	return  elem % SIZE ; 
}

int hashoffset(int elem,int SIZE ){
	return SIZE - 1 - ( elem % (SIZE - 1))  ; 
}

void double_hash_insert(hash_table table[] , int element,int SIZE ){
    int i = 0 ; 
    static int j = 0 ; 
	int loc = hashprobe(element , SIZE );
	int offset = hashoffset(element , SIZE);
    if( table[loc].data == element && table[loc].empty == 0  ){
        // printf("\nrepeatation so terminating....\n");
        return ; 
    }
	while( table[loc].empty != 1 ){
		
		i++ ; 
		loc = ((loc) + i * offset) % SIZE   ; 
        
		if ( j >= SIZE ){
			printf("\nno place to input \n");
			return ; 
		}

	}
	
  
	table[loc].data = element  ;
	table[loc].empty = 0  ;
	j++ ; 
	return ; 
}

void double_hash_search(hash_table table[] , int element,int SIZE ){
    int i = 0 ; 
    static int j = 0 ; 
	int loc = hashprobe(element , SIZE );
    int firstpos = loc ; 
	int offset = hashoffset(element , SIZE );

	while( table[loc].data !=  element){
		
		i++ ; 
		loc = ((loc) + i * offset) % SIZE   ; 
        if ( loc == firstpos ){
			printf("\nnot found \n");
			return ; 
		}

	}
	
  
	printf("\n found %d\n", table[loc].data );
    
	j++ ; 
	return ; 
}


node *newnode(int k ){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k ; 
    newnode->next = NULL ; 
    return newnode ; 
}

void insert( hashtable h[] , int k,int SIZE ){
    int pos = k % SIZE ; 
    node *temp = h[pos].nextnode ; 
    if(temp == NULL ){
        h[pos].nextnode = newnode(k); 
    }else{
        while(temp->next != NULL  ){
            temp = temp->next ; 
        }
        temp->next = newnode(k);
    }

}

void print_chain(hashtable h[],int SIZE  ){
    printf("\nhashtable\n");
    for( int i = 0 ; i < SIZE ; i++ ){
        printf("%d : " , i );
        node *tmep = h[i].nextnode ; 
        while( tmep != NULL ){
            printf("%d -> " , tmep->data );
            tmep = tmep->next ; 
        }
        printf("\n");
    }
    printf("\n\n");
}

void print(hash_table table[],int SIZE  ){
	for( int i = 0 ; i < SIZE ; i++ ){
		if ( table[i].empty == 1 ){
			printf(" E ,"  );
		}else {
			printf(" %d, " , table[i].data );
		}
				
	} 
	printf("\n\n\n");
	
}



int main(){
    
    double lfactor = 0.25 ; 
    
    int SIZE = (int)(NUMBER/lfactor);
    printf("hell\n"); 
    hash_table table1[SIZE] ; 
    for( int i = 0 ; i < SIZE ; i++ ){
		table1[i].empty = 1 ; 
    }
    hash_table table2[SIZE] ; 
    for( int i = 0 ; i < SIZE ; i++ ){
		table2[i].empty = 1 ; 
    }
    hashtable h_table[SIZE];
    for ( int i = 0 ; i < SIZE ; i++ ){
        h_table[i].nextnode = NULL ; 
    }
    print(table1, SIZE);
    print(table2 , SIZE);
    print_chain(h_table , SIZE );

    for( int i = 0 ; i < NUMBER ; i++ ){
		int m1 = rand() % 100000 ; 
		lin_hash_insert(table1, m1 , SIZE );
        double_hash_insert(table2, m1 , SIZE );
        insert(h_table, m1 , SIZE );
	}
    print(table1, SIZE);
    print(table2, SIZE);
    print_chain(h_table,SIZE);





    return 0 ; 



}
//     printf("%d\n",(int)a);
// 	hash_table table[SIZE];
// 	for( int i = 0 ; i < SIZE ; i++ ){
// 		table[i].empty = 1 ; 
//     }
// 	printf("hell\n");
// 	// print(table);
// 	// for( int i = 0 ; i < NUMBER ; i++ ){
// 	// 	int m = rand() % 100000 ; 
// 	// 	double_hash_insert(table, m);
// 	// }
// 	// lin_hash_insert(table,25);
// 	// print(table);
// 	// // lin_hash_insert(table,25);
// 	// // print(table);
// 	// lin_hash_insert(table,190);
// 	// print(table);
// 	// lin_hash_insert(table,1490);
// 	// print(table);
// 	// lin_hash_insert(table,290);
// 	// print(table);
// 	// lin_hash_insert(table,390);
// 	// print(table);
// 	// lin_hash_insert(table,490);
// 	// print(table);
// 	// lin_hash_insert(table,90);
// 	// print(table);
// 	// lin_hash_insert(table,190);
// 	// print(table);
// 	// lin_hash_insert(table,1490);
// 	// print(table);
// 	// // lin_hash_insert(table,90);
// 	// // print(table);
// 	// lin_hash_insert(table,590);
// 	// print(table);
//     // lin_hash_insert(table,590);
// 	// print(table);	
// 	// lin_hash_search(table , 490);

//     //////////////////////////////

// 	// print(table);
// 	// double_hash_insert(table,90);
// 	// print(table);
// 	// double_hash_insert(table,190);
// 	// print(table);
// 	// // print(table);
// 	// double_hash_insert(table,290);
// 	// print(table);
// 	// double_hash_insert(table,1190);
// 	// print(table);
// 	// double_hash_insert(table,390);
// 	// print(table);
// 	// double_hash_insert(table,490);
// 	// print(table);
// 	// print(table);
// 	// double_hash_insert(table,590);
// 	// print(table);
// 	// double_hash_insert(table,690);
// 	// print(table);
// 	// double_hash_insert(table,1490);
// 	// print(table);
// 	// print(table);
// 	// double_hash_insert(table,5190);
// 	// print(table);
// 	// double_hash_insert(table,0);
// 	// print(table);
// 	// search(table,5190);
//     // double_hash_search(table , 15727);

//     hashtable h_table[SIZE];
//     for ( int i = 0 ; i < SIZE ; i++ ){
//         h_table[i].nextnode = NULL ; 
//     }
//     for ( int i = 0 ; i < NUMBER ; i++ ){
//         int m = rand() % 100000 ; 
// 		insert(h_table, m);
//     }
//     print_chain(h_table); 
// 	return 0 ; 
// }
	
