#define _CRT_SECURE_NO_WARNINGS

#include "Ad_Matrix.h"

int main()
{
    GRAPH* graph;
    char DATA[MAX_SIZE][3] = { 0, };
    char Fn[30] = { 0, };
    FILE* fp;

    printf("\nmain.c\n\n");
    printf("File name of Graph : ");
    if (!scanf(" %s", Fn))
        return 0;
    fp = fopen(Fn, "r");
    if (fp == NULL)
    {
        printf("Wrong File name.\n\n"); return 0;
    }
    printf("--------Load File : %s--------\n", Fn);
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp); 
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

    char VERTEX_DATA[MAX_SIZE][2] = { 0, };
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

    graph=graphCreate_Matrix(VERTEX_INDEX+1);
    i = 0;
    while (VERTEX_DATA[i][0])
    {
        InsertVertex(graph, VERTEX_DATA[i][0]);
        i++;
    }
    
    //EDGE INSERT
    i = 1;
    while (DATA[i][0])
    {
        InsertEdge(graph, DATA[i][0], DATA[i][2]);
        i++;
    }

    graphShow(graph);
    free(buffer);
    
    printf("\n\nDepth First Traversal : ");
    graphDpthFrst(graph);
    printf("\n\nBreadth First Traversal : ");
    graphBrdthFrst(graph);
    printf("\n\n");

    graphDestroy(graph);
    graph = NULL;

    return 0;
}