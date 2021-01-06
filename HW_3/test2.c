#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1000000

double StackSpeed(){
    clock_t start,end;
    start = clock();
    int a[COUNT];
    for(int i=0;i<COUNT;i++){
        a[i]=i;
    }
    end = clock();
    return (double)(end-start);
}

double HeapSpeed(){
     clock_t start,end;
     start = clock();
     int *b= malloc(sizeof(int)*COUNT);
     for(int i=0;i<COUNT;i++){
         b[i]=i;
     }
     end = clock();
     return (double)(end-start);
 }

int main(){
    
    printf("Heap : %f\n",HeapSpeed());
    printf("Stack: %f\n",StackSpeed()); 

    return 0;
}
