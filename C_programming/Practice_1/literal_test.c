#include <stdio.h>

void literal_test()
{

    printf("%d\n", 19);        // 19: 10�� ���� ���ͷ�
    printf("0%o\n", 017);      // 017: 8�� ���� ���ͷ�, �տ� 0
    printf("0x%X\n", 0x1F);    // 0x1F: 16�� ���� ���ͷ�, �տ� 0x
    printf("%f\n", 0.1f);       // 0.100000: �Ǽ� ���ͷ� �Ҽ��� ǥ��
    printf("%f\n", 0.1F);       // 0.100000: �Ǽ� ���ͷ� �Ҽ��� ǥ��
    printf("%f\n", 1.0e-5f);    // 0.000010: �Ǽ� ���ͷ� ���� ǥ���
    printf("%f\n", 1.0E-5F);    // 0.000010: �Ǽ� ���ͷ� ���� ǥ���

    printf("\n\n");
    printf("%ld\n", -10L);                       // long ũ���� ���� ���ͷ�
    printf("%lld\n", -1234567890123456789LL);    // long long ũ���� ���� ���ͷ�

    printf("%u\n", 10U);                         // unsigned int ũ���� ���� ���ͷ�
    printf("%lu\n", 1234567890UL);               // unsigned long ũ���� ���� ���ͷ�

    printf("%lu\n", 10UL);                       // unsigned long ũ���� ���� ���ͷ�
    printf("%llu\n", 1234567890123456789ULL);    // unsigned long long ũ���� ���� ���ͷ�
    printf("0%lo\n", 017L);             // long ũ���� 8�� ���� ���ͷ�
    printf("0%lo\n", 017UL);            // unsigned long ũ���� 8�� ���� ���ͷ�
    printf("0x%lX\n", 0x7FFFFFL);       // long ũ���� 16�� ���� ���ͷ�
    printf("0x%lX\n", 0xFFFFFFFFUL);    // unsigned long ũ���� 16�� ���� ���ͷ�


    printf("%f\n", 0.1f);     // 0.100000: float ũ���� �Ǽ� ���ͷ�
    printf("%f\n", 0.1F);     // 0.100000: float ũ���� �Ǽ� ���ͷ�
    printf("%f\n", 0.1);      // 0.100000: double ũ���� �Ǽ� ���ͷ�
    printf("%Lf\n", 0.1l);    // 0.100000: long double ũ���� �Ǽ� ���ͷ�
    printf("%Lf\n", 0.1L);    // 0.100000: long double ũ���� �Ǽ� ���ͷ�

    printf("%f\n", 1.0e-5f);     // 0.000010: float ũ���� �Ǽ� ���ͷ�
    printf("%f\n", 1.0e-5F);     // 0.000010: float ũ���� �Ǽ� ���ͷ�
    printf("%f\n", 1.0e-5);      // 0.000010: double ũ���� �Ǽ� ���ͷ�
    printf("%Lf\n", 1.0e-5l);    // 0.000010: long double ũ���� �Ǽ� ���ͷ�
    printf("%Lf\n", 1.0e-5L);    // 0.000010: long double ũ���� �Ǽ� ���ͷ�

    printf("%s %o %lld %Lf\n", "Hello, world!", 076, -2147483647LL, 4.528172f);

}
