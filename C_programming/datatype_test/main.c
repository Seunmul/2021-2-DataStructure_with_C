#include <stdio.h>
#include <stdint.h> // ũ�⺰�� ���� �ڷ����� ���ǵ� ��� ����

int main(void)
{
    unsigned short int num1;
    unsigned long int num2;
    signed char num3;

    num1 = 65536;
    num2 = 4294967296;
    num3 = 128;

    printf("%u %u %d\n", num1, num2, num3);


    
   /*
    stdint_test();
    datatype_test();
    size_test();
    */
    return 0;
}