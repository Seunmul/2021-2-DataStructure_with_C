#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����

void num_test2()
{
    printf("�Ǽ� �Է� : ");
    double num4;
    scanf("%lf", &num4);    // �ڷ����� double�� ���� %lf
    getchar();
    printf("%lf\n", num4);
   
    printf("�Ǽ� �Է� : ");


    long double num5;
    scanf("%Lf", &num5);    // �ڷ����� long double�� ���� %Lf
    getchar();
    printf("%Lf", num5);
}