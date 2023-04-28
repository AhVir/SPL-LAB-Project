#include<stdio.h>
#include<string.h>

int main(){
    float sum;

    char str[] = "hello";

   r:
    sum = 5 + 4 + 43 + ((strcmp(str, "hello")==0)?58:0);
    printf("Sum-> %f\n", sum);

    goto r;

    return 0;
}