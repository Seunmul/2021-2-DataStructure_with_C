#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 1000

typedef enum { true=0, false } Bool;
 
void printList(int dataList[])
{
    static int size = 0;
    static int chk = 0;
    if (!chk) {
        while (dataList[size++] != 0);    size--;  chk++;//데이터 리스트의 크기 측정. =>어차피 n번 반복하는거,,
        return;
    }
    printf("\n\n - List : ");
    for (int i = 0; i < size; i++)
        printf("%d ",dataList[i]);
    printf("\n --\n\n");
    return;
}

//오름차순
Bool Selection(int dataList[], int size)
{
    int n = size;
    int smallest = 0;
    int temp = 0;
    printf("\n./ Selection Sort");
    for (int i = 0; i < n - 1; i++) // 0) i->current index
    {
        smallest = i; // 1) current value == smallest
        for (int j = i + 1; j < n; j++)
            if (dataList[j] < dataList[smallest])
                smallest = j; //2) find smaller value -> update value
        // Smallest selected: exchange with current
        temp = dataList[i];
        dataList[i] = dataList[smallest];
        dataList[smallest] = temp;
       //printList(dataList);
    }   
    return TRUE;
}

//내림차순
Bool Selection2(int dataList[], int size)
{
    int n = size;
    int smallest = 0;
    int temp = 0;
    printf("\n./ Selection Sort");
    for (int i = 0; i < n - 1; i++) // 0) i->current index
    {
        smallest = i; // 1) current value == smallest
        for (int j = i + 1; j < n; j++)
            if (dataList[j] > dataList[smallest])
                smallest = j; //2) find smaller value -> update value
        // Smallest selected: exchange with current
        temp = dataList[i];
        dataList[i] = dataList[smallest];
        dataList[smallest] = temp;
        //printList(dataList);
    }
    return TRUE;
}


//오름차순
Bool Insertion(int dataList[], int size)
{
    int i, j = 0;
    int n = size;
    int hold = 0;
    printf("\n./ Insertion Sort");
    for ( i = 1; i < n; i++) 
    {
        hold = dataList[i];
        for (j = i; j > 0 && hold < dataList[j - 1]; j--) // hold를 기준으로 앞의 값들을 교체.
            dataList[j] = dataList[j-1];
       dataList[j] = hold;
       //printList(dataList);
    }
    return TRUE;
}

//내림차순
Bool Insertion2(int dataList[], int size)
{
    int i, j = 0;
    int n = size;
    int hold = 0;
    printf("\n./ Insertion Sort2");
    for (i = 1; i < n; i++)
    {
        hold = dataList[i];
        for (j = i; j > 0 && hold > dataList[j - 1]; j--) // hold를 기준으로 앞의 값들을 교체.
            dataList[j] = dataList[j - 1];
        dataList[j] = hold;
        //printList(dataList);
    }
    return TRUE;
}


//오름차순
Bool Bubble(int dataList[], int size)
{
    printf("\n./ Bubble Sort");
    
    int i,j = 0;
    int n = size;
    int temp = 0;
    int sorted = FALSE;
        
    for (i = 0; i < n && !sorted; i++)
    {
        for (j = n - 1, sorted = TRUE; j > i; j--)
        {
            if (dataList[j] < dataList[j - 1])
            {
                sorted = FALSE;
                temp = dataList[j];
                dataList[j] = dataList[j - 1];
                dataList[j - 1] = temp;
            }
        }
       // printList(dataList);
    }
    return TRUE;
}

//mycode : 내림차순
Bool Bubble2(int dataList[], int size)
{
    printf("\n./ Bubble Sort2");

    int i, j = 0;
    int n = size;
    int temp = 0;
    int sorted = FALSE;

    for (i = 0; i < n && !sorted; i++)
    {
        for (j = 1, sorted = TRUE; j < n-i; j++) //뒤에서부터 인덱스 확정
        {
            if (dataList[j] < dataList[j - 1]) // 현재 것 보다 앞에 것이 크면 교체 - > 오름차순 
            {
                sorted = FALSE;
                temp = dataList[j];
                dataList[j] = dataList[j - 1];
                dataList[j - 1] = temp;
            }
        }
       //printList(dataList);
    }
    return TRUE;
}


//오름차순
void _quickSort(int dataList[], int left, int right)
{
    int pivot = 0, i = 0, j = 0;
    int temp = 0;
    
    if (left < right) {
        i = left; j = right + 1;
        pivot = dataList[left];
        do 
        {
            do
                i++;
            while (dataList[i] != 0 && dataList[i] < pivot );
            
            do
                j--;
            while (dataList[j] > pivot);

            if (i < j)
            {
                temp = dataList[i];
                dataList[i] = dataList[j];
                dataList[j] = temp;
            }
            //printList(dataList);
        } while (i < j);
        
         temp = dataList[left];
         dataList[left] = dataList[j];
         dataList[j] = temp;
         //printList(dataList);
        
        _quickSort(dataList, left, j - 1);    
        _quickSort(dataList, j + 1, right);
    }
    return;
}

//내림차순
void _quickSort2(int dataList[], int left, int right)
{
    int pivot = 0, i = 0, j = 0;
    int temp = 0;

    if (left < right) {
        i = left; j = right + 1;
        pivot = dataList[left];
        do
        {
            do
                i++;
            while (dataList[i] != 0 && dataList[i] > pivot);

            do
                j--;
            while (dataList[j] < pivot);

            if (i < j)
            {
                temp = dataList[i];
                dataList[i] = dataList[j];
                dataList[j] = temp;
            }
            //printList(dataList);
        } while (i < j);
        if(left!=j)
        {
            temp = dataList[left];
            dataList[left] = dataList[j];
            dataList[j] = temp;
            //printList(dataList);
        }  
        _quickSort2(dataList, left, j - 1);
        _quickSort2(dataList, j + 1, right);
    }
    return;
}

Bool Quick(int dataList[], int size)
{
    int left = 0;
    int right = size - 1;
    printf("\n./ Quick Sort");
    _quickSort(dataList, left, right);
    //_quickSort2(dataList, left, right);
    return TRUE;
}


//오름차순
void _merge(int dataList[], int sorted[], int first, int mid, int end) // 오름차순
{
    int d_idx, s_idx, t;
    d_idx = mid + 1;
    s_idx = first;
    
    while (first <= mid && d_idx <= end) {
        if (dataList[first] < dataList[d_idx])
            sorted[s_idx++] = dataList[first++];
        else
            sorted[s_idx++] = dataList[d_idx++];
    }
    if (first > mid) { // All elements in left list are copied
        for (t = d_idx; t <= end; t++) // copy remained elements in right list
            sorted[s_idx + t - d_idx] = dataList[t];
    }
    else { // There are remained elements in left list
        for (t = first; t <= mid; t++)// copy remained elements in left list
            sorted[s_idx + t - first] = dataList[t];
    }

    for (first = 0; first <= end; first++)
        dataList[first] = sorted[first];
    
    //printList(sorted);
    return;
}

//내림차순
void _merge2(int dataList[], int sorted[], int first, int mid, int end) 
{
    int d_idx, s_idx, t;
    d_idx = mid + 1;
    s_idx = first;

    while (first <= mid && d_idx <= end) {
        if (dataList[first] > dataList[d_idx])
            sorted[s_idx++] = dataList[first++];
        else
            sorted[s_idx++] = dataList[d_idx++];
    }
    if (first > mid) { // All elements in left list are copied
        for (t = d_idx; t <= end; t++) // copy remained elements in right list
            sorted[s_idx + t - d_idx] = dataList[t];
    }
    else { // There are remained elements in left list
        for (t = first; t <= mid; t++)// copy remained elements in left list
            sorted[s_idx + t - first] = dataList[t];
    }

    for (first = 0; first <= end; first++)
        dataList[first] = sorted[first];

    //printList(sorted);
    return;
}

void _mergeSort(int dataList[], int sorted[], int first, int end) {
    if (first < end) {
        int mid = (first + end) / 2;
        _mergeSort(dataList, sorted, first, mid);
        _mergeSort(dataList, sorted, mid + 1, end);
        _merge(dataList, sorted, first, mid, end);
        //_merge2(dataList, sorted, first, mid, end);
    }
    return;
}

Bool Merge(int dataList[], int size)
{
    int sorted[MAX] = { 0, };
    printf("\n./ Merge Sort");
    _mergeSort(dataList, sorted, 0, size-1);
    return TRUE; 
}


int main()
{
    int i = 0;
    char Fn[30] = { 0, }; // file name
    char* buffer;
    char* tok;
    int buffer_size = 0;
    int size=0, choose = 0;
    int dataList[MAX] = { 0, };

    FILE* fp;

    //printf("\nmain.c\n\n");
    printf("\n\nInput file name :  ");
    if (!scanf(" %s", Fn))
        return 0;
    if (!(fp = fopen(Fn, "r")))
    {
        printf("\nWrong File name.\n\n"); return 0;
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
    dataList[i] = atoi(tok); // dataList에 문자열을 atoi함수를 사용해 숫자로 저장.
    //printf("%d ", dataList[i]);
    while (tok != NULL)
    {
        tok = strtok(NULL, " \n");
        if (tok == NULL)
            break;
        
        dataList[++i] = atoi(tok);
        //printf("%d ", dataList[i]);
    }
    size = i + 1;
    printList(dataList);
    printf("\n\n - Choose a searching method (Selelction : 0, Insertion : 1, Bubble : 2, Quick : 3, Merge : 4) : ");
    if (!scanf(" %d", &choose))
        return 0;
    //printf("%d", choose_method);
    free(buffer);
    buffer = NULL;
    
    switch (choose)
    {
        case 0:
            Selection(dataList, size);
            //Selection2(dataList, size);
            break;
        case 1:
            Insertion(dataList, size);
            //Insertion2(dataList, size);
            break;
        case 2:
            Bubble(dataList, size);
            //Bubble2(dataList, size);
            break;
        case 3:
            Quick(dataList, size);
            break;
        case 4:
            Merge(dataList, size);
            break;
        default:
            printf("\n\nwrong menu number selelcted.\n\n");
            break;
    }
    printf("\n -- Result --");
    printList(dataList);
    return 0;
}