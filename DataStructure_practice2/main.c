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
    //�迭�� �����ϴ� ��쿡�� �迭��(a[i]����)�� �ּڰ� ������ ����� �� ����.
    //�̴� ������ ���� �迭������ ����ϴ� ����ϴ� ���� ����. ������ ����� ó���� �Ǵ���..
    //�� �迭�� �� a[i]���� a�� ����ϸ� �ּҴ�. �� �� a�� ����ϸ� �׳� ������ �ּҰ� �Ǳ� ������ ������ ����ó�� ����� �����ϰ�, �̴� ������ �����ϴ�

    // ���: a[i]���´� ������ ��� �����̴�. �׷��ϰ� �׷��� ǥ���� �������� �ּڰ��� � �����̳� ������ �Ұ����ϴ� ���̴�.
    // ���2: ������ �������� �ּڰ��� ���ϰų� ������ ������ ����� ������� ����. ������ ������ �� �͸� �������.

    printf("%d\n", *((int*)(*n[0]).dataPtr));// a[i] ���� ���� ������ ����
    printf("%d\n", *((int*)(n[1]->link->dataPtr)));// a[i]���·� ��� �� ������ ����. a[i]�� �ּڰ� ������ �ϱ� ����! �̷��� �ȵ�.
    printf("%d\n", (int)(n[2]->link->dataPtr)); // ���⼭�� a[i]�� a+i�� ������ ���� �ʴ´�. a[i]������ �迭���̱� ������ %d�� ����ϸ� ����� ���� 
    //%p������ �ּҸ� �����ش�. �� a+i������ �ּڰ��� �����ϴ� ���̹Ƿ� %d�� ����ϸ� ����� �������� �ƴ� �ּڰ��� ��µȴ�.
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