#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_test_1()
{
    char* s1 = "Hello";
    char s2[10] = "Hello";

    printf("%d\n", strlen(s1));
    printf("%d\n", strlen(s2)); //�迭 ũ��� ���� X

    int ret = strcmp(s1, s2);

    printf("%d\n", ret);

    // aaa�� ASCII �ڵ�� 97 97 97
        // aab�� ASCII �ڵ�� 97 97 98
        // aac�� ASCII �ڵ�� 97 97 99

    printf("%d\n", strcmp("aaa", "aaa"));    //  0: aaa�� aaa�� �����Ƿ� 0
    printf("%d\n", strcmp("aab", "aaa"));    //  1: aab�� aaa �߿��� aab�� ũ�Ƿ� 1
    printf("%d\n", strcmp("aab", "aac"));    // -1: aab�� aac �߿��� aac�� ũ�Ƿ� -1
    
}