//main
#define _CRT_SECURE_NO_WARNINGS
#include "Queue_Array.h"

void CurrentQueue(Queue* q, int index)
{
    printf("The current status of Queue :(");
    for (int j = 0; j < index; j++)
    {
        printf("%s%d", q->queue[(q->rear) - index + 1 + j], j + 1);
        if (j + 1 ==index) continue;
        printf(",");
    }
    printf(")\n\n\n");
}

int main()
{
    
    int size = 3,sel=0,index=0,chk=0, count=1, inputcnt=0;
    char **input = (char**)malloc(sizeof(char*)*size);
    Queue* pQueue;
    pQueue = CreateQueue(size);
    while (count)
    {
        printf("In(0), out(1), exit(2) : ");
        if (scanf("%d", &sel) != 1) { printf("check your input\n"); chk=getchar(); continue; }
        chk=getchar();
        switch (sel)
        {
        case 0:
            if (IsFullQueue(pQueue))
            {
                printf("Queue is Full!\n"); continue;
            }
            input[index] = (char*)malloc(sizeof(char) * 30); inputcnt++;
            printf("Customer : ");
            if (scanf("%[^\n]s", input[index]) != 1) { printf("check your input\n"); chk = getchar(); continue; }
            chk = getchar();
            Enqueue(pQueue, input[index++]);
            CurrentQueue(pQueue, index);

            break;
        case 1:
            if (IsEmptyQueue(pQueue))
            {
                printf("Queue is empty!\n");
            }
            else
            {
                printf("Customer dequeued : %s\n", Dequeue(pQueue));
                index--;
            }
            
            CurrentQueue(pQueue, index);
        break;

        case 2:
            count = 0;
            break;
        
        default:
            count = 0;
            break;

        }
    }
    for (int i = 0; i < inputcnt; i++)
    {
        free(input[i]);
    }
    free(input);
    DestroyQueue(pQueue);
   
    return 0;
}

/*
void CurrentQueue(Queue* q, int index)
{
    printf("The current status of Queue :(");
    QueueNode* ptr = q->front;
    for (int j = 0; j < index; j++)
    {
        printf("%s%d", ptr->data,j+1);
        if (j + 1 ==index) continue;
        ptr = ptr->next;
        printf(",");
    }
    printf(")\n\n\n");
}

int main()
{

    int size = 3,sel=0,i=0,chk=0;
    char **input = (char**)malloc(sizeof(char*)*size);
    Queue* pQueue;
    pQueue = CreateQueue(size);
    while (1)
    {
        printf("In(0), out(1), exit(2) : ");
        if (scanf("%d", &sel) != 1) { printf("check your input\n"); chk=getchar(); continue; }
        chk=getchar();
        switch (sel)
        {
        case 0:
            if (IsFullQueue(pQueue))
            {
                printf("Queue is Full!\n"); continue;
            }
            input[i] = (char*)malloc(sizeof(char) * 30);
            printf("Customer : ");
            if (scanf("%[^\n]s", input[i]) != 1) { printf("check your input\n"); chk = getchar(); continue; }
            chk = getchar();
            Enqueue(pQueue, input[i++]);
            CurrentQueue(pQueue, i);

            break;
        case 1:
            if (IsEmptyQueue(pQueue))
            {
                printf("Queue is empty!\n");
            }
            else
            {
                printf("Customer dequeued : %s\n", Dequeue(pQueue));
                i--;
            }

            CurrentQueue(pQueue, i);
        break;

        case 2:
            return 0;
            break;

        default:
            break;

        }
    }
    DestroyQueue(pQueue);
    for (int i = 0; i < size; i++)
    {
        free(input[i]);
    }
    free(input);
    return 0;
}*/