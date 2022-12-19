// Online C compiler to run C program online
#include <stdio.h>
#include <time.h>

int main() {
    // Write C code here

    //  clock_t start, end;
    //  double cpu_time_used;

    //  start = clock();
    //  printf("Hello world");
    //  end = clock();
    //  cpu_time_used = ((double) (end - start)) ;
    // printf("Hello world%lf\n" , (time_t)cpu_time_used);
    for ( int i = 0 ; i < 6; i++ ){
        for ( int j = 0 ; j < 5 ; j++ ){
            int m = rand()%50 ;
            printf("%d," , m);
        }
        printf("\n");
    }

    return 0;
}
