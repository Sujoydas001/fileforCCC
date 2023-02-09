
#include <stdio.h>
#include <stdlib.h>



int NUMBER = 10000;
int suc_prob_count = 0 ; 
int unsuc_prob_count = 0 ; 
double avg_lin_probe = 0 ; 
double avg_double_probe = 0 ; 
double avg_chain_probe = 0 ; 
int SIZE ;



typedef struct {
	int data ; 
	int empty ; 
} hash_table ;         /*for linear and double hashing */

typedef struct nd{
    int data ; 
    struct nd *next ; 
}node ; 

typedef struct ht{
    node *nextnode ; 
}hashtable  ;              /*for chaining */



void lin_hash_insert(hash_table table[] , int element ,int SIZE ){
	int i = 0 ; 
	int loc = (element % SIZE)  ; 
    if(  table[loc].empty == 0 && table[loc].data == element ){
        // printf("\nelement repeats ... so no insertion\n");
        return ;
    }
	
	while( table[loc].empty != 1 ){
        if(  table[loc].data == element ){
        // printf("\nelement repeats ... so no insertion\n");
        return ;
    }
		i++ ;
		loc = ((element % SIZE) + i) % SIZE   ; 
		if ( i >= SIZE ){
			// printf("\nno place to input \n");
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
	int probecount = 1 ; 
    // suc_prob_count = 0 ; 
    // unsuc_prob_count = 0 ; 
	while( table[loc].data != element ){
		
		i++ ;
        probecount++ ; 
		loc = ((element % SIZE) + i) % SIZE   ; 
		if ( i >= SIZE ){
			// printf("\nnot found \n");
            unsuc_prob_count += probecount ; 
			return ; 
		}
	}
    suc_prob_count += probecount ; 
	// printf("\n found %d %d\n", table[loc].data );

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
			// printf("\nno place to input \n");
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
    int probecount = 1  ; 

	int loc = hashprobe(element , SIZE );
    int firstpos = loc ; 
	int offset = hashoffset(element , SIZE );

	while( table[loc].data !=  element){
		
		i++ ; 
        probecount++ ; 
		loc = ((loc) + i * offset) % SIZE   ; 
        if ( loc == firstpos ){
            unsuc_prob_count += probecount ; 
			// printf("\nnot found \n");
			return ; 
		}

	}
	
    suc_prob_count += probecount ; 
	// printf("\n found %d\n", table[loc].data );
    
	j++ ; 
	return ; 
}


node *newnode(int k ){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k ; 
    newnode->next = NULL ; 
    return newnode ; 
}

void insert_chain( hashtable h[] , int k,int SIZE ){
    int pos = k % SIZE ; 
    node *temp = h[pos].nextnode ; 
    if( temp == NULL ){
        h[pos].nextnode = newnode(k); 
        
    }else{
        while( temp -> next != NULL ){
            if( temp -> data == k ){
                // printf("\nrepetation not needed\n");
                return ; 
            }
            temp = temp -> next ; 
        }
        temp->next = newnode(k);
    }

}

void search_chain( hashtable h[] , int k, int SIZE ){
    int pos = k % SIZE ; 
    int probecount = 1 ; 
    node *temp = h[pos].nextnode ; 
    
    while( 1 ){
        if(temp == NULL ){
            unsuc_prob_count+= probecount ; 
            // printf("\nnot found\n");
            return ; 
        };
        if( temp->data == k ) {
            suc_prob_count += probecount ; 
            // printf("\n data found \n");
            return ; 
        }else{
            temp = temp -> next ; 
        }

        probecount++ ; 

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
    printf("hell\n");
    FILE *fptr = fopen("hashing_stats.csv" , "a");
    fprintf(fptr , "\nexperiment done with %d numbers \n\n", NUMBER );
    double lfactor[] = {0.25, 0.50, 0.75 , 1.0}  ; 
   
    fprintf(fptr , "\n") ;
    /************************************************************/
    double result_avgprobe_lin[4];  
    for ( int j = 0 ; j < 4 ; j++ ){
        SIZE = NUMBER / lfactor[j] ;
        suc_prob_count = 0 ; 
        unsuc_prob_count = 0 ; 
        // printf("array size ; %d" , SIZE );
        hash_table table[SIZE] ;
        int search_array[NUMBER];
        srand(1);
        for( int i = 0 ; i < SIZE  ;i++ ){
            table[i].empty = 1 ; 
        } 
        // print(table,SIZE);
        for ( int i = 0 ; i < NUMBER ; i++ ){
            int m = rand()% 10000000 ; 
            lin_hash_insert(table, m , SIZE);
        }
        // print(table , SIZE);
        srand(1);
        for ( int i = 0 ; i < NUMBER ; i++ ){
            int m = rand()% 10000000 ; 
            // printf("%d,", m);
            search_array[i] = m ; 
        }
        printf("\n");
        for ( int i = 0 ; i < NUMBER ; i++ ){
            lin_hash_search(table, search_array[i] , SIZE);
            // printf("\n%d . %d . %d\n" ,  search_array[i] , suc_prob_count , unsuc_prob_count ); 
        }
        avg_lin_probe = (double)suc_prob_count / NUMBER ; 
        // printf("\n%lf = avg\n" , avg_lin_probe) ; 
        printf("\n------------------------------------------------------\n");
        result_avgprobe_lin[j] =  avg_lin_probe ; 
    }  ;
    fprintf(fptr , "linear_probe_conut\nl_factor,avg_probecount\n");
    for ( int i = 0 ; i < 4 ; i++ ){
        // printf("%lf, " , result_avgprobe_lin[i]);
        fprintf(fptr , "%lf,%lf\n", lfactor[i] , result_avgprobe_lin[i]);
    }
    fprintf(fptr , "\n") ;
/***********************************************************************/
    double result_avgprobe_double[4];  
    for ( int j = 0 ; j < 4 ; j++ ){
        SIZE = NUMBER / lfactor[j] ;
        suc_prob_count = 0 ; 
        unsuc_prob_count = 0 ; 
        // printf("array size ; %d" , SIZE );
        hash_table table_double[SIZE] ;
        int search_array2[NUMBER];
        srand(1);
        for( int i = 0 ; i < SIZE  ;i++ ){
            table_double[i].empty = 1 ; 
        } 
        // print(table_double,SIZE);
        for ( int i = 0 ; i < NUMBER ; i++ ){
            int m = rand()% 10000000 ; 
            double_hash_insert(table_double, m , SIZE);
        }
        // print(table_double , SIZE);
        srand(1);
        for ( int i = 0 ; i < NUMBER ; i++ ){
            int m = rand()% 10000000 ; 
            // printf("%d,", m);
            search_array2[i] = m ; 
        }
        printf("\n");
        for ( int i = 0 ; i < NUMBER ; i++ ){
            double_hash_search(table_double, search_array2[i] , SIZE);
            // printf("\n%d . %d . %d\n" ,  search_array2[i] , suc_prob_count , unsuc_prob_count ); 
        }
        avg_double_probe = (double)suc_prob_count / NUMBER ; 
        // printf("\n%lf = avg\n" , avg_double_probe) ; 
        printf("\n------------------------------------------------------\n");
        result_avgprobe_double[j] =  avg_double_probe ; 
    }  ;
    fprintf(fptr , "doublehashing_probe_conut\nl_factor,avg_probecount\n");
    for ( int i = 0 ; i < 4 ; i++ ){
        // printf("%lf, " , result_avgprobe_double[i]);
        fprintf(fptr , "%lf,%lf\n",lfactor[i] ,  result_avgprobe_double[i]);
    }
    fprintf(fptr , "\n") ;
/*************************************************************************/
    double result_avgprobe_chain[4];  
    for ( int j = 0 ; j < 4 ; j++ ){
        SIZE = NUMBER / lfactor[j] ;
        suc_prob_count = 0 ; 
        unsuc_prob_count = 0 ; 
        // printf("array size ; %d" , SIZE );
        hashtable table_chain[SIZE] ;
        int search_array3[NUMBER];
        srand(1);
        for( int i = 0 ; i < SIZE  ;i++ ){
            table_chain[i].nextnode  = NULL  ; 
        } 
        // print_chain(table_chain,SIZE);                /*blank chain*/
        for ( int i = 0 ; i < NUMBER ; i++ ){
            int m = rand()% 10000000 ; 
            insert_chain(table_chain, m , SIZE);
        }
        // print_chain(table_chain , SIZE);             /*hashed chain*/
        srand(1);
        for ( int i = 0 ; i < NUMBER ; i++ ){
            int m = rand()% 10000000 ; 
            // printf("%d,", m);
            search_array3[i] = m ; 
        }
        printf("\n");
        for ( int i = 0 ; i < NUMBER ; i++ ){
            search_chain(table_chain, search_array3[i] , SIZE);
            // printf("\n%d . %d . %d\n" ,  search_array3[i] , suc_prob_count , unsuc_prob_count ); 
        }
        avg_chain_probe = (double)suc_prob_count / NUMBER ; 
        // printf("\n%lf = avg\n" , avg_chain_probe) ; 
        printf("\n------------------------------------------------------\n");
        result_avgprobe_chain[j] =  avg_chain_probe ; 
    }  ;
    fprintf(fptr , "chaining_probe_conut\nl_factor,avg_probecount\n");
    for ( int i = 0 ; i < 4 ; i++ ){
        // printf("%lf, " , result_avgprobe_chain[i]);
        fprintf(fptr , "%lf,%lf\n", lfactor[i] , result_avgprobe_chain[i]);
    };
    fprintf(fptr , "\n") ;
    fclose(fptr) ; 






    return  0; 
}