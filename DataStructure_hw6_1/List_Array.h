//List_Array.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Element;

typedef struct _List {
    Element* list; // data array
    int count;
    int size;
} List;

bool isFullList(List* pList)
{
    if (pList->count == (pList->size))
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

    pNewList->list = (Element*)malloc((size+1) * sizeof(Element)); 
    //list* 메모리 할당 시, i+1의 인덱스를 조회하므로 추가적인 메모리 확보를 위해 size+1 malloc
    if (pNewList->list == NULL)    {
        free(pNewList);
        return NULL;
    }

    pNewList->size = size;
    pNewList->count = 0;
    
    return pNewList;
}

bool _searchList(List* pList, int* pPreIndex, Element data)
{
    *pPreIndex = 0;
    if (isEmptyList(pList)) // list가 비어있다면 return false
        return false;

    do { //preindex를 받아서 검색
        if (pList->list[(*pPreIndex)] == data)
            return true; // 같으면 반환
        else if (pList->list[(*pPreIndex)] > data)
            break; //오름차순으로 데이터가 들어오므로 리스트 내 데이터가 입력 데이터 보다 크면 break -> 제일 앞 인덱스

        (*pPreIndex)++;
    } while (*pPreIndex < (pList->count));
    return false; // 끝까지 못찾으면 false 반환
}

void _insertList(List* pList, int* pPreIndex, Element data)
{
    int preIndex = *pPreIndex;

    if (isEmptyList(pList)) {
        (pList->list)[preIndex] = data;
    }    
    else if (isFullList(pList))
        return;
    else {
        for (int i = pList->count; i >= preIndex ; i--) {
            (pList->list)[i + 1] = (pList->list)[i]; // index의 위치에 공간을 만들기 위해  i+1의 인덱스에 i의 인덱스 값을 대입
            //이는 i와 index의 위치가 같을 때 종료
        }
        (pList->list)[preIndex] = data; // i==index일 때 그 자리에 data를 입력.
    }
    pList->count++;
}

void _deleteList(List* pList, int* pPreIndex) {

    int preIndex = *pPreIndex;
    if (isEmptyList(pList))
        return;
    else    {
        for (int i = preIndex; i <= pList->count; i++)  {
            (pList->list)[i] = (pList->list)[i + 1]; // _insert와 반대로 큰 인덱스에서 작은 인덱스로 진행
        }
        (pList->list)[pList->count] = 0;
    }
    pList->count--;
}

void addArrayList(List* pList, Element data)
{
    int pPreIndex = 0;
    bool found;
    
    if (isFullList(pList))
        return;
    found = _searchList(pList, &pPreIndex, data);

    if (!found)
        _insertList(pList, &pPreIndex, data);
    return;
}

void removeList(List* pList, Element data)
{
    int pPreIndex = 0;
    bool found;

    if (isEmptyList(pList))
        return;
    found = _searchList(pList, &pPreIndex, data);

    if (found)    {
        _deleteList(pList, &pPreIndex);
        printf("%d was removed\n", data);
    }
    else
        printf("failed to remove %d : not exists\n", data);
    return;
}

void destroyList(List* pList)
{
    if (pList->list[0]);
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


