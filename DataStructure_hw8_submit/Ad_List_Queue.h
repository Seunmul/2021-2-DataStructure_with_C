#pragma once
//Ad_List_Queue.h

typedef void* Queue_Element;

typedef struct tQueueNode {
    Queue_Element data;
    struct tQueueNode* next;
}QueueNode;

typedef struct {
    int count;
    QueueNode* front, * rear;
} QUEUE;

bool IsFullQueue(QUEUE* q)
{
    return false;
}

bool IsEmptyQueue(QUEUE* pQueue) {
    if (pQueue->count == 0) return true;
    else return false;
}

QUEUE* CreateQueue(int size)
{
    QUEUE* pNewQueue = (QUEUE*)malloc(sizeof(QUEUE));
    if (pNewQueue == NULL) return NULL;

    pNewQueue->count = 0;
    pNewQueue->front = pNewQueue->rear = NULL;
    return pNewQueue;
}

bool Enqueue(QUEUE* pQueue, Queue_Element item)
{
    QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (pNewNode == NULL)
        return false;
    pNewNode->data = item;
    pNewNode->next = NULL;

    if (pQueue->count <= 0)
    {
        pQueue->front = pQueue->rear = pNewNode;
    }
    else {
        pQueue->rear->next = pNewNode;
        pQueue->rear = pNewNode;
    }

    pQueue->count++;
    return true;
}

Queue_Element Dequeue(QUEUE* pQueue)
{
    QueueNode* pFront = NULL;
    Queue_Element item = 0;

    if (pQueue->count <= 0)
        return 0;
    pFront = pQueue->front;
    item = pFront->data;

    if (pQueue->count == 1)
    {
        pQueue->front = pQueue->rear = NULL;
    }
    else {
        pQueue->front = pFront->next;
    }
    free(pFront);
    pQueue->count--;

    return item;
}

void DestroyQueue(QUEUE* pQueue)
{
    QueueNode* pCur = NULL, * pNext = NULL;

    for (pCur = pQueue->front; pCur != NULL; pCur = pNext)
    {
        pNext = pCur->next;
        free(pCur);
    }

    pQueue->count = 0;
    pQueue->front = pQueue->rear = NULL;

    free(pQueue);
}

