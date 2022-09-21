//Stack_List.h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//header
typedef char* Element;

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

//.Stack_List.c
//size is not used in linked list implementation
bool IsFullStack(Stack* pStack)
{
    return false;
}

//현재 스택의 count를 참조해서, 0미만일경우 true반환.
bool IsEmptyStack(Stack* pStack)
{
    if (pStack->count <= 0)
        return true;
    else
        return false;
}

//list형 stack 생성, 반환형: Stack* //size is not used in linked list implementation
Stack* CreateStack(int size)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack)); // Stack 구조체 포인터 선언 및 동적할당
    if (pStack == NULL) {
        printf("ERROR : Stack is NULL");
        return NULL;
    }
    pStack->count = 0;
    pStack->top = NULL;

    return pStack;
}

//Stack에 할당된 메모리를 해제
//Stack이 빌 때까지 이전 스택노드의 값과 메모리를 해제한 후, count가 0이 되면 루프를 빠져나와 pStack의 메모리를 해제.
void DestroyStack(Stack* pStack)
{
    while (!IsEmptyStack(pStack))
    {
        pStack->top->data = 0;
        StackNode* pOldTop = pStack->top;
        pStack->top = pStack->top->next;
        free(pOldTop);
        pStack->count--;
        // printf("destroy %d\n", pStack->count);
    }
    //printf("destroy %d\n", pStack->count);
    free(pStack);

}

//현재 Stack에 상위 스택노드를 추가하고 상위 스택노드와 현재 스택(top)의 next멤버에 주소를 연결(하위 스택노드에 연결)
//현재 스택의 top에 상위 스택노드를 주소를 연결 
void Push(Stack* pStack, Element item)
{
    StackNode* pNewNode = (StackNode*)malloc(sizeof(StackNode));
    if (pNewNode == NULL)
        return;
    pNewNode->data = item;
    pNewNode->next = pStack->top;
    pStack->top = pNewNode;
    pStack->count++;
}

//현재 스택의 empty상태를 확인 후, item이 존재하면 상위 item을 반환
//반환 후 해당 스택 노드는 메모리 해제
Element Pop(Stack* pStack)
{
    if (IsEmptyStack(pStack))
        return 0;
    else
    {
        Element item = pStack->top->data;
        StackNode* pOldTop = pStack->top;
        pStack->top = pStack->top->next;
        free(pOldTop);
        pStack->count--;
        return item;
    }
}

//현재 스택의 탑 노드의 데이터를 반환.
Element Top(Stack* pStack)
{
    if (IsEmptyStack(pStack))
        return 0;
    else
    {
        return pStack->top->data;
    }
}

//현재 스택의 사이즈를 반환.
int CountStackItem(Stack* pStack)
{
    return pStack->count;
}

//최상위 스택 노드부터 한 단계롤 내려오면서 값을 제거하고 메모리할당 해제
//count가 0일때 종료.
void ClearStack(Stack* pStack)
{
    while (!IsEmptyStack(pStack))
    {
        pStack->top->data = 0;
        StackNode* pOldTop = pStack->top;
        pStack->top = pStack->top->next;
        free(pOldTop);
        pStack->count--;
        // printf("destroy %d\n", pStack->count);
    }
    printf("destroy %d\n", pStack->count);
    return;
}


