#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {

    void* dataPtr;
    struct  _Node* link;

} NODE;

NODE* createNode(void* item, NODE* NextNode)
{
    NODE* nodePtr = NULL;
    nodePtr = (NODE*)malloc(sizeof(NODE));
    nodePtr->dataPtr = item;
    nodePtr->link = NextNode;
    return nodePtr;
}