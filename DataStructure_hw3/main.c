#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum index_choose
{
    name = 1,
    age,
    math,
    english,
    history
};

typedef struct _Student
{
    char name[30];
    int age;
    int math;
    int english;
    int history;
}Student;

void CurrentData(Student **dataset,int num,int* ex_sort_num_ptr)
{
    switch (*ex_sort_num_ptr) 
    {
    case(0):
            printf("No Name Age Math English History\n");

            for (int i = 0; i < num; i++)
            {
                printf("%d %s %d %d %d %d\n",
                    i + 1, dataset[i]->name, dataset[i]->age,
                    dataset[i]->math, dataset[i]->english, dataset[i]->history);
            }
            printf("\n");
            break;

    case(1):
        printf("No Name Age Math English History\n");

        for (int i = 0; i < num; i++)
        {
            printf("%d %s %d %d %d %d\n",
                i + 1, dataset[i]->name, dataset[i]->age,
                dataset[i]->math, dataset[i]->english, dataset[i]->history);
        }
        printf("\n");
        break;

    case(2):
        printf("No Age Name Math English History\n");

        for (int i = 0; i < num; i++)
        {
            printf("%d %d %s %d %d %d\n",
                i + 1, dataset[i]->age, dataset[i]->name,
                dataset[i]->math, dataset[i]->english, dataset[i]->history);
        }
        printf("\n");
        break;

    case(3):
        printf("No Math Name Age English History\n");

        for (int i = 0; i < num; i++)
        {
            printf("%d %d %s %d %d %d\n",
                i + 1, dataset[i]->math, dataset[i]->name, 
                dataset[i]->age,  dataset[i]->english, dataset[i]->history);
        }
        printf("\n");
        break;

    case(4):
        printf("No English Name Age Math History\n");

        for (int i = 0; i < num; i++)
        {
            printf("%d %d %s %d %d %d\n",
                i + 1, dataset[i]->english, dataset[i]->name, dataset[i]->age,
                dataset[i]->math,  dataset[i]->history);
        }
        printf("\n");
        break;

    case(5):
        printf("No History Name Age Math English\n");

        for (int i = 0; i < num; i++)
        {
            printf("%d %d %s %d %d %d\n",
                i + 1, dataset[i]->history, dataset[i]->name, dataset[i]->age,
                dataset[i]->math, dataset[i]->english);
        }
        printf("\n");
        break;
    default:
        printf("wrong data. program terminates");
        break;
    }
}

void DoSortByIndex(Student** PPStudent, int size, int num, int* ex_sort_num_ptr)
{
    int i = 0;
    int j = 0;

    Student* temp = malloc(sizeof(Student));
    if (!(temp == NULL)) {
        memset(temp, 0, sizeof(Student));
    }
    else
    {
        return;
    }

    enum index_choose index = num;
    switch (index)
    {
    case name:
        printf("NAME\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (strcmp(PPStudent[i]->name,PPStudent[i + 1]->name) > 0 )
                {
                    memcpy(temp, PPStudent[i], sizeof(Student));
                    memcpy(PPStudent[i], PPStudent[i + 1], sizeof(Student));
                    memcpy(PPStudent[i + 1], temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        *ex_sort_num_ptr = 1;
        break;

    case age:
        printf("AGE\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (PPStudent[i]->age > PPStudent[i + 1]->age)
                {
                    memcpy(temp, PPStudent[i], sizeof(Student));
                    memcpy(PPStudent[i], PPStudent[i + 1], sizeof(Student));
                    memcpy(PPStudent[i + 1], temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        *ex_sort_num_ptr = 2;
        break;

    case math:
        printf("MATH\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (PPStudent[i]->math > PPStudent[i + 1]->math)
                {
                    memcpy(temp, PPStudent[i], sizeof(Student));
                    memcpy(PPStudent[i], PPStudent[i + 1], sizeof(Student));
                    memcpy(PPStudent[i + 1], temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        *ex_sort_num_ptr = 3;
        break;

    case english:
        printf("ENGLISH\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (PPStudent[i]->english > PPStudent[i + 1]->english)
                {
                    memcpy(temp, PPStudent[i], sizeof(Student));
                    memcpy(PPStudent[i], PPStudent[i + 1], sizeof(Student));
                    memcpy(PPStudent[i + 1], temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        *ex_sort_num_ptr = 4;
        break;

    case history:
        printf("HISTORY\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (PPStudent[i]->history > PPStudent[i + 1]->history)
                {
                    memcpy(temp, PPStudent[i], sizeof(Student));
                    memcpy(PPStudent[i], PPStudent[i + 1], sizeof(Student));
                    memcpy(PPStudent[i + 1], temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        *ex_sort_num_ptr = 5;
        break;

    default:
        printf("check the field num to sort by");
        break;


    }
    free(temp);
    printf("\n\n");
}

int main()
{
    char* sel = NULL;
    int inputchk = 0;
    int insert_cnt = 0; //insert 실행 후 cnt ++
    int st_data_num = 0; //insert 실행 후 입력된 학생 수 저장
    int field_num = 0; // 정렬 필드 넘버 저장
    int ex_sort_num = 0; // 정렬 실행 후 이전 정렬 필드 넘버 저장(처음 insert 실행 시 0)
    int* ex_sort_num_ptr=&ex_sort_num;

    char result[100] = { 0, };
    char Fn[100] = { 0, };

    FILE* fp = NULL;
    Student** st_data = { NULL, }; //insert 실행 후 구조체 포인터 위치 저장

    while (1)
    {
        printf("1) Insert\n");
        printf("2) Sort\n");
        printf("3) Quit\n");
        printf("Select a menu : ");

        if (sel == NULL)
        {
            sel = (char*)malloc(sizeof(char)*31);
        }
        inputchk=scanf(" %s", sel);

        switch (atoi(sel))
        {
        case 1:
            //Insert
             //파일이름 입력
            printf("File name : ");
            inputchk=scanf(" %s", Fn);
            printf("--------Load File : %s--------\n", Fn);

            //입력한 txt파일에서 전체 글자 읽기 및 전체 사이즈 반환
            fp = fopen(Fn, "r");
            if (fp == NULL)
            {
                printf("Wrong File name.\n\n"); break;
            }

            fseek(fp, 0, SEEK_END);
            int size = ftell(fp); // size : 입력 파일 사이즈
            char* buffer = malloc(size + 1);
            memset(buffer, 0, size + 1);

            rewind(fp);
            fread(buffer, size + 1, 1, fp);            //printf("전체 자료 : \n%s\n\n", buffer);
            fclose(fp);

            //받은 문장에서 엔터 키 반환(문장 수 반환=학생수 반환)

            char* chk = (char*)malloc(size + 1);
            memset(chk, 0, size + 1);
            strcpy(chk, buffer); // chk에 받은 파일 문자들 전부 복사.
            char* tok;
            int cnt = 0;

            tok = strtok(chk, "\n");
            while (tok != NULL)
            {
                tok = strtok(NULL, "\n");
                cnt++;
            }
            //  printf("%d문단\n", cnt); //자료 학생 수 반환

             //학생 수 만큼 구조체 동적할당 선언 + 각 문단별 길이 저장
            int i = 0;
            int j = 0;

            char** sArr = (char**)malloc(sizeof(char*) * (cnt)); // 포인터 배열로 사용할 이중 포인터 선언
            for (int i = 0; i < cnt; i++)    // 요소 개수만큼 반복
            {
                 sArr[i] = (char*)malloc(sizeof(Student));    // 각 요소에 구조체 크기만큼 메모리 할당
                 memset(sArr[i], 0, sizeof(Student));
                 // printf("sArr[%d]\n", i);                
            }
           // printf("%d", sizeof(char**) * cnt);

            if (insert_cnt == 0) //insert_cnt가 1이면 이미 파일을 읽어들었으므로 동적할당 실행 X,.기존 할당된 메모리 계속 사용.
            {
                st_data = (Student**)malloc(sizeof(Student*) * (cnt)); // 구조체 포인터 동적 할당
                for (int i = 0; i < cnt; i++)    // 요소 개수만큼 반복
                {
                    st_data[i] = (Student*)malloc(sizeof(Student));    // 각 요소에 구조체 크기만큼 메모리 할당
                    memset(st_data[i], 0, sizeof(Student));
                    //printf("구조체 생성 st_data[%d]\n", i);
                }
            }
            else // 동적할당 실행 X, 할당된 메모리만 초기화.
            {
                for (int i = 0; i < cnt; i++)    // 요소 개수만큼 반복
                {
                    memset(st_data[i], 0, sizeof(Student));
                }
            }

            strcpy(chk, buffer);
            free(buffer);

            tok = strtok(chk, "\n");
            sArr[0] = tok;
            i = 0;
            while (tok != NULL)
            {
                i++;                tok = strtok(NULL, "\n");
                if (tok == NULL)    continue;
                
                sArr[i] = tok;
            }

            //각 문단별 요소 구조체 멤버에 대입
            i = 0;
            char sArrchk[30] = { 0, };
            char* sArrtok;
            for (i = 0; i < cnt; i++)
            {
                sArrtok = strtok(sArr[i], " ");
                for (j = 0; j < 5; j++)
                {
                    switch (j)
                    {
                    case 0:
                        strcpy(st_data[i]->name, sArrtok);
                        break;
                    case 1:
                        if (atoi(sArrtok) < 0)
                        {
                            printf("The age cannot be a negative number. Program terminates.\n"); goto END;
                        }
                        else  st_data[i]->age = atoi(sArrtok);
                        break;
                    case 2:
                        if (atoi(sArrtok) < 0 || atoi(sArrtok) > 100)
                        {
                            printf("Grades must be higher than 0 and lower than 100. Program terminates.\n"); goto END;
                        }
                        else  st_data[i]->math = atoi(sArrtok);
                        break;
                    case 3:
                        if (atoi(sArrtok) < 0 || atoi(sArrtok) > 100)
                        {
                            printf("Grades must be higher than 0 and lower than 100. Program terminates.\n"); goto END;
                        }
                        else  st_data[i]->english = atoi(sArrtok);
                        break;
                    case 4:
                        if (atoi(sArrtok) < 0 || atoi(sArrtok) > 100)
                        {
                            printf("Grades must be higher than 0 and lower than 100. Program terminates.\n"); goto END;
                        }
                        else  st_data[i]->history = atoi(sArrtok);
                        break;
                    default:
                        break;
                    }
                    //printf("%s", sArrtok);
                    sArrtok = strtok(NULL, " ");
                }
            }

            printf("\n");
            printf("Result:\n");
            ex_sort_num = 0; //이전 정렬 필드 넘버 초기화. 
            CurrentData(st_data, cnt,ex_sort_num_ptr);
            printf("-----------------------------------------\n");
            printf("-----------------------------------------\n");
            printf("\n");

            free(chk); // strtok함수로 자른 문자열의 메모리주소를 sArr영역으로 저장했으므로 메모리 해제

            st_data_num = cnt;
            insert_cnt = 1; // 전역변수 inser_cnt에 1 대입, 동적할당 2번 하는 걸 막기 위함.

            break;

        case 2:

            if (st_data == NULL)
            {
                printf("There is no file to sort. please insert file.\n\n");
                break;
            }

            printf("Choose the field to sort by  \n");
            printf("1 : Name  2 : Age  3: Math  4:English  5: History \n");
            printf("Your input : ");
            inputchk=scanf("%d", &field_num);

            DoSortByIndex(st_data, st_data_num, field_num,ex_sort_num_ptr);

            printf("\n");
            printf("Result:\n");

            CurrentData(st_data, st_data_num, ex_sort_num_ptr);
            
            printf("-----------------------------------------\n");
            printf("-----------------------------------------\n");
            printf("\n");
            break;

        case 3:
            printf("Close the program.\n");

            if (insert_cnt == 0)
            {
                goto END;
            }
            else
            {
                for (i = 0; i < cnt; i++)    // 요소 개수만큼 반복
                {
                    free(st_data[i]);    // 각 요소의 동적 메모리 해제
                }
                free(st_data);
                goto END;
            }

        default:
            printf("Check the number of menu\n\n");
            break;
        }
    }
    END:

    if (sel != NULL)
    {
        free(sel);
    }

    return 0;
}