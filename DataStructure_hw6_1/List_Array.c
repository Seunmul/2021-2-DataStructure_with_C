//List_Array.c
#define _CRT_SECURE_NO_WARNINGS

#define LIST_SIZE 5
#define NORMAL 1
#define ERROR 0

#include "List_Array.h"

void Traverse(List* pList)
{
    int ret = 1;
    printf("The current status of List : ");
    for (int i = 0, data = 0; ret != 0; i++)
    {
        ret = traverseList(pList, i, &data);
        if (i != 0 && ret)
            printf(", ");
        if (ret)
            printf("%d", data);
    }
    printf("\n\n\n");
    
}

void Search(List* pList, Element data)
{
    int pPreIndex = 0,  pLocIndex = 0;
    bool found = _searchList(pList, &pPreIndex, data);
    if (found)
        printf("My List has %d.\n", data);
    else
        printf("My List does not have %d.\n", data);
}

int main()
{
    int sel = 0, chk = NORMAL;
    Element input = 0;
    List* pList = createList(LIST_SIZE);

    if (!pList) {
        printf("Fail to allocate for List\n");
        return 0;
    }

    printf("In (0), Seach (1), Out (2), Exit (3) : ");
    while (chk=scanf(" %d", &sel) && sel != 3)    
    {
        switch (sel)        
        {
            case 0:
                //In
                if (isFullList(pList))    {
                    printf("List is Full\n\n");
                    break;
                }
                printf("In : ");
                if (!scanf(" %d", &input)) { printf("input int number\n\n\n"); chk = ERROR;  break; }

                addArrayList(pList, input);
                Traverse(pList);
                break;

            case 1:
                //Search
                if (isEmptyList(pList))    {
                    printf("List is Empty\n\n");
                    break;
                }
                printf("Search : ");
                if (!scanf(" %d", &input)) { printf("input int number\n\n\n"); chk = ERROR; break; }

                Search(pList, input);
                Traverse(pList);
                break;

            case 2:
                //Out
                if (isEmptyList(pList))    {
                    printf("List is Empty\n\n");
                    break;
                }
                printf("Out : ");
                if (!scanf(" %d", &input)) { printf("input int number\n\n\n"); chk = ERROR; break; }

                removeList(pList, input);
                Traverse(pList);
                break;

            default:
                printf("choose correct number of menu : (0), (1), (2), (3)\n\n\n");
                break;
        }
        if (chk == ERROR)
            break;
        printf("In (0), Seach (1), Out (2), Exit (3) : ");
    }

    if(sel!=3 && chk==ERROR)
        printf("Error, program terminates\n\n\n");
    
    destroyList(pList);
    pList = NULL;

    return 0;
}


/*
void Out(List* pList, Element data)
{
    int pPreIndex = 0, pLocIndex = 0;
    bool found = _searchList(pList, &pPreIndex, data);

    if (found)
    {
        _deleteList(pList, &pPreIndex, &pLocIndex);
        printf("%d was removed\n", data);
    }
    else
    {
        printf("failed to remove %d : not exists\n", data);
    }
}*/