#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void get_in(int**a, int**b, int count)
{
    *a = (int*)malloc(sizeof(int)*count);
    *b = (int*)malloc(sizeof(int)*count);
    for (int i = 0; i < count; i++)
    {
        printf("in1 in2 : ");
        scanf("%d %d", *a+i, *b+i);
    }
}

int* add(int* in1, int* in2, int count) {

    int* result= (int*)malloc(sizeof(int)*count);

    for (int i = 0; i < count; i++)
    {
       result[i] = in1[i] + in2[i];
    }

    return result;
}

int main(void)
{
    int count, i;
    int* in1 = NULL, * in2 = NULL, * result = NULL;

    printf("# of input pairs: ");
    scanf("%d", &count);

    get_in(&in1, &in2, count);

    result = add(in1, in2, count);

   for (i = 0; i < count; i++)        
       printf("%d + %d = %d\n", in1[i], in2[i], result[i]);

    free(in1);
    free(in2);

    return 0;
}