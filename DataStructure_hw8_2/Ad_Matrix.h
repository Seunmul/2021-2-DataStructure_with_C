#pragma once

#define MAX_SIZE 31
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _graph 
{
    int size;
    int count;
    int MATRIX[MAX_SIZE][MAX_SIZE];
    char VERTEX[MAX_SIZE];
} GRAPH;

int compareChar(const void* a, const void* b)
{
    char char1 = *(char*)a; 
    char char2 = *(char*)b;

    if (char1 < char2)
        return -1;      

    if (char1 > char2)
        return 1;       

    return 0; 
}

bool graphEmpty(GRAPH* graph)
{
    if (graph->size == 0)
        return true;
    return false;
}

bool graphFull(GRAPH* graph)
{
    if (graph->size >= MAX_SIZE)
        return true;
    if (graph->count >= graph->size)
        return true;
    else if (graph->count == 0)
        return false;
    return false;
}

//Create Graph
GRAPH* graphCreate_Matrix(int size)
{
    GRAPH* graph=(GRAPH*)malloc(sizeof(GRAPH));    
    int i = 0, j = 0;

    if (graph == NULL)
        return NULL;
    graph->size = size;
    graph->count = 0;
    
    for (i = 0; i < MAX_SIZE; i++)
    {
        graph->VERTEX[i] = 0;
        for (j = 0; j < MAX_SIZE; j++)
        {
            if((i<size)&&(j<size))
                graph->MATRIX[i][j] = 0;
            else
                graph->MATRIX[i][j] = -1;
        }
    }
    return graph;
}

int findVertex(GRAPH* graph, char dataPtr)
{
    int index = 0;
    int j = 0, k = 0;

    while (graph->VERTEX[index]) //1열의 데이터 : 중복되지 않는 데이터가 있을 시 VERTEX_DATA에 추가
    {
        k = 0;
        if (graph->VERTEX[index] == dataPtr)
        {
            k = 1;
        }
        if (k == 1)
            return index;
        index++;
    }

    return index;
}


void InsertVertex(GRAPH* graph, char dataPtr)
{
    if (graphFull(graph))
        return;
    
    graph->VERTEX[graph->count++] = dataPtr;
    qsort(graph->VERTEX, graph->count, sizeof(char), compareChar);
}

void InsertEdge(GRAPH* graph, char fromVertex, char toVertex)
{
    graph->MATRIX[findVertex(graph, fromVertex)][findVertex(graph,toVertex)]=1;
}

void deleteEdge(GRAPH* graph, char fromVertex, char toVertex)
{
    graph->MATRIX[findVertex(graph, fromVertex)][findVertex(graph, toVertex)] = 0;
}

void graphDestroy(GRAPH* graph)
{
    int i = 0, j = 0;
    for (; i < graph->size; i++)
    {
        for(; j<graph->size;j++)
        {
            graph->MATRIX[i][j] = -1;
        }
    }
    free(graph);
}

int findMatrixRow(GRAPH* graph, int from)
{
    int j = 0, cnt = 0;
    for (j = 0; j < graph->size; j++)
    {
        if (graph->MATRIX[from][j] >= 1)
        {
            cnt = 1; break;
        }
    }
    if (cnt == 1)
        return j;
    else
        return -1;
}

void _DepthFirstTraversal(GRAPH* graph, int from, int processed[])
{
    int to = 0;
    to = findMatrixRow(graph, from);
    if (to == -1)
        return;
    if (processed[to] != 0)
        printf("%c ", graph->VERTEX[to]);
    processed[to] = 0;
    graph->MATRIX[from][to] = 0;

    do {
        _DepthFirstTraversal(graph, to, processed);
        from = to;
    } while ((from = findMatrixRow(graph, from)) != -1);
}

void graphDpthFrst(GRAPH* graph)
{
    GRAPH* newGraph = graphCreate_Matrix(graph->size);
    int processed[MAX_SIZE] = { 0, };
    if (!newGraph)
        return;
    for (int i = 0; i < graph->size; i++)
    {
        processed[i] = 1;
        newGraph->VERTEX[i] = graph->VERTEX[i];
        for (int j = 0; j < graph->size; j++)
            newGraph->MATRIX[i][j] = graph->MATRIX[i][j];
    }
    newGraph->size = graph->size;
    printf("%c ", graph->VERTEX[0]);
    processed[0] = 0;
    do {
        _DepthFirstTraversal(newGraph, 0, processed);
    } while (findMatrixRow(newGraph, 0) != -1);

    graphDestroy(newGraph);
    newGraph = NULL;
}

void graphBrdthFrst(GRAPH* graph)
{
    int processed[MAX_SIZE] = { 0, };
    for (int i = 0; i < graph->size; i++)
    {
        processed[i] = 1;
    }

    printf("%c ", graph->VERTEX[0]);
    processed[0] = 1;

    int i = 0, j = 0;
    for (i = 0; i < graph->size; i++)
    {
        
        for (j = 0; j < graph->size; j++)
        {
            if (graph->MATRIX[i][j] >= 1 && (processed[j] == 1))
            {
                printf("%c ", graph->VERTEX[j]);
                processed[j] = 0;
            }
        }
    }
}

void graphShow(GRAPH* graph)
{
    int i = 0, j = 0;
    for (i = 0; i < graph->size; i++)
    {
        printf("%c : ", graph->VERTEX[i]);
        for (j = 0; j < graph->size; j++)
        {
            if (graph->MATRIX[i][j] >= 1)
                printf("%c ", graph->VERTEX[j]);
        }
        printf("\n");
    }
}

void matrixShow(GRAPH* graph) {

    int size = graph->size;
    int i = 0, j = 0;
    printf("\n\n");
    for (i = 0; i < size; i++)
    {
        printf(" %c", graph->VERTEX[i]);
    }

    printf("\n\n");
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if ((i < size) && (j < size))
                printf(" %d", graph->MATRIX[i][j]);
        }
        if ((i >= size) && (j >= size))
            continue;
        printf("\n");
    }
}

