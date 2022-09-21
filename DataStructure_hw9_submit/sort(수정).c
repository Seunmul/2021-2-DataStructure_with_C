//sort.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXDATA 1000

typedef int Bool;

int i = 0, j = 0, k = 0; /*iterative*/

void printList(int data[MAXDATA] , int size_data)
{
    printf("\n\n --\n\n");
    for (i = 0; i < size_data; i++)
        printf("%d ",data[i]);
    
    printf("\n\n --\n\n");
    return;
}

Bool Selection(int data[MAXDATA], int size_Data)
{
    int n = size_Data;
    int smallest = 0;
    int temp = 0;
    printf("\n./ Selection Sort");
    for (i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (j = i + 1; j < n; j++)
            if (data[j] < data[smallest])
                smallest = j;
        // Smallest selected: exchange with current
        temp = data[i];
        data[i] = data[smallest];
        data[smallest] = temp;
    }   
    return TRUE;
}

Bool Insertion(int data[MAXDATA], int size_Data)
{
    printf("\n./ Insertion Sort");
    int n = size_Data;
    int hold = 0;
    for (i = 1; i < n; i++) 
    {
        hold = data[i];
        for (j = i; j > 0 && hold < data[j - 1]; j--)
            data[j] = data[j-1];
       data[j] = hold;
    }
    return TRUE;
}

Bool Bubble(int data[MAXDATA], int size_Data)
{
    printf("\n./ Bubble Sort");
    
    int n = size_Data;
    int temp = 0;
    int sorted = FALSE;
        
    for (i = 0; i < n && !sorted; i++)
    {
        for (j = n - 1, sorted = TRUE; j > i; j--)
        {
            if (data[j] < data[j - 1])
            {
                sorted = FALSE;
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
        }
    }
    return TRUE;
}

void _quickSort(int list[], int left, int right)
{
    int pivot = 0, i = 0, j = 0;
    int temp = 0;
    // It is assumed that list[left].key <= llist[right+1].key
    if (left < right) {
        i = left; j = right + 1;
        pivot = list[left];
        do 
        {
            do
                i++;
            while (list[i] < pivot);
            
            do
                j--;
            while (list[j] > pivot);

            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
                
        } while (i < j);
        temp = list[left];
        list[left] = list[j];
        list[j] = temp;
        
        _quickSort(list, left, j - 1);
        _quickSort(list, j + 1, right);
    }
}

Bool Quick(int data[MAXDATA], int size_Data)
{
    int left = 0;
    int right = size_Data - 1;
    printf("\n./ Quick Sort");
    _quickSort(data, left, right);
    return TRUE;
}

void _merge(int list[], int sorted[], int first, int mid, int end)
{
    int j, k, t;
    j = mid + 1;
    k = first;
    
    while (first <= mid && j <= end) {
        if (list[first] < list[j])
            sorted[k++] = list[first++];
        else
            sorted[k++] = list[j++];
    }
    if (first > mid) { // All elements in left list are copied
        for (t = j; t <= end; t++) // copy remained elements in right list
            sorted[k + t - j] = list[t];
    }
    else { // There are remained elements in left list
        for (t = first; t <= mid; t++)// copy remained elements in left list
            sorted[k + t - first] = list[t];
    }

    for (first = 0; first <= end; first++)
        list[first] = sorted[first];
    return;
}

void _mergeSort(int list[], int sorted[], int first, int end) {
    if (first < end) {
        int mid = (first + end) / 2;
        _mergeSort(list, sorted, first, mid);
        _mergeSort(list, sorted, mid + 1, end);
        _merge(list, sorted, first, mid, end);
    }
    return;
}

Bool Merge(int data[MAXDATA], int size_Data)
{
    int sorted[MAXDATA] = { 0, };
    printf("\n./ Merge Sort");
    _mergeSort(data, sorted, 0, size_Data-1);
    return TRUE; 
}


int main()
{
    char Fn[30] = { 0, }; // file name
    char* buffer;
    char* tok;
    int buffer_size = 0;
    int size_Data =0, choose_method = 0;
    int integer_Data[MAXDATA] = { 0, };

    FILE* fp;

    //printf("\nmain.c\n\n");
    printf("\n\nInput file name :  ");
    if (!scanf(" %s", Fn))
        return 0;
    fp = fopen(Fn, "r");
    if (fp == NULL)
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

    i = 0;
    tok = strtok(buffer, " \n");
    integer_Data[i] = atoi(tok);
    //printf("%d ", integer_Data[i]);
    while (tok != NULL)
    {
        tok = strtok(NULL, " \n");
        if (tok == NULL)
            break;
        
        integer_Data[++i] = atoi(tok);
        //printf("%d ", integer_Data[i]);
    }
    size_Data = i + 1;

    printf("\n\n - Choose a searching method (Selelction : 0, Insertion : 1, Bubble : 2, Quick : 3, Merge : 4) : ");
    if (!scanf(" %d", &choose_method))
        return 0;
    //printf("%d", choose_method);
    free(buffer);

    switch (choose_method)
    {
        case 0:

            Selection(integer_Data, size_Data);
            break;
        case 1:

            Insertion(integer_Data, size_Data);
            
            break;
        case 2:

            Bubble(integer_Data, size_Data);
            break;
        case 3:

            Quick(integer_Data, size_Data);
            break;
        case 4:

            Merge(integer_Data, size_Data);
            break;
        default:
            printf("\n\nwrong menu number selelcted.\n\n");
            break;
    }
    printList(integer_Data, size_Data);
    return 0;
}