#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  string_test_2()
{

   
    char* s1 = malloc(sizeof(char) * 30);
    char* s2 = malloc(sizeof(char) * 30);

    scanf("%s", s1);
    scanf("%s", s2);

    printf("%s %s\n", s1, s2);
    //strcpy(s2, s1); // s2에 s1 저장.
    strcat(s2, s1); // s2에 s1 붙임.
    printf("%s", s2);

    free(s1);
    free(s2);
   
}