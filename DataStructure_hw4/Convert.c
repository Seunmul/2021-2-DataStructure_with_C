#define _CRT_SECURE_NO_WARNINGS
//#include "Stack_Array.h"
#include "Stack_List.h"

void Convert()
{
    int decimal = 0, inputChk = 0;
    int max_size = 1000;
    Stack* pStack = CreateStack(max_size);

    printf("Enter an integer : ");
    inputChk = scanf(" %d", &decimal);
    if (inputChk != 1)
    {
        printf("END\n\n");
        return;
    }
   
    printf("\nThe binary number of %d: ", decimal);
   
    while (decimal != 0) 
    {
        //printf("%d\n", decimal);
        Push(pStack, decimal%2);
        decimal = decimal / 2;
    }   
    while (IsEmptyStack(pStack) == false)
    {
        printf("%d", Pop(pStack));
    }
    printf("\n");

    DestroyStack(pStack);
    pStack = NULL;
    return;
}
