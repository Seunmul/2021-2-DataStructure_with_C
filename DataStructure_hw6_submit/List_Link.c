//List_Link.c
#define _CRT_SECURE_NO_WARNINGS

#include "List_Link.h"

void Traverse(List *pList)
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
    ListNode* pPre = NULL, * pLoc = NULL;
    bool found = _searchList(pList, &pPre, &pLoc, data);

    if (found)
        printf("My List has %d.\n", data);
    else
        printf("My List does not have %d.\n", data);
}

void Out(List* pList, Element data)
{
    ListNode* pPre = NULL, * pLoc = NULL;
    bool found = _searchList(pList, &pPre, &pLoc, data);

    if (found)
    {
        _deleteList(pList, pPre, pLoc);
        printf("%d was removed\n", data);
    }
    else
    {
        printf("failed to remove %d : not exists\n",data);
    }
}

int main()
{
    int sel = 0, chk = NORMAL;
    Element input = 0;
    List* pList = createList();
    while (chk)
    {
        printf("In (0), Seach (1), Out (2), Exit (3) : ");
        if (!scanf(" %d", &sel)) { printf("Error, program terminates\n\n\n");  chk = EXIT; break; }

        switch (sel)
        {
        case 0:
            //In
            printf("In : ");
            if (!scanf(" %d", &input)) { printf("input int number\n\n\n"); chk = EXIT; break; }
            
            addNodeList(pList, input);
            Traverse(pList);

            break;

        case 1:
            //Search
            if (isEmptyList(pList))
            {
                printf("List is Empty\n\n");
                break;
            }
            printf("Search : ");
            if (!scanf(" %d", &input)) { printf("input int number\n\n\n"); chk = EXIT; break; }

            Search(pList, input);
            Traverse(pList);

            break;

        case 2:
            //Out
            if (isEmptyList(pList))
            {
                printf("List is Empty\n\n");
                break;
            }
            printf("Out : ");
            if (!scanf(" %d", &input)) { printf("input int number\n\n\n");  chk = EXIT; break; }

            Out(pList, input);
            Traverse(pList);

            break;

        case 3:
            //Exit

            chk = EXIT;
            break;

        default:
            printf("choose correct number of menu : (0), (1),(2)\n\n\n");
            break;
        }
        if (chk == EXIT) break;
    }
    
    destroyList(pList);
    pList = NULL;

    return 0;
}