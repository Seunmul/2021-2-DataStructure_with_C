#include <stdio.h>
#include <stdbool.h>    // bool, true, false�� ���ǵ� ��� ����

void bool_type()
{
    bool b1 = true;
    bool b2 = false;

    if (b1 == true)        // b1�� true���� �˻�
        printf("��\n");    // b1�� true�̹Ƿ� ���� ��µ�
    else
        printf("����\n");

    printf("int�� ũ��: %d\n", sizeof(int));      // int�� ũ��: 4: int�� ũ��� 4����Ʈ
    printf("bool�� ũ��: %d\n", sizeof(bool));    // bool�� ũ��: 1: bool�� ũ��� 1����Ʈ



    printf(b1 ? "true" : "false");    // b1�� true�̹Ƿ� true�� ��µ�
    printf("\n");
    printf(b2 ? "true" : "false");    // b2�� false�̹Ƿ� false ��µ�
    printf("\n");

    printf("%s\n", b1 ? "true" : "false");    // b1�� true�̹Ƿ� true�� ��µ�
    printf("%s\n", b2 ? "true" : "false");    // b2�� false�̹Ƿ� false ��µ�
}