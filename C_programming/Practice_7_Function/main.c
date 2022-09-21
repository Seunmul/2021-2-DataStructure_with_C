#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person {
    char name[30];
    int age;
    void (*ptr)(struct Person*); // Person����ü��, Person����ü �����͸� ���ڷ� �޴� �Լ���, �Լ� ������
};

void print(struct Person* p)
{
    printf("%s %d\n", p->name, p->age);
}

void executer(void (*fp[])(struct Person*), struct Person p[], int count)
{
    for (int i = 0; i < count; i++)
    {
        fp[i](&p[i]); // Person ����ü �����͸� ���ڷ� ���� �Լ� ������ �迭��
                           // Pesron ����ü �迭 �׸��� ����ü ũ�⸦ ����
    }
}

void (*getPrintFunc(struct Person*p))/*��������� �޴� ���ڰ� ��Ÿ���� �Լ�, �� ��ȯ�ϴ� �Լ��� ��Ÿ��*/(struct Person*)//����� ��ȯ�ϴ� �Լ��� ���� ����.
{
    return p->ptr;
}


int main()
{
    struct Person p[3];
    p[0].ptr = print; // ���� ����ü �迭�� �Լ� ������ ��� ptr�� print �Լ��� �޸� �ּ� ���.
    p[1].ptr = print;
    p[2].ptr = print;

    scanf("%s %d %s %d %s %d",
        p[0].name, &p[0].age,
        p[1].name, &p[1].age,
        p[2].name, &p[2].age
    );

    //p[0].ptr(&p[1]);

    void (*fp[3])(struct Person*); //�Ǵٸ� �Լ������� �迭 ����

    for (int i = 0; i < sizeof(p) / sizeof(struct Person); i++)
    {
        fp[i] = getPrintFunc(&p[i]); // ������ �Լ� ������ �迭�� Print�Լ��� �޸� �ּ��� ��ȯ�Ͽ� �ִ´�..
    }

    executer(fp, p, sizeof(p) / sizeof(struct Person)); //�׷���  exectuter �Լ����� ����. fp�� ��������� Person��ü�� �Լ������� ptr�� ����Ű�� �Լ� Print, p�� ����ü �迭 ����.�� Print �Լ��� ����.
    //�׷��� ����� ����

    return 0;
}