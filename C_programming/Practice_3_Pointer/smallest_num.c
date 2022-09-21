#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void smallest_num()
{
    int numArr[5];
    int smallestNumber;

    scanf("%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);
    //8มู

    int* ptr = numArr;
    smallestNumber = *ptr;
    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
    {
        if (smallestNumber >= *(ptr + i))
        {
            smallestNumber = *(ptr + i);
        }
    }

    printf("%d\n", smallestNumber);
}