#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_chk();
int compare();

int main()
{
    char* input1 = malloc(sizeof(char) * 200);
    char* input2 = malloc(sizeof(char) * 200);
    char input_tot[400] = { 0, };

    printf("Input :\n");
    scanf("%[^\n]s ", input1);
    getchar();
    scanf("%[^\n]s ", input2);
    getchar();

    // 입력 숫자 개수 및 오름차순 판별, input_chk, 입력숫자가 2*10이 아닐 경우 0반환, 오름차순이 아닐 경우 1 반환, 둘 다 아닐 경우 2 바환
    switch (input_chk(input1))
    {
    case 0:
        printf("You should input 20 numbers in total");
        return 0; //입력 숫자가 10개가 아닐 시 프로그램 종료
        break;
    case 1:
        printf("The input numbers are not in ascending order");
        return 0;  //입력 숫자가 오름차순이 아닐 시 프로그램 종료
        break;
    default:
        break;
    }

    switch (input_chk(input2))
    {
    case 0:
        printf("You should input 20 numbers in total");
        return 0; //입력 숫자가 10개가 아닐 시 프로그램 종료
        break;
    case 1:
        printf("The input numbers are not in ascending order");
        return 0;  //입력 숫자가 오름차순이 아닐 시 프로그램 종료
        break;
    default:
        break;
    }

    //조건 판별 후 result 문자열에 두 인풋값 합침
    strcpy(input_tot, input1);
    strcat(input_tot, " ");
    strcat(input_tot, input2);


    int result[20] = { 0, };  //크기 20의 정수배열 선언 후 숫자 담기.
    int i = 0;
    int j = 0;


    char* tok = strtok(input_tot, " ,");
    while (tok != NULL)
    {
        if (tok != "," && tok != " ")
        {
            result[j] = atoi(tok);
            i++;
            j++;
            tok = strtok(NULL, " ,");
        }
        else
        {
            i++;
            tok = strtok(NULL, " ,");
        }
    }

    qsort(result, sizeof(result) / sizeof(int), sizeof(int), compare); //퀵정렬 함수 사용

    // 정렬 후 중복 제거
    int k = 0;
    int dedup_result[20] = { 0, };
    for (int i = 0; i < j; i++)
    {
        if (result[i] != result[i + 1])
        {
            dedup_result[k] = result[i];
            k++;
        }
    }

    printf("Output:\n");
    //결과값 출력
    for (int i = 0; i < k; i++)
    {
        printf("%d", dedup_result[i]);
        if(i+1==k)
        {
            continue;
        }
        printf(", ");
    }

    printf("\n");

    free(input1);
    free(input2);
    return 0;
}


int compare(const void* a, const void* b)    // 퀵정렬 오름차순 비교 함수 구현
{
    int num1 = *(int*)a;    
    int num2 = *(int*)b;   

    if (num1 < num2)    
        return -1;      

    if (num1 > num2)    
        return 1;       

    return 0;   
}



//입력 숫자 개수 체크 및 오름차순 체크 함수
int input_chk(char* str_in)
{
    void* str = malloc(sizeof(char) * 200);
    int chk_asc_tok[200] = { 0, };
    int i = 0;
    int cnt = 0;
    int min = 0;
    int chk=2;

    strcpy(str, str_in);
    char* tok = strtok(str, " ,");
    //각 토큰으로 나누어서 숫자일 경우에만 cnt 카운트, cnt카운트가 10이 아닐 경우  0 반환
    while (tok != NULL)
    {
        if (tok != "," && tok != " ")
        {
            
            chk_asc_tok[cnt] = atoi(tok);
            cnt++;
            i++;
            //printf("%d", atoi(tok));
            tok = strtok(NULL, " ,");
            
        }
        else
        {
            i++;
            tok = strtok(NULL, " ,");

        }
    }
    //printf("\n\n");
    if (cnt != 10)
    {
        chk = 0;
    }
    else //cnt 카운트가 10인 경우에 한해 오름차순 테스트, 오름차순이 아닐 경우 1 반환 
    {
        min = chk_asc_tok[0];
        for (i = 0;i < cnt-1; i++)
        {
            //printf("%d\n", chk_asc_tok[i]);
            if (min > chk_asc_tok[i + 1])
            {
                chk = 1;
                break;
            }
            else
            {
                min = chk_asc_tok[i + 1];
                continue;
            }
        }
    }
    free(str);
    return chk;
}