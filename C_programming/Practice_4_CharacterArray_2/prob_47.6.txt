#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int num = 0;
    char* text = malloc(sizeof(char) * 11);
    
    scanf("%d %s", &num, text);

    if (strlen(text) < num)
    {
        printf("wrong\n");
    }
    else {
        // 3-gram
        /*for (int i = 0; i < strlen(text) - 2; i++)
        {
            printf("%c%c%c\n", text[i], text[i + 1], text[i + 2]);    // 현재 문자열과 그다음 문자열 출력
        //printf("%s", text);
        }*/

        //N-gram
        for (int i = 0; i < strlen(text)-(num-1); i++)
        {
            for (int j = 0; j<num; j++)
                printf("%c", text[i + j]);

            printf("\n");
        }
    }
    free(text);
    return 0;
}