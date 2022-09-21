#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS   // scanf 보안 경고로 인한 컴파일 에러 방지

void num_test1()
{
    int num1;
    int num2;
   

    printf("정수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);    // 표준 입력을 받아서 변수에 저장, &변수 = > 주소 의미.
    getchar();
    printf("%d %d \n", num1, num2);    // 변수의 내용을 출력


  
}