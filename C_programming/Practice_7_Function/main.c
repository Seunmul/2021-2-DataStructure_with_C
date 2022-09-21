#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person {
    char name[30];
    int age;
    void (*ptr)(struct Person*); // Person구조체의, Person구조체 포인터를 인자로 받는 함수의, 함수 포인터
};

void print(struct Person* p)
{
    printf("%s %d\n", p->name, p->age);
}

void executer(void (*fp[])(struct Person*), struct Person p[], int count)
{
    for (int i = 0; i < count; i++)
    {
        fp[i](&p[i]); // Person 구조체 포인터를 인자로 갖는 함수 포인터 배열과
                           // Pesron 구조체 배열 그리고 구조체 크기를 받음
    }
}

void (*getPrintFunc(struct Person*p))/*여기까지는 받는 인자가 나타내는 함수, 즉 반환하는 함수를 나타냄*/(struct Person*)//여기는 반환하는 함수가 받을 인자.
{
    return p->ptr;
}


int main()
{
    struct Person p[3];
    p[0].ptr = print; // 각각 구조체 배열의 함수 포인터 멤버 ptr에 print 함수의 메모리 주소 등록.
    p[1].ptr = print;
    p[2].ptr = print;

    scanf("%s %d %s %d %s %d",
        p[0].name, &p[0].age,
        p[1].name, &p[1].age,
        p[2].name, &p[2].age
    );

    //p[0].ptr(&p[1]);

    void (*fp[3])(struct Person*); //또다른 함수포인터 배열 생성

    for (int i = 0; i < sizeof(p) / sizeof(struct Person); i++)
    {
        fp[i] = getPrintFunc(&p[i]); // 생성한 함수 포인터 배열에 Print함수의 메모리 주소을 반환하여 넣는다..
    }

    executer(fp, p, sizeof(p) / sizeof(struct Person)); //그래서  exectuter 함수에서 실행. fp는 결과적으로 Person객체의 함수포인터 ptr이 가리키는 함수 Print, p는 구조체 배열 인자.즉 Print 함수의 인자.
    //그래서 결과값 도출

    return 0;
}