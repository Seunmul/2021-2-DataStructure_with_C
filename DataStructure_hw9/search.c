#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include "search_heap.h"

/*
    HASH 함수는 :  MAXDATA-((int)key%MAXDATA)-1;
    Collision 대비는 Linked List 방식.
*/

int j = 0, k = 0; /*iterative*/

typedef int ADDRESS;
typedef int DATA;

typedef struct _NODE
{
    int data;
    struct _NODE* next;
}HASH_NODE;

typedef struct _HEAD
{
    int count;
    HASH_NODE* first;
}HASH_HEAD;

ADDRESS HASH(int key)
{
    ADDRESS address = 0;
    address = MAX - ((int)key % MAX) - 1;
    return address;
}

void destroyHash(HASH_HEAD* Hashed_Data[])
{
    int  i = 0;
    int end = MAX;
    HASH_NODE* temp = NULL;
    
    if (Hashed_Data == NULL)
        return;

    for (i = 0; i < end; i++)
    {
        if (!Hashed_Data[i])
            continue;
        if (Hashed_Data[i]->count == 0) {
            free(Hashed_Data[i]);
            continue;
        }
        if (Hashed_Data[i]->count > 0) {
            temp = Hashed_Data[i]->first;
            while (temp) {
                Hashed_Data[i]->first = temp->next;
                free(temp);
                temp = Hashed_Data[i]->first;
            }
            free(Hashed_Data[i]);
        }
    }
    return;
}

Bool createHash(int data[MAX], int size, HASH_HEAD* Hashed_Data[MAX])
{
    int i = 0, cnt = 0;
    int end = MAX;

    if (data == NULL)
        return FALSE;
    //HASH_HEAD 공간 할당
    for (i = 0; i < end; i++)
    {
        cnt++;
        HASH_HEAD* newHead = (HASH_HEAD*)malloc(sizeof(HASH_HEAD));
        if (!newHead) {
            free(newHead);
            for (i = 0; i < cnt - 1; i++)
                free(Hashed_Data[i]);
            return FALSE;
        }
        newHead->first = NULL;
        newHead->count = 0;
        Hashed_Data[i] = newHead;
    }

    cnt = 0;
    for (i = 0; i < size; i++)
    {
        ADDRESS ad = HASH(data[i]);
        HASH_NODE* temp = NULL;
        HASH_NODE* newNode = (HASH_NODE*)malloc(sizeof(HASH_NODE));
        if (!newNode) {
            free(newNode);
            destroyHash(Hashed_Data);
            return FALSE;
        }
        newNode->data = data[i];

        if (Hashed_Data[ad]->count == 0) { // 중복된 데이터 없을 시.
            newNode->next = NULL;
            Hashed_Data[ad]->first = newNode;
            Hashed_Data[ad]->count++;
        }
        else {
            temp = Hashed_Data[ad]->first;
            Hashed_Data[ad]->first = newNode;
            newNode->next = temp;
            Hashed_Data[ad]->count++;
        }
        /*
        printf("\nkey -> %d : address -> %d : data -> %d [%d](이전 저장 데이터 : %d)", 
            data[i], HASH(data[i]), data[i], Hashed_Data[ad]->count, !temp ? (int)NULL : temp->data);
            */
    }
    return TRUE;
}

Bool hashedSearch(HASH_HEAD* Hashed_Data[MAX], int find)
{
    ADDRESS ad = HASH(find);
    Bool found = FALSE;
    HASH_NODE* temp = NULL;
    printf("\n./ Hashed Search");

    temp = Hashed_Data[ad]->first;
    while (temp)
    {
        if (temp->data == find)
            break;
        temp = temp->next;
    }
    printf("\nkey -> %d : address -> %d : data -> %d", find, HASH(find), !temp ? (int)NULL : temp->data);

    if (!temp) {
        printf("\n%d is not found !\n", find);
        return FALSE;
    }
    else {
        printf("\n%d is found !\n", find);
        return TRUE;
    }
    return TRUE;
}

void heapSort(HEAP* pHeap, int dataList[], int size)
{
    int i=0, index = 0;
    pHeap->size = pHeap->maxSize;
    for (i = 0; i < size; i++) {
        pHeap->heapAry[index] = dataList[index]; //heapArray에 unsorted list 대입.   
        index++;
    }
    printf("\n\n");
    BuildHeap(pHeap);
    for (i = size; i > 0; i--) // 입력된 data의 사이즈의 크기+1만큼 반복 
    {
       // BuildHeap(pHeap);
        dataList[index - 1] = DeleteHeap(pHeap);
        printf("%d ", dataList[index - 1]);
        index--;
    }
}

Bool binarySearch(int dataList[], int size, int find)
{
    int begin = 0;
    int mid = 0;
    int end = size - 1;
    HEAP* heap;

    printf("\n./ Bianry Search");
    //heapSort
    heap = createHeap(size);
    heapSort(heap, dataList, size);
    destroyHeap(heap);
    //heapSort End

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (find > dataList[mid])
            begin = mid + 1; // look in upper half
        else if (find < dataList[mid])
            end = mid - 1; // look in lower half
        else
            begin = end + 1; // found: force exit
    } // end while   

    if (find == dataList[mid])
        printf("\n%d is found !\n", find);
    else
        printf("\n%d is not found !\n", find);

    return TRUE;
}

int main()
{
    int  i = 0;
    char Fn[30] = { 0, }; // file name
    char* buffer;
    char* tok;
    int buffer_size = 0;
    int size = 0, find = 0, choose = 0;
    int dataList[MAX] = { 0, };

    HASH_HEAD* Hashed_DataList[MAX] = { 0, };
    FILE* fp;

    printf("\nInput file name :  ");
    if (!scanf(" %s", Fn))
        return 0;
    ;
    if (!(fp = fopen(Fn, "r")))
    {
        printf("\nWrong File name.\n\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    buffer_size = ftell(fp);
    buffer = (char*)malloc(buffer_size + 1);
    if (buffer == NULL)
        return 0;
    memset(buffer, 0, buffer_size + 1);
    rewind(fp);
    fread(buffer, buffer_size + 1, 1, fp);
    fclose(fp);
    fp = NULL;

    i = 0;
    tok = strtok(buffer, " \n");
    dataList[i] = atoi(tok);
    //printf("%d ", dataList[i]);
    while (tok != NULL)
    {
        tok = strtok(NULL, " \n");
        if (tok == NULL)
            break;
        dataList[++i] = atoi(tok);
        //printf("%d ", dataList[i]);
    }
    size = i + 1; // size of input datalist

    printf("\n\n - Target integer : ");
    if (!scanf(" %d", &find))
        return 0;
    //printf("%d", find);

    printf("\n\n - Choose a searching method (Binary : 1, Hash : 2) : ");
    if (!scanf(" %d", &choose))
        return 0;
    //printf("%d", choose_method);
    free(buffer);
    buffer = NULL;

    switch (choose)
    {
    case 1:
        binarySearch(dataList, size, find);
        break;
    case 2:
        createHash(dataList, size, Hashed_DataList);
        hashedSearch(Hashed_DataList, find);
        destroyHash(Hashed_DataList);
        break;
    default:
        printf("\n\nwrong menu number selelcted.\n\n");
        break;
    }

    return 0;
}