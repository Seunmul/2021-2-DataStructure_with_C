#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>




//prob 53.7 // 마지막 문제
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
    // "p[i] -> age"는 구조체의 정수형을 참조한다. age가 int형 변수이기 떄문
    // 따라서 변수 앞에 &를 붙여야 주솟값을 전달한다
    // p[i] -> name 같은 경우 배열이므로 주소값을 전달하니 &를 붙일 필요가 없다/
    // 저거 하나 찾는데 아...미치겠네 1시간 30분 날림 ㅜ

    int chk=0, chk_age = 0; // 인덱스 저장할 변수 와 최솟값 저장할 변수 선언
    chk_age = p[0]->age; // 최솟값 저장할 변수에 첫번째 구조체의 멤버 age값 대입
    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        if (p[i]->age>=chk_age) // 인덱스 0부터 최대까지 검사, 해당 인덱스에서 값이 크거나 같을 경우의 인덱스를 반환.
        {
            chk = i; 
            chk_age = p[i]->age;
        }
    }//최솟값 구조체 인덱스 chk 반환

    //printf("%d\n", p[chk]->age);
    printf("%s", p[chk]->name);
   
        for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
        {
            free(p[i]);
        }
    
    return 0;
}