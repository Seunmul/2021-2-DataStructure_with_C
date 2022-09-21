#define _CRT_SECURE_NO_WARNINGS  
//#include "Stack_Array.h"
#include "Stack_List.h"


void Reverse() 
{
    int input = 0;
    int max_size = 1000;
    Stack* pStack = CreateStack(max_size);

    printf("최대 %d개의 숫자를 입력받을 수 있습니다. \n", max_size);

    for (int i = 0; i <=max_size; i++) 
    {
        if (i == max_size)
        {
            printf("이미 최대 개수 만큼의 숫자를 입력하셨습니다.\n\n");
            continue;
        }
        int inputChk = 0;
        printf("Enter a number: <EOF> to stop: ");
        inputChk = scanf("%d", &input);
        if (inputChk != 1)
        {
            printf("END\n\n");
            break;
        }
        Push(pStack, input);
    }
    printf("current written size of stack : %d\n", CountStackItem(pStack));
    printf("The List of numbers reversed :\n\n");
   
    while (IsEmptyStack(pStack) == false)
    {
        printf("%d\n", Pop(pStack));
    }
    
    DestroyStack(pStack);

    pStack = NULL;
    return;
}



