#include <stdio.h>
#include <stdlib.h>
float average(int n1, int n2, int n3, int n4, int n5, int n6, int n7){
    float result =( n1+n2+n3+n4+n5+n6+n7)/7;
    return result;

}

int main(){

    int a=11, b=22, c=33, d=44, e=55, f=66, g=77;
    printf("a의 주소 : %p\n",&a);
    printf("평균 : %f\n",average(a,b,c,d,e,f,g));

    int *array = malloc(sizeof(int)*7);
    for(int i=0;i<7;i++){
        array[i]=(i+1)*10+i+1;
    }
    printf("array[0]의 주소 : %p\n",&array[0]);
    printf("평균 : %f\n", average(array[0],array[1],array[2],array[3],array[4],array[5],array[6]));
    free(array);
    return 0;
}
