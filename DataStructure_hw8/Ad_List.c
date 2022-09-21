//Ad_List.c
#define _CRT_SECURE_NO_WARNINGS
#define MAX_DATA 31

#include "Ad_List.h"

int compareStr(void* argu1, void* argu2)
{
    return strcmp((char*)argu1, (char*)argu2);
}

int compareInt(void* argu1, void* argu2)
{
    int num1 = *(int*)argu1;    
    int num2 = *(int*)argu2;   

    if (num1 < num2)    
        return -1;      

    if (num1 > num2) 
        return 1;       

    return 0;  
}

void graphShow(GRAPH* graph)
{
    VERTEX* predPtr;
    VERTEX* walkPtr;
    VERTEX* toVertexPtr;
    ARC* preArcPtr;
    ARC* arcWalkPtr;

    if (graphEmpty(graph))
        return;
    
    //locate first vertex 
    predPtr = NULL;
    walkPtr = graph->first;
    printf("\nThe graph is\n");
    while (walkPtr)
    {
        predPtr = walkPtr;
        walkPtr = walkPtr->pNextVertex;
        printf("\n%s :", (char*)predPtr->dataPtr);
    
        preArcPtr = NULL;
        arcWalkPtr = predPtr->pArc;
        while (arcWalkPtr)
        {
            preArcPtr = arcWalkPtr;
            toVertexPtr = preArcPtr->destination;
            arcWalkPtr = arcWalkPtr->pNextArc;
            --predPtr->outDegree;
            --toVertexPtr->inDegree;
            printf(" %s", (char*)preArcPtr->destination->dataPtr);
        }
    }
}

int main()
{
    GRAPH* graph = graphCreate(compareStr);
    graph->compare = compareStr;
    char DATA[MAX_DATA][3] = { 0, };
    char Fn[30] = { 0, };
    FILE* fp;

    printf("\nmain.c\n\n");
    printf("File name of Graph : ");
    if (!scanf(" %s", Fn))
        return 0;
    fp = fopen(Fn, "r");
    if (fp == NULL)
    {
        printf("Wrong File name.\n\n"); return 0 ;
    }
    printf("--------Load File : %s--------\n", Fn);
    //파일을 끝까지 읽어서
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp); // size : 입력 파일 사이즈
    char* buffer = (char*)malloc(size + 1);
    if (buffer == NULL)
        return 0;
    memset(buffer, 0, size + 1);
    rewind(fp);
    fread(buffer, size + 1, 1, fp);
    fclose(fp);
    
    char* tok;
    int cnt = 0;

    tok = strtok(buffer, "\n");
    strcpy(DATA[cnt], tok);
    
    while (tok != NULL)
    {
        tok = strtok(NULL, "\n");
        cnt++;
        if (tok == NULL)
            break;
        strcpy(DATA[cnt], tok);
    
    }//각 문단을 2차원배열에 저장

    char VERTEX_DATA[MAX_DATA][2] = { 0, };
    VERTEX_DATA[0][0] = DATA[0][0];
    
    int VERTEX_INDEX = 0;
    int i = 0, j = 0, k = 0;
    
    i = 1;
    while (DATA[i][0]) //1열의 데이터 : 중복되지 않는 데이터가 있을 시 VERTEX_DATA에 추가
    {
        j = 0; k = 0;
        while (VERTEX_DATA[j][0])
        {
            if (VERTEX_DATA[j][0] == DATA[i][0])
            {
                k = 1; break;
            }
            j++;
        }
        if (k == 0)
            VERTEX_DATA[++VERTEX_INDEX][0] = DATA[i][0];
        i++;
    }
    i = 1;
    while (DATA[i][2]) //2열의 데이터 참조 -> 1열과 중복되지 않는 데이터가 있을 시 VERTEX_DATA에 추가
    {
        j = 0; k = 0;
        while (VERTEX_DATA[j][0])
        {
            if (VERTEX_DATA[j][0] == DATA[i][2])
            {
                k = 1; break;
            }
            j++;
        }
        if (k == 0)
            VERTEX_DATA[++VERTEX_INDEX][0] = DATA[i][2];
        i++;
    }

    //Vertex로 먼저 insrt하고
    i = 0;
    while (VERTEX_DATA[i][0])
    {
        graphInsVrtx(graph, VERTEX_DATA[i]);
        i++;
    }

    //EDGE INSERT
    i = 1;
    while (DATA[i][0])
    {
        char _temp_A[2] = { 0, };
        char _temp_B[2] = { 0, };
        _temp_A[0] = DATA[i][0];
        _temp_B[0] = DATA[i][2];
        graphInsArc(graph, _temp_A, _temp_B);
        i++;
    }
    free(buffer);
    graphShow(graph);

    printf("\n\nDepth First Traversal : ");
    graphDpthFrst(graph, printStr);
    printf("\n\nBreadth First Traversal : ");
    graphBrdthFrst(graph, printStr);
    printf("\n\n");

    graph=graphDestroy(graph);
    free(graph);
    graph = NULL;

    return 0;
}