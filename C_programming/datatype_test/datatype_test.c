#include <stdio.h>

int datatype_test()
{
    char num1 = 200;
    short num2 = 30000;
    int num3 = -1234567890;
    long num4 = -1234567890;
    long long num5 = -1234567890123456789;

    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);

    unsigned char num6 = 200;                          // 1����Ʈ ��ȣ ���� ���������� 
                                                       // ������ �����ϰ� �� �Ҵ�

    unsigned short num7 = 60000;                       // 2����Ʈ ��ȣ ���� ���������� 
                                                       // ������ �����ϰ� �� �Ҵ�

    unsigned int num8 = 4123456789;                    // 4����Ʈ ��ȣ ���� ���������� 
                                                       // ������ �����ϰ� �� �Ҵ�

    unsigned long num9 = 4123456789;                   // 4����Ʈ ��ȣ ���� ���������� 
                                                       // ������ �����ϰ� �� �Ҵ�

    unsigned long long num10 = 12345678901234567890;    // 8����Ʈ ��ȣ ���� ���������� 
                                                       // ������ �����ϰ� �� �Ҵ�

    // unsigned char, unsigned short, unsigned int�� %u�� ����ϰ� 
    // unsigned long�� %lu, unsigned long long�� %llu�� ���
    printf("%u %u %u %lu %llu\n", num6, num7, num8, num9, num10);
    // 200 60000 4123456789 4123456789 12345678901234567890
    return 0;
}