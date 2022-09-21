#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>




//prob 53.7 // ������ ����
struct Person {
    char name[30];
    int age;
};

int main()
{
    struct Person* p[5];
    
    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        p[i] = malloc(sizeof(struct Person));
    }

    scanf("%s %d %s %d %s %d %s %d %s %d", (p[0]->name), &(p[0]->age), (p[1]->name), &(p[1]->age), (p[2]->name), &(p[2]->age) , (p[3]->name), &(p[3]->age), (p[4]->name), &(p[4]->age));
    // "p[i] -> age"�� ����ü�� �������� �����Ѵ�. age�� int�� �����̱� ����
    // ���� ���� �տ� &�� �ٿ��� �ּڰ��� �����Ѵ�
    // p[i] -> name ���� ��� �迭�̹Ƿ� �ּҰ��� �����ϴ� &�� ���� �ʿ䰡 ����/
    // ���� �ϳ� ã�µ� ��...��ġ�ڳ� 1�ð� 30�� ���� ��

    int chk=0, chk_age = 0; // �ε��� ������ ���� �� �ּڰ� ������ ���� ����
    chk_age = p[0]->age; // �ּڰ� ������ ������ ù��° ����ü�� ��� age�� ����
    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        if (p[i]->age>=chk_age) // �ε��� 0���� �ִ���� �˻�, �ش� �ε������� ���� ũ�ų� ���� ����� �ε����� ��ȯ.
        {
            chk = i; 
            chk_age = p[i]->age;
        }
    }//�ּڰ� ����ü �ε��� chk ��ȯ

    //printf("%d\n", p[chk]->age);
    printf("%s", p[chk]->name);
   
        for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
        {
            free(p[i]);
        }
    
    return 0;
}