#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

enum index_choose
{
    name = 1,
    age,
    math,
    english,
    history
};

int insert_cnt = 0;

typedef struct _Student {
    char name[30];
    int age;
    int math;
    int english;
    int history;
}Student;

void DoSortByIndex(Student s[], int size, enum index_choose index) {
    
    int i = 0;
    int j = 0;
    Student temp = { NULL, };

    switch (index)
    {
    case name:
        printf("NAME\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (s[i].name[0] > s[i + 1].name[0])
                {
                    memcpy(&temp, &s[i], sizeof(Student));
                    memcpy(&s[i], &s[i + 1], sizeof(Student));
                    memcpy(&s[i + 1], &temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        break;

    case age:
        printf("AGE\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (s[i].age > s[i + 1].age)
                {
                    memcpy(&temp, &s[i], sizeof(Student));
                    memcpy(&s[i], &s[i + 1], sizeof(Student));
                    memcpy(&s[i + 1], &temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        break;

    case math:
        printf("MATH\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (s[i].math > s[i + 1].math)
                {
                    memcpy(&temp, &s[i], sizeof(Student));
                    memcpy(&s[i], &s[i + 1], sizeof(Student));
                    memcpy(&s[i + 1], &temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        break;

    case english:
        printf("ENGLISH\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (s[i].english > s[i + 1].english)
                {
                    memcpy(&temp, &s[i], sizeof(Student));
                    memcpy(&s[i], &s[i + 1], sizeof(Student));
                    memcpy(&s[i + 1], &temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        break;

    case history:
        printf("HISTORY\n");
        for (j = 0; j < size; j++)
        {
            for (i = 0; i < size - 1; i++)
            {
                if (s[i].history > s[i + 1].history)
                {
                    memcpy(&temp, &s[i], sizeof(Student));
                    memcpy(&s[i], &s[i + 1], sizeof(Student));
                    memcpy(&s[i + 1], &temp, sizeof(Student));
                }
                else
                {
                    continue;
                }
            }
        }
        break;

    default:
        break;

    }
    printf("\n\n");
    printf("RESULT : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%s %d %d %d %d", s[i].name, s[i].age, s[i].math, s[i].english, s[i].history);
        printf("\n");
    }
   
}

int main()
{
    /*
    gu 10 12 50 99
    kim 24 20 50 34
    lee 23 33 40 33
    sung 30 40 -22 12
*/
    Student s[4] = { NULL, };
    strcpy(s[0].name,"gu"); s[0].age = 10; s[0].math = 12; s[0].english=50; s[0].history = 99;
    strcpy(s[1].name, "kim"); s[1].age = 24; s[1].math = 20; s[1].english = 50; s[1].history = 34;
    strcpy(s[2].name, "lee"); s[2].age = 23; s[2].math = 33; s[2].english = 40; s[2].history = 33;
    strcpy(s[3].name, "sung"); s[3].age = 30; s[3].math = 40; s[3].english = 22; s[3].history = 12;

    for (int i = 0; i < sizeof(s) / sizeof(Student); i++)
    {
        printf("%s %d %d %d %d", s[i].name, s[i].age, s[i].math, s[i].english, s[i].history);
        printf("\n");
    }

    printf("���� �ε����� Ÿ���� �ϼ���\n");
    char *index=NULL;
    enum index_choose num;
    if (index == NULL)
    {
        index = malloc(1024);
    }
    scanf("%d", &num);
    
    DoSortByIndex(s, sizeof(s) / sizeof(Student), num);


    free(index);
    return 0;
}
/*
int main()
{
    int cnt;
    scanf("%d", &cnt);
    Student** p = malloc(sizeof(Student*)*cnt);    // ����ü ���� ������ �迭 ����
   
    printf("%d\n", sizeof(int) );
    printf("%d\n", sizeof(int)*4) ;
    printf("%d\n", sizeof(char[30]));
    printf("%d\n", sizeof(p));
   
  // ����ü ������ �迭 ��ü ũ�⿡�� ���(����ü ������)�� ũ��� ������ ��� ������ ����
    for (int i = 0; i < cnt; i++)    // ��� ������ŭ �ݺ�
    {
        p[i] = malloc(sizeof(Student));    // �� ��ҿ� ����ü ũ�⸸ŭ �޸� �Ҵ�
        memset(p[i], 0, sizeof(Student));
        printf("����ü ����p[%d]\n", i);
    }
    
    for (int i = 0; i < cnt; i++)    // ��� ������ŭ �ݺ�
    {
        strcpy(p[i]->name,"char"); // ����� ���ڿ� �Ҵ�
        p[i]->age = "1"; // ����� ���� �Ҵ�
        
    }
    int s;
    scanf("%d", &s);
    p[0]->age = s;
    printf("%d", p[0]->age);
    printf("%s", p[0]->name);
    
    for (int i = 0; i < cnt; i++)    // ��� ������ŭ �ݺ�
    {
       
            free(p[i]);    // �� ����� ���� �޸� ����
        
    }

    free(p);

    return 0;
}
*/

/*
char buffer[10000] = {0, };

 FILE* src = fopen("words.txt", "r");
 fread(buffer, sizeof(buffer), 1, src);
 //printf("%s\n", buffer);

 for (int i =sizeof(buffer)-1; i >=0; i--)
 {
     if (buffer[i] == NULL)
         continue;
     fwrite(&buffer[i], 1, 1, stdout);
 }

 fclose(src);
 */
