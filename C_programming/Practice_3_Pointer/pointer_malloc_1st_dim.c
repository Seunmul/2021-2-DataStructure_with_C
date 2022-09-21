#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pointer_malloc_1st_dim()
{
    //1차원 포인터 동적할당 - >배열처럼 사용
    int size;

    scanf("%d", &size);

    int* numPtr = malloc(sizeof(int) * size);    // int 10개 크기만큼 동적 메모리 할당 // (int 크기 * 입력받은 크기)만큼 동적 메모리 할당

    numPtr[0] = 10;    // 배열처럼 인덱스로 접근하여 값 할당
    printf("%d\n", numPtr[0]);    // 배열처럼 인덱스로 접근하여 값 출력

    numPtr[0] = 20;    // 배열처럼 인덱스로 접근하여 값 할당
    printf("%d\n", *numPtr);    // 포인터 역참조로 값 출력



    for (int i = 0; i < size; i++)    // 입력받은 크기만큼 반복
    {
        numPtr[i] = i;                // 인덱스로 접근하여 값 할당
    }

    for (int i = 0; i < size; i++)    // 입력받은 크기만큼 반복
    {
        printf("%d\n", numPtr[i]);    // 인덱스로 접근하여 값 출력
    }

    free(numPtr);    // 동적으로 할당한 메모리 해제
}