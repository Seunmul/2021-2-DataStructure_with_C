#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#define __USE_MINGW_ANSI_STDIO 1//  Dev-C++(MinGW)에서 %hhu를 사용하기 위한 설정
#include <stdio.h>


int main()
{
    //bool_type();
    //bitwise_asign();
    //while_test();

    int input;

    scanf("%d", &input);

 
    while (input > 1200)
    {
        input = input - 1200;
        printf("%d\n", input);
        
    }

    return 0;
} 