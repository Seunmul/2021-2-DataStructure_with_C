#include <stdio.h>
#define _CRT_NO_WARNINGS

void num_test3()
{

    int num_input;

    int num1, num2, num3, num4, num5;

    printf("5자리 수를 입력하세요 : ");
    scanf("%d", &num_input);

    num1 = (num_input / 10000) % 10;
    num2 = (num_input / 1000) % 10;
    num3 = (num_input / 100) % 10;
    num4 = (num_input / 10) % 10;
    num5 = num_input % 10;

    printf("%d %d %d %d %d", num5, num4, num3, num2, num1);
}