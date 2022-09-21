#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지

void num_test2()
{
    printf("실수 입력 : ");
    double num4;
    scanf("%lf", &num4);    // 자료형이 double일 때는 %lf
    getchar();
    printf("%lf\n", num4);
   
    printf("실수 입력 : ");


    long double num5;
    scanf("%Lf", &num5);    // 자료형이 long double일 때는 %Lf
    getchar();
    printf("%Lf", num5);
}