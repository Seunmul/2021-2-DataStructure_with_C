#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pointer_malloc_2st_dim()
{

    int** m = malloc(sizeof(int*) * 3);   // 이중 포인터에 (int 포인터 크기 * 세로 크기)만큼
                                         // 동적 메모리 할당. 배열의 세로

    for (int i = 0; i < 3; i++)            // 세로 크기만큼 반복
    {
        m[i] = malloc(sizeof(int) * 4);    // (int 크기 * 가로 크기)만큼 동적 메모리 할당.
                                           // 배열의 가로
    }

    m[0][0] = 1;    // 세로 인덱스 0, 가로 인덱스 0인 요소에 값 할당
    m[2][0] = 5;    // 세로 인덱스 2, 가로 인덱스 0인 요소에 값 할당
    m[2][3] = 2;    // 세로 인덱스 2, 가로 인덱스 3인 요소에 값 할당

    printf("%d\n", m[0][0]);    // 1: 세로 인덱스 0, 가로 인덱스 0인 요소의 값 출력
    printf("%d\n", m[2][0]);    // 5: 세로 인덱스 2, 가로 인덱스 0인 요소의 값 출력
    printf("%d\n", m[2][3]);    // 2: 세로 인덱스 2, 가로 인덱스 3인 요소의 값 출력

    for (int i = 0; i < 3; i++)    // 세로 크기만큼 반복
    {
        free(m[i]);                // 2차원 배열의 가로 공간 메모리 해제
    }

    free(m);    // 2차원 배열의 세로 공간 메모리 해제

}