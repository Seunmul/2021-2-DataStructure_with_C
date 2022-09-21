#pragma once
//Stack_List.h

#ifndef Stack_List_H
#define Stack_List_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//header
typedef int Element;

typedef struct tStackNode {
    Element data;
    struct tStackNode* next;
} StackNode;

typedef struct {
    int count;
    StackNode* top;
}Stack;

bool IsFullStack(Stack* pStack);
bool IsEmptyStack(Stack* pStack);
Stack* CreateStack(int size);
void DestroyStack(Stack* pStack);
void Push(Stack* pStack, Element item);
Element Pop(Stack* pStack);
Element Top(Stack* pStack);
int CountStackItem(Stack* pStack);
void ClearStack(Stack* pStack);
//header ends.


#endif
