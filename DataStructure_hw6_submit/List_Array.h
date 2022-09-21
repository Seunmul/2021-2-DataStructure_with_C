//List_Array.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NORMAL 1
#define EXIT 0

typedef int Element;

typedef struct _List {
    
    Element* list;
    Element head;
    Element pos;
    int count;
    int size;

} List;

bool isFullList(List* pList)
{
    if (pList->count == (pList->size) - 1)
        return true;
    else
        return false;
}

bool isEmptyList(List* pList)
{
    if (pList->count == 0)
        return true;
    else
        return false;
}

List* createList(int size)
{
    List* pNewList = (List*)malloc(sizeof(List));
    if (pNewList == NULL)
        return NULL;

    pNewList->list = (Element*)malloc(size * sizeof(Element));
    if (pNewList->list == NULL)
    {
        free(pNewList);
        return NULL;
    }

    pNewList->size = size;
    pNewList->count = 0;
    pNewList->pos = 0;
    pNewList->head = 0;

    return pNewList;
}

bool _searchList(List* pList, int* pPreIndex, int* pLocIndex, Element data)
{
    *pPreIndex = 0, * pLocIndex = 0;
    if (isEmptyList(pList))
        return false;

    do {
        if (pList->list[(*pPreIndex)] == data)
        {
            return true;
        }
        else if (pList->list[(*pPreIndex)] > data)
        {
            //(*pPreIndex)++;
            break;
        }
        (*pPreIndex)++;
    } while (*pPreIndex < (pList->count));
    return false;
}

void _insertList(List* pList, int *pPreIndex, Element data)
{
    int preIndex = *pPreIndex;

    if (isEmptyList(pList))
    {
        (pList->list)[preIndex] = data;
    }
    else if (isFullList(pList))
        return;
    else
    {
        for (int i = pList->count; i >= preIndex ; i--)
        {
            (pList->list)[i + 1] = (pList->list)[i];
        }
        (pList->list)[preIndex] = data;
    }
    pList->count++;
}

void _deleteList(List* pList, int* pPreIndex, int* pPreLoc) {

    int preIndex = *pPreIndex;
    if (isEmptyList(pList))
        return;

    else
    {
        for (int i = preIndex; i <= pList->count; i++)
        {
            (pList->list)[i] = (pList->list)[i + 1];
        }
        (pList->list)[pList->count] = 0;
    }
    pList->count--;
}

void addArrayList(List* pList, Element data)
{
    if (isFullList(pList))
        return;

    int pPreIndex = 0, pLocIndex = 0;
    bool found = _searchList(pList, &pPreIndex, &pLocIndex, data);

    if (!found)
    {
        _insertList(pList, &pPreIndex, data);
    }
}

void removeList(List* pList, Element data)
{
    int pPreIndex = 0, pLocIndex = 0;
    bool found = _searchList(pList, &pPreIndex, &pLocIndex, data);

    if (found)
    {
        _deleteList(pList, &pPreIndex, &pLocIndex);
    }
}

void destroyList(List* pList)
{
    /*ListNode* pDel = NULL, * pNext = NULL;

    for (pDel = pList->head; pDel != NULL; pDel = pNext)
    {
        pNext = pDel->next;
        free(pDel);
    }*/
    free(pList->list);
    free(pList);
}

int countList(List* pList)
{
    return pList->count;
}

bool traverseList(List* pList, int fromWhere, Element* pDataOut)
{
    if (fromWhere < pList->count)
    {
        *pDataOut = pList->list[fromWhere]; 
        return true;
    }
     return false;
}


