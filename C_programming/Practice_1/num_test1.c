#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS   // scanf ���� ���� ���� ������ ���� ����

void num_test1()
{
    int num1;
    int num2;
   

    printf("������ �Է��ϼ���: ");
    scanf("%d %d", &num1, &num2);    // ǥ�� �Է��� �޾Ƽ� ������ ����, &���� = > �ּ� �ǹ�.
    getchar();
    printf("%d %d \n", num1, num2);    // ������ ������ ���


  
}