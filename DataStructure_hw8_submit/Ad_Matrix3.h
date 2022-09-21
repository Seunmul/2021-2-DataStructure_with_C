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

GRAPH* graphCreate_Matrix(int size)
{
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
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
            if ((i < size) && (j < size))
                graph->MATRIX[i][j] = 0;
            else
                graph->MATRIX[i][j] = -1;
        }
    }
    return graph;
}

void InsertVertex(GRAPH* graph, char dataPtr)
{
    if (graphFull(graph))
        return;    //graph의 사이즈 제한만큼 넣을 수 있음

    graph->VERTEX[graph->count++] = dataPtr;
    qsort(graph->VERTEX, graph->count, sizeof(char), compareChar);
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

void InsertEdge(GRAPH* graph, char fromVertex, char toVertex,int weight)
{
    graph->MATRIX[findVertex(graph, fromVertex)][findVertex(graph, toVertex)] = weight;
    graph->MATRIX[findVertex(graph, toVertex)][findVertex(graph, fromVertex)] = weight;
    // matrixShow(graph);
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
        for (; j < graph->size; j++)
        {
            graph->MATRIX[i][j] = -1;
        }
    }
    free(graph);
}

