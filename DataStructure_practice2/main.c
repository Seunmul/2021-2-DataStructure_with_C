#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list_Ex.h"

void linked_list()
{
    NODE* n[5];
    int a[5] = { 1,2,3,4,5 };
    int* ap = a;
    for (int i = 0; i < sizeof(n) / sizeof(NODE*); i++)
    {
        printf("%d\n", a[i]);
    }

    for (int i = 0; i < sizeof(n) / sizeof(NODE*); i++)
    {
        n[i] = createNode(a + i, NULL);
    }
    for (int i = 0; i < sizeof(n) / sizeof(NODE*); i++)
    {
        if (i + 1 >= sizeof(n) / sizeof(NODE*))
            continue;
        else {
            n[i]->link = n[i + 1];
        }
    }
    //배열로 참조하는 경우에는 배열명(a[i]형태)을 주솟값 참조로 사용할 수 없다.
    //이는 포인터 명을 배열명으로 사용하는 사용하는 경우와 같다. 포인터 상수로 처리가 되더라..
    //단 배열명 즉 a[i]에서 a만 사용하면 주소다. 이 때 a를 사용하면 그냥 포인터 주소가 되기 때문에 포인터 연산처럼 사용이 가능하고, 이는 참조가 가능하다

    // 결론: a[i]형태는 포인터 상수 형태이다. 그러니가 그렇게 표현된 포인터의 주솟값에 어떤 접근이나 수정이 불가능하단 뜻이다.
    // 결론2: 포인터 연산으로 주솟값을 더하거나 빼려면 포인터 상수를 사용하지 말자. 포인터 값으로 된 것만 사용하자.

    printf("%d\n", *((int*)(*n[0]).dataPtr));// a[i] 형태 사용시 에러가 난다
    printf("%d\n", *((int*)(n[1]->link->dataPtr)));// a[i]형태로 사용 시 에러가 난다. a[i]를 주솟값 역참조 하기 때문! 이러면 안됨.
    printf("%d\n", (int)(n[2]->link->dataPtr)); // 여기서는 a[i]든 a+i든 에러가 나지 않는다. a[i]에서는 배열명이기 때문에 %d를 사용하면 저장된 수를 
    //%p에서는 주소를 보여준다. 단 a+i에서는 주솟값을 참조하는 것이므로 %d를 사용하면 저장된 정수값이 아닌 주솟값이 출력된다.
    for (int i = 0; i < sizeof(n) / sizeof(NODE*); i++)
    {
        free(n[i]);
    }

}

int factorial(int n) {
    if (n == 0)
    {
        return 1;
    }
    else
        return(n * factorial(n - 1));
}

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n-1) + fib(n - 2);
}

int preToPostFix(char* preFixIn, char* postFix) // return value: length of converted expression
{
    char op[2]; //operator
    int p = 0;

    //base case
    if (strchr("+-*/", preFixIn[0]) == NULL) {
        postFix[0] = preFixIn[0];
        postFix[1] = '\0';
        return strlen(postFix);
    }

    //general case
    op[0] = preFixIn[p++];
    op[1] = '\0';
    p = p + preToPostFix(preFixIn + p, postFix);
    p = p + preToPostFix(preFixIn + p, postFix + strlen(postFix));
    strcat(postFix, op);
    
    //return length of current sub-expression
    return strlen(postFix);
    //preToPostFix
}
int main()
{
    int num = 5;
    int result = 0;
    //linked_list();
    //result =factorial(num);
   // result = fib(2);
    //printf("%d", fib(5));
    char* preFixIn="+-57/107";
    char* postFix = malloc(1000);

    preToPostFix(preFixIn, postFix);
    printf("%s", postFix);

    return 0;
}