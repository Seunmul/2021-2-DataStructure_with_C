#pragma once
//List_Link.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

typedef enum{false, true}bool;
typedef int Element;

//Data node
typedef struct tListNode {
    Element data;
    struct tListNode* next;
} ListNode;

//Head node
typedef struct {
    int            count;
    ListNode* head;
    ListNode* pos; // traverse를 위한 변수
}List;

List* createList()
{
    List* pNewList = (List*)malloc(sizeof(List));
    if (pNewList == NULL)        
        return NULL;

    pNewList->count = 0;
    pNewList->head = NULL;

    return pNewList;
}

void _insertList(List* pList, ListNode* pPre, Element data)
{
    ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
    if (pNewNode != NULL) 
        pNewNode->data = data;
    else return;

    if (pPre == NULL) {
        pNewNode->next = pList->head;
        pList->head = pNewNode;
    }    else    {
        pNewNode->next = pPre->next;
        pPre->next = pNewNode;
    }
    pList->count++;
}

bool _searchList(List* pList, ListNode** ppPre, ListNode** ppLoc, Element data)
{
    for (*ppPre = NULL, *ppLoc = pList->head; *ppLoc != NULL; *ppPre = *ppLoc, *ppLoc = (*ppLoc)->next)
    {
        if ((*ppLoc)->data == data)  // data found then, return          
            return true;
        else if ((*ppLoc)->data > data)            
            break;
    }
    return false;
}

void _deleteList(List* pList, ListNode* pPre, ListNode* pLoc)
{
    if (pPre == NULL)
        pList->head = pLoc->next;
    else
        pPre->next = pLoc->next;

    free(pLoc); // free allocated memory of pLoc
    pList->count--;
}


void addNodeList(List* pList, Element data)
{
    ListNode* pPre = NULL, * pLoc = NULL; 
    bool found = _searchList(pList, &pPre, &pLoc, data); // 이전 노드와 데이터가 들어갈 노드의 위치를 반환

    if (!found) { //found => false일 경우
        _insertList(pList, pPre, data);
        printf("\n%d insert.\n",data);
    }   else
        printf("\nList already has %d\n", data);
    return;
}

void removeList(List* pList, Element data)
{
    ListNode* pPre = NULL, * pLoc = NULL;
    bool found = _searchList(pList, &pPre, &pLoc, data);

    if (found) { //found => true일 경우
        _deleteList(pList, pPre, pLoc);
        printf("\n%d delete.\n", data);
    }   else  {
        printf("\n%d not exists in List.\n", data);
    }
}

//하나의 데이터셋 만 반환
bool traverseList(List* pList, int fromWhere, Element* pDataOut)
{
    if (fromWhere == 0 || pList->pos == NULL)
        pList->pos = pList->head;
    else
        pList->pos = pList->pos->next;

    if (pList->pos != NULL) {
        *pDataOut = pList->pos->data;
          return true;
    }   else   {
        *pDataOut = 0;
        return false;
    }
    return false;
} 

void destroyList(List* pList)
{
    ListNode* pDel = NULL, * pNext = NULL;
    
    for (pDel = pList->head; pDel != NULL; pDel = pNext)
    {
        pNext = pDel->next;
        free(pDel);
    }
    free(pList);
}

int countList(List* pList)
{
    return pList->count;
}

bool isFullList(List* pList)
{
    return false; //Linked List cannot be full
}

bool isEmptyList(List* pList)
{
    if (pList->count == 0)
        return true;
    else
        return false;
}
