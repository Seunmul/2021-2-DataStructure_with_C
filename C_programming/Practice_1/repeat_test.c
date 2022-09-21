#include <stdio.h>

void repeat_test()
{
    printf("repest_test\n");

    int height;

    scanf("%d", &height);

    for (int i =height; i >=1; i--)
    {
        for (int j = 1; j <= 2*height-1 ; j++)
        {
            if( ( j>=i && j<=2*height-i) )
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}