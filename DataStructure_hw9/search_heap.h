#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef int Element;
typedef int Bool;

typedef struct _HEAP {
    Element* heapAry;
    int maxSize;
    int size;
}HEAP;

HEAP* createHeap(int maxSize){
    HEAP* newHeap = (HEAP*)malloc(sizeof(HEAP));
    if (!newHeap)
        return NULL;
    
    newHeap->maxSize=(int)pow(2,ceil(log2(maxSize)))-1;
    newHeap->size = 0;
    newHeap->heapAry = (Element*)calloc(newHeap->maxSize,sizeof(Element));
    
    return newHeap;
}

Bool ReheapUp(HEAP* pHeap, int index)
{
    int parentIndex = 0;

    if (index <= 0 || index >= pHeap->size)
        return FALSE; // HEAP is FULL or index is size_overed

    parentIndex = (index - 1) / 2;
    if (pHeap->heapAry[index] > pHeap->heapAry[parentIndex])
    {
        Element temp = pHeap->heapAry[index];
        pHeap->heapAry[index] = pHeap->heapAry[parentIndex];
        pHeap->heapAry[parentIndex] = temp;
        ReheapUp(pHeap, parentIndex);
    }
    return TRUE;
}

Bool InsertHeap(HEAP* pHeap, Element data)
{
    Bool chk = FALSE;
    if (pHeap->size >= pHeap->maxSize)
    {
        printf("\nHeap is full!\n");
        return FALSE;
    }
    pHeap->heapAry[pHeap->size++] = data;
    
    chk=ReheapUp(pHeap, pHeap->size - 1);
    return chk;
}

Bool ReHeapDown(HEAP* pHeap, int index)
{
    Element curData = 0;
    if (index < 0 || index >= pHeap->size)
        return FALSE; // HEAP is FULL or index is size_overed

    if (index * 2 + 1 < pHeap->size) {
        int maxChild = index * 2 + 1;
        if (maxChild + 1 < pHeap->size && pHeap->heapAry[maxChild + 1] > pHeap->heapAry[maxChild])
            maxChild++; // 오른쪽 child가 존재하고 왼쪽 child보다 클 때 maxChild++

        if (pHeap->heapAry[maxChild] > pHeap->heapAry[index]) {
            Element temp = pHeap->heapAry[index];
            pHeap->heapAry[index] = pHeap->heapAry[maxChild];
            pHeap->heapAry[maxChild] = temp;
            ReHeapDown(pHeap, maxChild);
        }
    }
    return TRUE;
}

Element DeleteHeap(HEAP* pHeap)
{
    Element DataOut;
    if (pHeap->size <=0)
    {
        printf("\nHeap is empty!\n");
        return FALSE;
    }
    DataOut = pHeap->heapAry[0];
    pHeap->heapAry[0] = pHeap->heapAry[--pHeap->size];
    ReHeapDown(pHeap, 0);

    return DataOut;
}

void BuildHeap(HEAP* pHeap) 
{
    int i = 0;
    for (i = 1; i < pHeap->size; i++)
        ReheapUp(pHeap, i);
}

Bool destroyHeap(HEAP* pHeap)
{
    if (!pHeap)
        return FALSE; 
    else
    {
        pHeap->maxSize = 0;
        pHeap->size = 0;
        free(pHeap->heapAry);
    }
    return TRUE;
}