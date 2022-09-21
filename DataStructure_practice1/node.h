#pragma once

typedef struct node{
    
    void* dataPtr;
    struct node* link;
}NODE;

NODE* createNode(void* itemPtr);
