#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pointer_malloc_1st_dim()
{
    //1���� ������ �����Ҵ� - >�迭ó�� ���
    int size;

    scanf("%d", &size);

    int* numPtr = malloc(sizeof(int) * size);    // int 10�� ũ�⸸ŭ ���� �޸� �Ҵ� // (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�

    numPtr[0] = 10;    // �迭ó�� �ε����� �����Ͽ� �� �Ҵ�
    printf("%d\n", numPtr[0]);    // �迭ó�� �ε����� �����Ͽ� �� ���

    numPtr[0] = 20;    // �迭ó�� �ε����� �����Ͽ� �� �Ҵ�
    printf("%d\n", *numPtr);    // ������ �������� �� ���



    for (int i = 0; i < size; i++)    // �Է¹��� ũ�⸸ŭ �ݺ�
    {
        numPtr[i] = i;                // �ε����� �����Ͽ� �� �Ҵ�
    }

    for (int i = 0; i < size; i++)    // �Է¹��� ũ�⸸ŭ �ݺ�
    {
        printf("%d\n", numPtr[i]);    // �ε����� �����Ͽ� �� ���
    }

    free(numPtr);    // �������� �Ҵ��� �޸� ����
}