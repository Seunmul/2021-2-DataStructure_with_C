#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_test_1()
{
    char* s1 = "Hello";
    char s2[10] = "Hello";

    printf("%d\n", strlen(s1));
    printf("%d\n", strlen(s2)); //배열 크기랑 관련 X

    int ret = strcmp(s1, s2);

    printf("%d\n", ret);

    // aaa는 ASCII 코드로 97 97 97
        // aab는 ASCII 코드로 97 97 98
        // aac는 ASCII 코드로 97 97 99

    printf("%d\n", strcmp("aaa", "aaa"));    //  0: aaa와 aaa는 같으므로 0
    printf("%d\n", strcmp("aab", "aaa"));    //  1: aab와 aaa 중에서 aab가 크므로 1
    printf("%d\n", strcmp("aab", "aac"));    // -1: aab와 aac 중에서 aac가 크므로 -1
    
}