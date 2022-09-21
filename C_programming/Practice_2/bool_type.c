#include <stdio.h>
#include <stdbool.h>    // bool, true, false가 정의된 헤더 파일

void bool_type()
{
    bool b1 = true;
    bool b2 = false;

    if (b1 == true)        // b1이 true인지 검사
        printf("참\n");    // b1이 true이므로 참이 출력됨
    else
        printf("거짓\n");

    printf("int의 크기: %d\n", sizeof(int));      // int의 크기: 4: int의 크기는 4바이트
    printf("bool의 크기: %d\n", sizeof(bool));    // bool의 크기: 1: bool의 크기는 1바이트



    printf(b1 ? "true" : "false");    // b1이 true이므로 true가 출력됨
    printf("\n");
    printf(b2 ? "true" : "false");    // b2가 false이므로 false 출력됨
    printf("\n");

    printf("%s\n", b1 ? "true" : "false");    // b1이 true이므로 true가 출력됨
    printf("%s\n", b2 ? "true" : "false");    // b2가 false이므로 false 출력됨
}