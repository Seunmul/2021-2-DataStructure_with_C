#include <stdio.h>

void literal_test()
{

    printf("%d\n", 19);        // 19: 10진 정수 리터럴
    printf("0%o\n", 017);      // 017: 8진 정수 리터럴, 앞에 0
    printf("0x%X\n", 0x1F);    // 0x1F: 16진 정수 리터럴, 앞에 0x
    printf("%f\n", 0.1f);       // 0.100000: 실수 리터럴 소수점 표기
    printf("%f\n", 0.1F);       // 0.100000: 실수 리터럴 소수점 표기
    printf("%f\n", 1.0e-5f);    // 0.000010: 실수 리터럴 지수 표기법
    printf("%f\n", 1.0E-5F);    // 0.000010: 실수 리터럴 지수 표기법

    printf("\n\n");
    printf("%ld\n", -10L);                       // long 크기의 정수 리터럴
    printf("%lld\n", -1234567890123456789LL);    // long long 크기의 정수 리터럴

    printf("%u\n", 10U);                         // unsigned int 크기의 정수 리터럴
    printf("%lu\n", 1234567890UL);               // unsigned long 크기의 정수 리터럴

    printf("%lu\n", 10UL);                       // unsigned long 크기의 정수 리터럴
    printf("%llu\n", 1234567890123456789ULL);    // unsigned long long 크기의 정수 리터럴
    printf("0%lo\n", 017L);             // long 크기의 8진 정수 리터럴
    printf("0%lo\n", 017UL);            // unsigned long 크기의 8진 정수 리터럴
    printf("0x%lX\n", 0x7FFFFFL);       // long 크기의 16진 정수 리터럴
    printf("0x%lX\n", 0xFFFFFFFFUL);    // unsigned long 크기의 16진 정수 리터럴


    printf("%f\n", 0.1f);     // 0.100000: float 크기의 실수 리터럴
    printf("%f\n", 0.1F);     // 0.100000: float 크기의 실수 리터럴
    printf("%f\n", 0.1);      // 0.100000: double 크기의 실수 리터럴
    printf("%Lf\n", 0.1l);    // 0.100000: long double 크기의 실수 리터럴
    printf("%Lf\n", 0.1L);    // 0.100000: long double 크기의 실수 리터럴

    printf("%f\n", 1.0e-5f);     // 0.000010: float 크기의 실수 리터럴
    printf("%f\n", 1.0e-5F);     // 0.000010: float 크기의 실수 리터럴
    printf("%f\n", 1.0e-5);      // 0.000010: double 크기의 실수 리터럴
    printf("%Lf\n", 1.0e-5l);    // 0.000010: long double 크기의 실수 리터럴
    printf("%Lf\n", 1.0e-5L);    // 0.000010: long double 크기의 실수 리터럴

    printf("%s %o %lld %Lf\n", "Hello, world!", 076, -2147483647LL, 4.528172f);

}
