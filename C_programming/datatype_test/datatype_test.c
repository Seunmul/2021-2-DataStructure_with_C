#include <stdio.h>

int datatype_test()
{
    char num1 = 200;
    short num2 = 30000;
    int num3 = -1234567890;
    long num4 = -1234567890;
    long long num5 = -1234567890123456789;

    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);

    unsigned char num6 = 200;                          // 1바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned short num7 = 60000;                       // 2바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned int num8 = 4123456789;                    // 4바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned long num9 = 4123456789;                   // 4바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned long long num10 = 12345678901234567890;    // 8바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    // unsigned char, unsigned short, unsigned int는 %u로 출력하고 
    // unsigned long은 %lu, unsigned long long은 %llu로 출력
    printf("%u %u %u %lu %llu\n", num6, num7, num8, num9, num10);
    // 200 60000 4123456789 4123456789 12345678901234567890
    return 0;
}