#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

NODE* createNode(void* itemPtr)
{
    NODE* nodePtr = NULL;
    nodePtr = (NODE*)malloc(sizeof(NODE));
    nodePtr->dataPtr = itemPtr;
    nodePtr->link = NULL;
    return nodePtr;
}

void makedata(char* d)
{
    //d[4] = 'P';
    *(d + 4) = 'P'; //�д� �� ������ ���� �ٲٴ� �� ������ �����.
    return;
}
//�Լ� ������ �̿��ؼ� ��Ģ���� ���� �����غ���..

int main()
{
/*    struct Node {
        int data;
        struct Node* next;
    };

    struct Node n1,n2,n3,n4;
    n1.data = 0;
    n1.next = &n2;
    n2.data = 1;
    n2.next = &n3;
    n3.data = 2;
    n3.next = &n4;
    n4.data = 3;
    n4.next = NULL;

    printf("%d\n", n1.next->next->next->data);
    */
    int* newData = NULL;
    int* newData2 = NULL;
    int* nodeData = NULL;
    int* nodeData2 = NULL;

    NODE* node = NULL;
    NODE* node2 = NULL;
    NODE* (*function)(void*) = createNode;

    char* data = (char*)malloc(sizeof(char) * 10);
    char* data2 = (char*)malloc(sizeof(char) * 10);
    strcpy(data,"abcde"); //���ͷ� �ּҿ� �ִ� ���ڿ��� �����޸𸮿� �Ҵ��ϴ� �� // �������� // �ּ� ���ٵ� ����
    data2 = "asdfa"; // ���ͷ� �ּҸ� �����޸𸮿� �Ҵ��ϴ� �� // �����Ұ�
    printf("%s\n", data);
    makedata(data);
    printf("%s\n", data);

    newData = (int*)malloc(sizeof(int));
    *newData = 7;

    newData2 = (int*)malloc(sizeof(int));
    *newData2 = 75;

    node =  (*function)(newData);
    node2 = (*function)(newData2);

    node->link = node2;
    printf("Data from node : %d\n", *((int*)node->dataPtr));
    printf("Data from node : %d\n", *((int*)node->link->dataPtr));

    free(newData);
    free(newData2);
    free(node);
    free(node2);

   void* ptr = NULL;
    int i = 7;
    float f = 23.5;

    ptr = &i;
    printf("%d\n", *((int*)ptr) );
    

    ptr = &f;
    printf("%f\n", *((float*)ptr));
    
    
    printf("%p", function);

    return 0;
}