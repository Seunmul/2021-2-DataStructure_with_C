#define _CRT_SECURE_NO_WARNINGS

#include "Ad_Matrix3.h"
#define FALSE 0;
#define TRUE 1;
#define INF 1000000;

int found[MAX_SIZE] = { 0, };
int distance[MAX_SIZE] = { 0, };

void graphShow(GRAPH* graph)
{
    int i = 0, j = 0;
    for (i = 0; i < graph->size; i++)
    {
        printf("%c : ", graph->VERTEX[i]);
        for (j = 0; j < graph->size; j++)
        {
            if (graph->MATRIX[i][j] >= 1)
                printf("%c (%d) ", graph->VERTEX[j],graph->MATRIX[i][j]);
        }
        printf("\n");
    }
}

void matrixShow(GRAPH* graph) {

    int size = graph->size;
    int i = 0, j = 0;
    printf("\n\n");
    for (i = 0; i < size; i++)
         printf(" %c", graph->VERTEX[i]);
    
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

int shtVertex(int n)
{
    int i, min, min_index;
    min = INF;
    min_index = -1;
    for (i = 0; i < n; i++)
    {
        if ((distance[i] < min) && !found[i])
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[], GRAPH* graph)
{
    int MST_temp[MAX_SIZE][3] = { 0, };

    for (int i = 1; i < graph->size; i++)
    {
        MST_temp[i - 1][0] = parent[i];
        MST_temp[i-1][1] = i;
        MST_temp[i-1][2] = graph->MATRIX[i][parent[i]];
    }
    
    for (int i = 0; i < graph->size; i++)
    {
        int temp = 0;    
        if (MST_temp[i][0] > MST_temp[i+1][0])
        {
            if ((MST_temp[i + 1][0] + MST_temp[i + 1][1] + MST_temp[i + 1][2]) == 0)
                break;
            temp = MST_temp[i+1][0];
            MST_temp[i+1][0] = MST_temp[i][0];
            MST_temp[i][0] = temp;

            temp = MST_temp[i + 1][1];
            MST_temp[i + 1][1] = MST_temp[i][1];
            MST_temp[i][1] = temp;

            temp = MST_temp[i + 1][2];
            MST_temp[i + 1][2] = MST_temp[i][2];
            MST_temp[i][2] = temp;
        }
    }
    printf("\n");
    for (int i = 0; i < graph->size - 1; i++)
    {
        printf("\n%c ", graph->VERTEX[MST_temp[i][0]]);
        printf("%c ", graph->VERTEX[MST_temp[i][1]]);
        printf("(%d) ", MST_temp[i][2]);
    }
    return; 
}

void createMST(GRAPH* graph)
{
    int i = 0, u = 0, w = 0;/*iterative*/
    int parent[MAX_SIZE] = { 0, };

    for(i=0;i<MAX_SIZE;i++)
    {
        found[i] = 0;
        distance[i] = 0;
    }

    for (i = 0; i < graph->size; i++)
        distance[i] = INF; found[i] = FALSE;
    
    distance[0] = 0;
    parent[0] = -1; 

    for (int i = 0; i < graph->size - 1; i++)
    {
        u = shtVertex(graph->size);
        found[u] = true;

       for (w = 0; w < graph->size; w++)
       {
           if (graph->MATRIX[u][w] && !found[w] && graph->MATRIX[u][w] < distance[w])
           {
               parent[w] = u, distance[w] = graph->MATRIX[u][w];
           }
       }
    }
    printMST(parent, graph);
}

void _printStepPath(GRAPH* graph) 
{
    int i,j;
    for (i=0,j=1; i < graph->size-1; i++, j++)
        printf("\n%c %c : %d", graph->VERTEX[0], graph->VERTEX[j], distance[j]);
    printf("\n");
    return ;
}

void shortPath(GRAPH* graph, int to)
{
    int fromMST[MAX_SIZE] = { 0, };
    int valueMST[MAX_SIZE] = { 0, };
    int i=0, u=0, w=0;/*iterative*/
    int n = graph->size;
    int parent[MAX_SIZE] = { 0, };
    int step = 1;
    
    GRAPH* pathGraph = graphCreate_Matrix(graph->size);
    if (!pathGraph)
        return;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        found[i] = 0;
        distance[i] = 0;
    }

    //pathGraph->연결되지 않은 EDGE의 weight를 1000으로 설정 및 초기화
    for (int i = 0; i < graph->size; i++)
    {
        pathGraph->VERTEX[i] = graph->VERTEX[i];
        found[i] = FALSE;
        distance[i] = pathGraph->MATRIX[0][i];
        for (int j = 0; j < graph->size; j++)
        {
            if (graph->MATRIX[i][j] == 0)
                pathGraph->MATRIX[i][j] = 1000;
            else
                pathGraph->MATRIX[i][j] = graph->MATRIX[i][j];
        };
    }
    
    found[0] = TRUE;
    distance[0] = 0;
    printf("\n");
    _printStepPath(pathGraph);

    for (i = 0; i < n - 1; i++)
    {
        u = shtVertex(n);
        found[u] = TRUE;
        for (w = 0; w < n; w++)
        {
            if (!found[w] && (distance[u] + pathGraph->MATRIX[u][w] < distance[w]))
                distance[w] = distance[u] + pathGraph->MATRIX[u][w];
        }
        _printStepPath(pathGraph);
    }
}

int main()
{
    GRAPH* graph;
    //graph->compare = compareStr;
    char DATA[MAX_SIZE][5] = { 0, };
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

    //배열에 저장된 첫 열의 값을 참조 -> 중복제거
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

    //graph생성
    graph = graphCreate_Matrix(VERTEX_INDEX + 1);
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
        InsertEdge(graph, DATA[i][0], DATA[i][2],((int)DATA[i][4])-48);
        i++;
    }
    printf("\n\nThe Graph is : \n\n");
    graphShow(graph);
    free(buffer);

    printf("\n\nMinimum Spanning Tree : ");
    createMST(graph);
    printf("\n\nShortest Path from A : ");
    shortPath(graph, 0);
    printf("\n\n");

    graphDestroy(graph);
    graph = NULL;

    return 0;
}