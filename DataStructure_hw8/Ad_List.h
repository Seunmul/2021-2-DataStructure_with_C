//Ad_List.h
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Ad_List_Queue.h"

typedef void* dataPtr;

typedef struct arc
{
    struct vertex* destination;
    struct arc* pNextArc;
}ARC;

typedef struct vertex
{
    struct vertex* pNextVertex;
    void* dataPtr;
    int inDegree;
    int outDegree;
    short processed;
    struct arc* pArc;
}VERTEX;

typedef struct graph{
    int count;
    struct vertex* first;
    int (*compare)(void* argu1, void* argu2);
}GRAPH;


void printStr(void* dataPtr) //*process 자리에 printStr을 넣으면 됨. 혹은 위에 변수 선언으로 넣으면 될 듯
{
    printf("%s ", (char*)dataPtr);
    return;
}

void printInt(void* dataPtr) //*process 자리에 IntStr을 넣으면 됨. 혹은 위에 변수 선언으로 넣으면 될 듯
{
    printf("%d ", *(int*)dataPtr);
    return;
}

GRAPH* graphCreate(int (*compare) (void* argu1, void* argu2));
GRAPH* graphDestroy(GRAPH* graph);
void graphInsVrtx(GRAPH* graph, void* dataInPtr);
int graphDltVrtx(GRAPH* graph, void* dltKey);
int graphInsArc(GRAPH* graph, void* pFromKey, void*pTokey);
int graphDltArc(GRAPH* graph, void* pFromKey, void* pTokey);
void graphDpthFrst(GRAPH* graph, void(*process)(void* dataPtr));
void graphBrdthFrst(GRAPH* graph, void(*process)(void* dataPtr));
bool graphEmpty(GRAPH* graph);
bool graphFull(GRAPH* graph); 

GRAPH* graphCreate(int (*compare) (void* argu1, void* argu2))
{
    GRAPH* newGraph = (GRAPH*)malloc(sizeof(GRAPH));
    if (newGraph == NULL)
        return NULL;
    newGraph->count = 0;
    newGraph->first = NULL;
    return newGraph;
}

void graphInsVrtx(GRAPH* graph, void* dataInPtr)
{
    VERTEX* newPtr;
    VERTEX* locPtr;
    VERTEX* predPtr;
    
    newPtr = (VERTEX*)malloc(sizeof(VERTEX));
    if (newPtr)
    {
        newPtr->pNextVertex = NULL;
        newPtr->dataPtr = dataInPtr;
        newPtr->inDegree = 0;
        newPtr->outDegree = 0;
        newPtr->processed = 0;
        newPtr->pArc = NULL;
        (graph->count)++;
    }
    else
        printf("Overflow error 100\a\n"), exit(100);

    locPtr = graph->first;
    if (!locPtr)
        graph->first = newPtr;
    else
    {
        predPtr = NULL;
        while (locPtr && (graph->compare)(dataInPtr, locPtr->dataPtr) > 0)
        {
            predPtr = locPtr;
            locPtr = locPtr->pNextVertex;
        }
        if (!predPtr)
        {
            graph->first = newPtr;
        }
        else
            predPtr->pNextVertex = newPtr;
        newPtr->pNextVertex = locPtr;
    }
    return;
}

int graphDltVrtx(GRAPH* graph, void* dltKey)
{
    ARC* preArcPtr;
    ARC* arcWalkPtr;
    VERTEX* predPtr;
    VERTEX* walkPtr;
    VERTEX* toVertexPtr;
    
    if (!graph->first)
        return -2; //dltKey not found

    predPtr = NULL;
    walkPtr = graph->first;
    while (walkPtr && (graph->compare(dltKey, walkPtr->dataPtr) > 0))
    {
        predPtr = walkPtr;
        walkPtr = walkPtr->pNextVertex;
    }
    if (!walkPtr || graph->compare(dltKey, walkPtr->dataPtr) != 0)
        return -2;

    if ((walkPtr->inDegree > 0) || (walkPtr->outDegree > 0))
    {
        if (!predPtr)
            graph->first = walkPtr->pNextVertex;
        else
            predPtr->pNextVertex = walkPtr->pNextVertex;

        preArcPtr = NULL;
        arcWalkPtr = walkPtr->pArc;
        while (arcWalkPtr)
        {
            preArcPtr = arcWalkPtr;
            toVertexPtr = preArcPtr->destination;
            arcWalkPtr = arcWalkPtr->pNextArc;
            --predPtr->outDegree;
            --toVertexPtr->inDegree;
            free(preArcPtr);
        }

        --graph->count;
        free(walkPtr);

        return -1;
    }
    //일반적인 경우
    if (!predPtr)
        graph->first = walkPtr->pNextVertex;
    else
        predPtr->pNextVertex = walkPtr->pNextVertex;
    
    --graph->count;
    free(walkPtr);
    return 1;
}

int graphInsArc(GRAPH* graph, void* pFromKey, void* pToKey)
{
    ARC* newPtr;
    ARC* arcPredPtr;
    ARC* arcWalkPtr;
    VERTEX* vertFromPtr;
    VERTEX* vertToPtr;

    newPtr = (ARC*)malloc(sizeof(ARC));
    if (!newPtr)
        return(-1);

    vertFromPtr = graph->first;
    while (vertFromPtr && (graph->compare(pFromKey, vertFromPtr->dataPtr) > 0))
    {
        vertFromPtr = vertFromPtr->pNextVertex;
    }
    if (!vertFromPtr || (graph->compare(pFromKey, vertFromPtr->dataPtr) != 0))
        return (-2);

    vertToPtr = graph->first;
    while (vertToPtr && graph->compare(pToKey, vertToPtr->dataPtr) > 0)
    {
        vertToPtr = vertToPtr->pNextVertex;
    }
    if (!vertToPtr || (graph->compare(pToKey, vertToPtr->dataPtr) != 0))
        return (-3);

    ++vertFromPtr->outDegree;
    ++vertToPtr->inDegree;
    newPtr->destination = vertToPtr;
    if (!vertFromPtr->pArc)
    {
        vertFromPtr->pArc = newPtr;
        newPtr->pNextArc = NULL;
        return 1;
    } // if new arc

    arcPredPtr = NULL;
    arcWalkPtr = vertFromPtr->pArc;
    while (arcWalkPtr && graph->compare(pToKey, arcWalkPtr->destination->dataPtr) >= 0)
    {
        arcPredPtr = arcWalkPtr;
        arcWalkPtr = arcWalkPtr->pNextArc;
    }

    if (!arcPredPtr)
        vertFromPtr->pArc = newPtr;
    else
        arcPredPtr->pNextArc = newPtr;
    newPtr->pNextArc = arcWalkPtr;
    return 1;
}

int graphDltArc(GRAPH* graph, void* fromKey, void* toKey)
{
    VERTEX* fromVertexPtr;
    VERTEX* toVertexPtr;
    ARC* preArcPtr;
    ARC* arcWalkPtr;

    if (!graph->first)
        return -2;
    //locate source vertex
    fromVertexPtr = graph->first;
    while (fromVertexPtr && (graph->compare(fromKey, fromVertexPtr->dataPtr) > 0))
    {
        fromVertexPtr = fromVertexPtr->pNextVertex;
    }
    if (!fromVertexPtr || (graph->compare(fromKey, fromVertexPtr->dataPtr) != 0))
        return (-2);

    //locate destination vertex in adjacency list
    if (!fromVertexPtr->pArc)
        return -3;

    preArcPtr = NULL;
    arcWalkPtr = fromVertexPtr->pArc;

    while (arcWalkPtr && (graph->compare(toKey, arcWalkPtr->destination->dataPtr) > 0))
    {
        preArcPtr = arcWalkPtr;
        arcWalkPtr = arcWalkPtr->pNextArc;
    }
    if (!arcWalkPtr || graph->compare(toKey, arcWalkPtr->destination->dataPtr) != 0)
        return -3;
    toVertexPtr = arcWalkPtr->destination;

    //from, toVertex & arcPtr located. Delete Aarc
    --fromVertexPtr->outDegree;
    --toVertexPtr->inDegree;
    if (!preArcPtr)
        fromVertexPtr->pArc = arcWalkPtr->pNextArc;
    else
        preArcPtr->pNextArc = arcWalkPtr->pNextArc;
    free(arcWalkPtr);
    return -1;
} // graphDltArc

void _DepthFirstTraversal(VERTEX* root, void(*process)(void* dataPtr))
{
    ARC* arc = NULL;
    if (root->processed)
        return;
    (*process)(root->dataPtr);
    root->processed = true;

    for (arc = root->pArc; arc != NULL; arc = arc->pNextArc)
    {
        if (!arc->destination->processed)
            _DepthFirstTraversal(arc->destination, process);
    }
}

void graphDpthFrst(GRAPH* graph, void(*process)(void* dataPtr))
{
    VERTEX* vertexPtr;
    void(*print)(void* dataPtr) = process;

    // set processed flags to not processed
    vertexPtr = graph->first;
    if (vertexPtr == NULL)
        return;
    while (vertexPtr)
    {
        vertexPtr->processed = 0;
        vertexPtr = vertexPtr->pNextVertex;
    }
    vertexPtr = graph->first;
    
    _DepthFirstTraversal(vertexPtr, print);
}

void graphBrdthFrst(GRAPH* graph, void(*process)(void* dataPtr))
{
    bool success;
    VERTEX* walkPtr;
    VERTEX* vertexPtr;
    VERTEX* vertToPTR;
    QUEUE* queue;
    ARC* arcWalkPtr;

    if (!graph->first)
        return;

    // set processed flags to not processed
    walkPtr = graph->first;
    while (walkPtr)
    {
        walkPtr->processed = 0;
        walkPtr = walkPtr->pNextVertex;
    }

    queue = CreateQueue(100);
    walkPtr = graph->first;
    while (walkPtr)
    {
        if (walkPtr->processed < 2)
        {
            if (walkPtr->processed < 1)
            {
                success = Enqueue(queue, walkPtr);
                if (!success)
                    printf("\aQueue overflow 100\a\n"), exit(100);
                walkPtr->processed = 1;
            } 
        }
    

        while (!IsEmptyQueue(queue))
        {
            vertexPtr=Dequeue(queue);
            process(vertexPtr->dataPtr);
            vertexPtr->processed = 2;

            arcWalkPtr = vertexPtr->pArc;
            while (arcWalkPtr)
            {
                vertToPTR = arcWalkPtr->destination;
                if (vertToPTR->processed == 0)
                {
                    success = Enqueue(queue, vertToPTR);
                    if (!success)
                        printf("\aQueue overrflow 101\a\n"), exit(101);
                    vertToPTR->processed = 1;
                }//if vertToPtr
                arcWalkPtr = arcWalkPtr->pNextArc;
            }
        }
        walkPtr = walkPtr->pNextVertex;
    }//while walkPtr
    DestroyQueue(queue);
    return;

}

bool graphEmpty(GRAPH* graph)
{
    if (!(graph->first))
        return true;
    else
        return false;
}

bool graphFull(GRAPH* graph)
{
    return false;
}

GRAPH*  graphDestroy(GRAPH* graph)
{
    if (graphEmpty(graph))
    {
        return graph;
    }
    VERTEX* predPtr;
    VERTEX* walkPtr;
    VERTEX* toVertexPtr;
    ARC* preArcPtr;
    ARC* arcWalkPtr;

    predPtr = NULL;
    walkPtr = graph->first;

    while (walkPtr)
    {
        predPtr = walkPtr;
        walkPtr = walkPtr->pNextVertex;
        preArcPtr = NULL;
        arcWalkPtr = predPtr->pArc;
        while (arcWalkPtr)
        {
            preArcPtr = arcWalkPtr;
            toVertexPtr = preArcPtr->destination;
            arcWalkPtr = arcWalkPtr->pNextArc;
            --predPtr->outDegree;
            --toVertexPtr->inDegree;
            free(preArcPtr);
        }
        --graph->count;
    }
    graph->first=NULL;
    return graph;
 }

