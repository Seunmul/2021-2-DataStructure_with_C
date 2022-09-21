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
    //list* �޸� �Ҵ� ��, i+1�� �ε����� ��ȸ�ϹǷ� �߰����� �޸� Ȯ���� ���� size+1 malloc
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
    if (isEmptyList(pList)) // list�� ����ִٸ� return false
        return false;

    do { //preindex�� �޾Ƽ� �˻�
        if (pList->list[(*pPreIndex)] == data)
            return true; // ������ ��ȯ
        else if (pList->list[(*pPreIndex)] > data)
            break; //������������ �����Ͱ� �����Ƿ� ����Ʈ �� �����Ͱ� �Է� ������ ���� ũ�� break -> ���� �� �ε���

        (*pPreIndex)++;
    } while (*pPreIndex < (pList->count));
    return false; // ������ ��ã���� false ��ȯ
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
            (pList->list)[i + 1] = (pList->list)[i]; // index�� ��ġ�� ������ ����� ����  i+1�� �ε����� i�� �ε��� ���� ����
            //�̴� i�� index�� ��ġ�� ���� �� ����
        }
        (pList->list)[preIndex] = data; // i==index�� �� �� �ڸ��� data�� �Է�.
    }
    pList->count++;
}

void _deleteList(List* pList, int* pPreIndex) {

    int preIndex = *pPreIndex;
    if (isEmptyList(pList))
        return;
    else    {
        for (int i = preIndex; i <= pList->count; i++)  {
            (pList->list)[i] = (pList->list)[i + 1]; // _insert�� �ݴ�� ū �ε������� ���� �ε����� ����
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


