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

//Stack_Array.c�� �߶󳻱�
/*
#include "Stack_Array.h"

//stack�� top�� size�� -1�̸� true ��ȯ
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

//stack�� top�� 0���� ������ true ��ȯ
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

// ���ο� Stack�� �����ϰ� �޸𸮸� �Ҵ�. element�� ũ��� size��ŭ. Stack�� ������ �ּҸ� ��ȯ.
Stack* CreateStack(int size) //array�� stack ����, ��ȯ��: Stack*
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack)); // Stack ����ü ������ ���� �� �����Ҵ�
    if (pStack == NULL) {
        printf("ERROR : Stack is NULL");
        return NULL;
    }
    pStack->stack = (int*)malloc(sizeof(Stack) * size); // ����ü�����ͷ� ����ü ��� void �����Ϳ� ���� �� �����Ҵ�
    if (pStack->stack == NULL)
    {
        free(pStack);
        return NULL;
    }

    pStack->size = size;
    pStack->top = -1;

    return pStack;
}

//Stack�� �Ҵ�� �޸𸮸� ����
void DestroyStack(Stack* pStack) {
    if (IsEmptyStack == false)
    {
        free(pStack->stack);
    }
    free(pStack);
}

//Stack�� top element�� item�� ����.
void Push(Stack* pStack, Element item)
{
    //�ִ� �������� -1�� top(���� ��ġ)�� ���� ��, ����
    if (IsFullStack(pStack))
    {
        return;
    }
    pStack->stack[++pStack->top] = item; // ����� �� ���� top�� 1�� ����
    //printf("current item : %d\n\n", item);
}

//Stack�� top element���� ��ȯ�ϰ� �ش� element�� Stack���� ����
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

//Stack�� top element���� ��ȯ
Element Top(Stack* pStack)
{
    int temp = 0;

    if (IsEmptyStack(pStack))
    {
        return temp;
    }

    return pStack->stack[pStack->top];
}

//Stack�� ����� item ���� ��ȯ(top+1)
int CountStackItem(Stack* pStack)
{
    return pStack->top + 1;
}

//top���� Stack�� ����� element�� �����ϸ鼭 �� element�� NULL���� �����ϰ� ���������� top�� -1�� �ǰ� ����.
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