#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#define __USE_MINGW_ANSI_STDIO 1//  Dev-C++(MinGW)���� %hhu�� ����ϱ� ���� ����
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