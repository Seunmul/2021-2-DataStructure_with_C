#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main(void)
{
   // literal_test();
    //num_test1();
    //num_test2();
    //num_test3();
    //repeat_test();

    int num1, num2;

    scanf("%d %d", &num1, &num2);

    for (int i = num1; i <= num2; i++)
    {
        if (i % 5 == 0 && i % 11 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (i % 5 == 0)
        {
            printf("Fizz\n");
        }
        else if (i % 11 == 0)
        {
            printf("Buzz\n");
        }
        else
            printf("%d\n",i);

    }

    return 0;

}