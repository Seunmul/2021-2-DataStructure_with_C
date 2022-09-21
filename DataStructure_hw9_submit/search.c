#define _CRT_SECURE_NO_WARNINGS
#define MAXDATA 300

#include "search_heap.h"

/*  MAXDATA 변경-> 각 배열의 크기 조정
    HASH 함수는 :  MAXDATA-((int)key%MAXDATA)-1;
    Collision 처리는 Linked List 방식.
    113줄의 주석을 제거하면 HASH함수 구조 알 수 있음.
    132줄의 주석을 제거하면 키의 입력에 따라 해당 위치에 데이터 유무를 확인가능.

    binarySearch는 heapSort를 사용해 정렬 157줄의 주석을 제거하면 내림차순으로 출력되는데 이는 끝에서부터 내림차순으로 출력하는데 실제로는 앞에서 부터 오름차순으로 정렬됨.
*/

int i = 0, j = 0, k = 0; /*iterative*/

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
    address = MAXDATA - ((int)key % MAXDATA) - 1;
    return address;
}

void destroyHash(HASH_HEAD* Hashed_Data[MAXDATA])
{
    HASH_NODE* temp = NULL;
    int end = MAXDATA;
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

Bool createHash(int data[MAXDATA], int size_Data, HASH_HEAD* Hashed_Data[MAXDATA])
{
    int cnt = 0;
    int end = MAXDATA;
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
    for (i = 0; i < size_Data; i++)
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
        //printf("\nkey -> %d : address -> %d : data -> %d [%d](이전 저장 데이터 : %d)", data[i], HASH(data[i]), data[i], Hashed_Data[ad]->count, !temp ? (int)NULL : temp->data);
    }
    return TRUE;
}

Bool hashedSearch(HASH_HEAD* Hashed_Data[MAXDATA], int find_Data)
{
    ADDRESS ad = HASH(find_Data);
    Bool found = FALSE;
    HASH_NODE* temp = NULL;
    printf("\n./ Hashed Search");

    temp = Hashed_Data[ad]->first;
    while (temp)
    {
        if (temp->data == find_Data)
            break;
        temp = temp->next;
    }
    //printf("\nkey -> %d : address -> %d : data -> %d", find_Data, HASH(find_Data), !temp ? (int)NULL : temp->data);

    if (!temp) {
        printf("\n%d is not found !\n", find_Data);
        return FALSE;
    }
    else {
        printf("\n%d is found !\n", find_Data);
        return TRUE;
    }
    return TRUE;
}

void heapSort(HEAP* pHeap, int list_Data[MAXDATA], int size_data)
{
    int index = 0;
    pHeap->size = pHeap->maxSize;
    for (i = 0; i < size_data; i++) {
        pHeap->heapAry[index] = list_Data[index]; //heapArray에 unsorted list 대입.   
        index++;
    }
    for (i = size_data; i > 0; i--) // 입력된 data의 사이즈의 크기+1만큼 반복 
    {
        BuildHeap(pHeap);
        list_Data[index - 1] = DeleteHeap(pHeap);
        //printf("%d ", list_Data[index - 1]);
        index--;
    }
}

Bool binarySearch(int list_Data[MAXDATA], int size_Data, int find_Data)
{
    int begin = 0;
    int mid = 0;
    int end = size_Data - 1;
    HEAP* heap;

    printf("\n./ Bianry Search");
    //heapSort
    heap = createHeap(size_Data);
    heapSort(heap, list_Data, size_Data);
    destroyHeap(heap);
    //heapSort End

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (find_Data > list_Data[mid])
            begin = mid + 1; // look in upper half
        else if (find_Data < list_Data[mid])
            end = mid - 1; // look in lower half
        else
            begin = end + 1; // found: force exit
    } // end while   

    if (find_Data == list_Data[mid])
        printf("\n%d is found !\n", find_Data);
    else
        printf("\n%d is not found !\n", find_Data);

    return TRUE;
}

int main()
{
    char Fn[30] = { 0, }; // file name
    char* buffer;
    char* tok;
    int buffer_size = 0;
    int size_Data = 0, find_Data = 0, choose_method = 0;
    int integer_DataList[MAXDATA] = { 0, };
    HASH_HEAD* integer_Hashed_DataList[MAXDATA] = { 0, };

    FILE* fp;

    printf("\nInput file name :  ");
    if (!scanf(" %s", Fn))
        return 0;
    fp = fopen(Fn, "r");
    if (fp == NULL) {
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

    i = 0;
    tok = strtok(buffer, " \n");
    integer_DataList[i] = atoi(tok);
    // printf("%d ", integer_DataList[i]);
    while (tok != NULL)
    {
        tok = strtok(NULL, " \n");
        if (tok == NULL)
            break;
        integer_DataList[++i] = atoi(tok);
        //printf("%d ", integer_DataList[i]);
    }
    size_Data = i + 1;

    printf("\n\n - Target integer : ");
    if (!scanf(" %d", &find_Data))
        return 0;
    //printf("%d", find_data);

    printf("\n\n - Choose a searching method (Binary : 1, Hash : 2) : ");
    if (!scanf(" %d", &choose_method))
        return 0;
    //printf("%d", choose_method);
    free(buffer);

    switch (choose_method)
    {
    case 1:
        binarySearch(integer_DataList, size_Data, find_Data);
        break;
    case 2:
        createHash(integer_DataList, size_Data, integer_Hashed_DataList);
        hashedSearch(integer_Hashed_DataList, find_Data);
        destroyHash(integer_Hashed_DataList);
        break;

    default:
        printf("\n\nwrong menu number selelcted.\n\n");
        break;
    }

    return 0;
}