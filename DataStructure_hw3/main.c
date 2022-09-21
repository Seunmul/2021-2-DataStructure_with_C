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
    int insert_cnt = 0; //insert ���� �� cnt ++
    int st_data_num = 0; //insert ���� �� �Էµ� �л� �� ����
    int field_num = 0; // ���� �ʵ� �ѹ� ����
    int ex_sort_num = 0; // ���� ���� �� ���� ���� �ʵ� �ѹ� ����(ó�� insert ���� �� 0)
    int* ex_sort_num_ptr=&ex_sort_num;

    char result[100] = { 0, };
    char Fn[100] = { 0, };

    FILE* fp = NULL;
    Student** st_data = { NULL, }; //insert ���� �� ����ü ������ ��ġ ����

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
             //�����̸� �Է�
            printf("File name : ");
            inputchk=scanf(" %s", Fn);
            printf("--------Load File : %s--------\n", Fn);

            //�Է��� txt���Ͽ��� ��ü ���� �б� �� ��ü ������ ��ȯ
            fp = fopen(Fn, "r");
            if (fp == NULL)
            {
                printf("Wrong File name.\n\n"); break;
            }

            fseek(fp, 0, SEEK_END);
            int size = ftell(fp); // size : �Է� ���� ������
            char* buffer = malloc(size + 1);
            memset(buffer, 0, size + 1);

            rewind(fp);
            fread(buffer, size + 1, 1, fp);            //printf("��ü �ڷ� : \n%s\n\n", buffer);
            fclose(fp);

            //���� ���忡�� ���� Ű ��ȯ(���� �� ��ȯ=�л��� ��ȯ)

            char* chk = (char*)malloc(size + 1);
            memset(chk, 0, size + 1);
            strcpy(chk, buffer); // chk�� ���� ���� ���ڵ� ���� ����.
            char* tok;
            int cnt = 0;

            tok = strtok(chk, "\n");
            while (tok != NULL)
            {
                tok = strtok(NULL, "\n");
                cnt++;
            }
            //  printf("%d����\n", cnt); //�ڷ� �л� �� ��ȯ

             //�л� �� ��ŭ ����ü �����Ҵ� ���� + �� ���ܺ� ���� ����
            int i = 0;
            int j = 0;

            char** sArr = (char**)malloc(sizeof(char*) * (cnt)); // ������ �迭�� ����� ���� ������ ����
            for (int i = 0; i < cnt; i++)    // ��� ������ŭ �ݺ�
            {
                 sArr[i] = (char*)malloc(sizeof(Student));    // �� ��ҿ� ����ü ũ�⸸ŭ �޸� �Ҵ�
                 memset(sArr[i], 0, sizeof(Student));
                 // printf("sArr[%d]\n", i);                
            }
           // printf("%d", sizeof(char**) * cnt);

            if (insert_cnt == 0) //insert_cnt�� 1�̸� �̹� ������ �о������Ƿ� �����Ҵ� ���� X,.���� �Ҵ�� �޸� ��� ���.
            {
                st_data = (Student**)malloc(sizeof(Student*) * (cnt)); // ����ü ������ ���� �Ҵ�
                for (int i = 0; i < cnt; i++)    // ��� ������ŭ �ݺ�
                {
                    st_data[i] = (Student*)malloc(sizeof(Student));    // �� ��ҿ� ����ü ũ�⸸ŭ �޸� �Ҵ�
                    memset(st_data[i], 0, sizeof(Student));
                    //printf("����ü ���� st_data[%d]\n", i);
                }
            }
            else // �����Ҵ� ���� X, �Ҵ�� �޸𸮸� �ʱ�ȭ.
            {
                for (int i = 0; i < cnt; i++)    // ��� ������ŭ �ݺ�
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

            //�� ���ܺ� ��� ����ü ����� ����
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
            ex_sort_num = 0; //���� ���� �ʵ� �ѹ� �ʱ�ȭ. 
            CurrentData(st_data, cnt,ex_sort_num_ptr);
            printf("-----------------------------------------\n");
            printf("-----------------------------------------\n");
            printf("\n");

            free(chk); // strtok�Լ��� �ڸ� ���ڿ��� �޸��ּҸ� sArr�������� ���������Ƿ� �޸� ����

            st_data_num = cnt;
            insert_cnt = 1; // �������� inser_cnt�� 1 ����, �����Ҵ� 2�� �ϴ� �� ���� ����.

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
                for (i = 0; i < cnt; i++)    // ��� ������ŭ �ݺ�
                {
                    free(st_data[i]);    // �� ����� ���� �޸� ����
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