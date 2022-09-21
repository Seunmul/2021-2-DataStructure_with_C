//Stack_Array.h  

#ifndef Stack_Array_H
#define Stack_Array_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//header
typedef int Element;

typedef struct _Stack {
    Element* stack;
    int size;
    int top;
} Stack;

bool IsFullStack(Stack* pStack);
bool IsEmptyStack(Stack* pStack);
Stack* CreateStack(int size);
void DestroyStack(Stack* pStack);
void Push(Stack* pStack, Element item);
int Pop(Stack* pStack);
int Top(Stack* pStack);
int CountStackItem(Stack* pStack);
void ClearStack(Stack* pStack);
// header ends.

//Stack_Array.c로 잘라내기
/*
#include "Stack_Array.h"

//stack의 top이 size의 -1이면 true 반환
bool IsFullStack(Stack* pStack)
{
    if (pStack->top == (pStack->size) - 1)
    {
        //printf("Error : Stack Structure has been full ! \n");
        return true;
    }
    else
        return false;
}

//stack의 top이 0보다 작으면 true 반환
bool IsEmptyStack(Stack* pStack)
{
    if (pStack->top < 0)
    {
        //printf("Error : Stack is empty\n");
        return true;
    }
    else
        return false;
}

// 새로운 Stack을 생성하고 메모리를 할당. element의 크기는 size만큼. Stack의 포인터 주소를 반환.
Stack* CreateStack(int size) //array형 stack 생성, 반환형: Stack*
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack)); // Stack 구조체 포인터 선언 및 동적할당
    if (pStack == NULL) {
        printf("ERROR : Stack is NULL");
        return NULL;
    }
    pStack->stack = (int*)malloc(sizeof(Stack) * size); // 구조체포인터로 구조체 멤버 void 포인터에 접근 및 동적할당
    if (pStack->stack == NULL)
    {
        free(pStack);
        return NULL;
    }

    pStack->size = size;
    pStack->top = -1;

    return pStack;
}

//Stack에 할당된 메모리를 해제
void DestroyStack(Stack* pStack) {
    if (IsEmptyStack == false)
    {
        free(pStack->stack);
    }
    free(pStack);
}

//Stack의 top element에 item을 삽입.
void Push(Stack* pStack, Element item)
{
    //최대 사이즈의 -1과 top(현재 위치)가 같을 때, 종료
    if (IsFullStack(pStack))
    {
        return;
    }
    pStack->stack[++pStack->top] = item; // 실행될 때 마다 top이 1씩 증가
    //printf("current item : %d\n\n", item);
}

//Stack의 top element값을 반환하고 해당 element를 Stack에서 제거
Element Pop(Stack* pStack)
{
    int temp = 0;

    if (IsEmptyStack(pStack))
    {
        return temp;
    }

    temp = pStack->stack[pStack->top];
    pStack->stack[pStack->top] = (Element)NULL;
    --pStack->top;
    return temp;

}

//Stack의 top element값을 반환
Element Top(Stack* pStack)
{
    int temp = 0;

    if (IsEmptyStack(pStack))
    {
        return temp;
    }

    return pStack->stack[pStack->top];
}

//Stack에 저장된 item 수를 반환(top+1)
int CountStackItem(Stack* pStack)
{
    return pStack->top + 1;
}

//top으로 Stack에 저장된 element에 접근하면서 각 element에 NULL값을 대입하고 최종적으로 top을 -1이 되게 설정.
void ClearStack(Stack* pStack)
{
    while (pStack->top != -1)
    {
        pStack->stack[pStack->top] = (Element)NULL;
        --pStack->top;
    }
    printf("%d", pStack->top);

}

*/

#endif