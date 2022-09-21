//Queue_Array.h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef char* Element;

typedef struct {
    Element* queue;
    int size;
    int front, rear;
} Queue;

bool IsFullQueue(Queue* q)
{
    if ((q->rear + 1)%q->size==q->front) return true;
    else return false;
}

bool IsEmptyQueue(Queue* q) {
    if (q->front == q->rear) return true;
    else return false;
}

Queue* CreateQueue(int size)
{
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    if (pQueue == NULL) return NULL;

    pQueue->queue = (Element*)malloc(size * sizeof(Element));
    if (pQueue->queue == NULL) {
        free(pQueue);
        return NULL;
    }
    pQueue->size = size;
    pQueue->front = pQueue->rear = 0;
    
    return pQueue;
}

void Enqueue(Queue* q, Element item)
{
    if (IsFullQueue(q))
    {
        printf("Error : Queue is full.");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->queue[q->rear] = item;
    }
}

Element Dequeue(Queue* q)
{
    if (IsEmptyQueue(q))
    {
        printf("Error : Queue is empty.");
        return 0;
    }
    else {
        q->front = (q->front + 1) % q->size;
        return q->queue[q->front];
    }
}

Element QueueFront(Queue*q){
    return q->queue[q->front];
}

Element QueueRear(Queue* q) {
    return q->queue[q->rear];
}

void DestroyQueue(Queue* pQueue)
{
    free(pQueue->queue);
    free(pQueue);
}


