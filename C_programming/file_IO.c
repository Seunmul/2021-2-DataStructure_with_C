#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDATA 300

int main()
{
    char Fn[30] = { 0, }; // file name
    char* buffer;
    char* tok;
    int buffer_size = 0;
    int size_Data =0;
    int integer_Data[MAXDATA] = { 0, };
    int i=0;

    FILE* fp;

    printf("\n\nInput file name :  ");
    if (!scanf(" %s", Fn))
        return 0;
    fp = fopen(Fn, "r");
    if (fp == NULL)
    {
        printf("\nWrong File name.\n\n"); return 0;
    }

    fseek(fp, 0, SEEK_END); // 파일포인터로 끝까지 파일전체 읽기
    buffer_size = ftell(fp); // 파일포인터의 끝 위치를 반환
    buffer = (char*)malloc(buffer_size + 1); // 문자열 포인터에 저장(파일 전체 사이즈 +1('/0') 고려)
    if (buffer == NULL)
        return 0;
    memset(buffer, 0, buffer_size + 1);  // 버퍼 메모리 초기화
    rewind(fp); // fp위치 0으로
    fread(buffer, buffer_size + 1, 1, fp); // 파일을 읽어서 저장 : 버퍼 메모리에 저장 
    fclose(fp); // 파일포인터 삭제
    
    printf("%s\n",buffer); // buffer 에 저장

    //tok에 buffer에 저장된 문자열을 특정 문자를 기준으로 잘라서 저장
    i = 0;
    tok = strtok(buffer, " \n"); 
    integer_Data[i] = atoi(tok); 
    //printf("%d ", integer_Data[i]);
    while (tok != NULL)
    {
        tok = strtok(NULL, " \n");
        if (tok == NULL)
            break;
        
        integer_Data[++i] = atoi(tok);
      //  printf("%d ", integer_Data[i]);
    }

    return 0;
}