#define _CRT_SECURE_NO_WARNINGS
#include "Stack_List.h"

//Convert
char* Convert(int decimal)
{
    char* a[100] = { 0, };
    char temp[2] = { 0, };
    char* result = (char*)malloc(sizeof(char) * 100);
    memset(result, 0, 100);
    int max_size = 1000;
    int index = 0;
    
    Stack* pStack = CreateStack(max_size);

    while (decimal != 0)
    {
        a[index] = (char*)malloc(sizeof(char) * 3);
        sprintf(a[index], "%d", decimal % 12);
        Push(pStack, a[index]);
        decimal = decimal / 12;
        index++;
    }
    while (IsEmptyStack(pStack) == false)
    {
        switch (atoi(Top(pStack)))
        {
        case 11:
            temp[0] = 'B';
            Pop(pStack);
            break;
        case 10:
            temp[0] = 'A';
            Pop(pStack);
            break;
        default:
            sprintf(temp, "%s", Pop(pStack));
            break;
        }
        //printf("%s", temp);
        strcat(result, temp);
    }
    //printf("%s", result);
    //printf("\n");

    DestroyStack(pStack);
    pStack = NULL;
    for (int j = 0; j < index; j++)
    {
        free(a[j]);
    }
    return result;
}

//현재 스택의 모든 멤버를 조회
void ViewStackMember(Stack* pStack)
{
    StackNode* temp = NULL;
    int size = pStack->count;
    temp = pStack->top;
    if (IsEmptyStack(pStack))
    {
        printf("STACK Stat : NULL\n");
        return;
    }
    else
    {
        printf("STACK Stat : ");

        for (int i = 0; i < size; i++)
        {
            printf("%s ", temp->data);
            temp = temp->next;
        }
        printf("(%d)\n", pStack->count);
    }

}

//현재 스택의 멤버 중 입력값과 같은 값이 저장된 Stack의 위치를 찾아 Pop -> 코드 수정해야할듯....이 부분만 떼서 수정하자.
void FindPopStackMember(Stack* pStack, int  decimal)
{
    StackNode* temp = NULL;
    int size = pStack->count;
    int index = 0;
    char* array[100] = { 0, };
    char* str = NULL;
    str = Convert(decimal);

    if (IsEmptyStack(pStack))
        return;
    else
    {
        int validchk = 0;
        temp = pStack->top;
        for (int i = 0; i < size; i++)
        {
            if (atoi(temp->data) == atoi(str))
            {
                validchk = 1;                break;
            }
            temp = temp->next;
        }
        if (validchk == 0) { printf("there is no value ");     return; }

        for (int i = 0; i < size; i++)
        {
            temp = pStack->top;
            if (atoi(temp->data) == atoi(str))
            {
                Pop(pStack);                break;
            }
            else {
                array[index] = (char*)malloc(sizeof(char) * 30);
                array[index] = Pop(pStack);                index++;
            }
        }

        for (index; index > 0; index--)
        {
            char* temp = (char*)malloc(sizeof(char) * 30);
            sprintf(temp, "%s", array[index - 1]);
            Push(pStack, temp);
        }

        for (int i = 0; i < index; i++)
        {
            free(array[i]);
        }
    }

    free(str);
    return;
}


int main()
{
    int sel = 0, selchk = 1, inputChk = 0;
    char* result[1000] = { 0, };
    int result_index = 0;
    int decimal = 0;
    Stack* pStorageStack = CreateStack(1000);

    while (selchk)
    {
        printf("Push(0), Pop(1), Exit(2) : ");

        if (!scanf("%d", &sel)) {
            printf("input error, program terminates");            break;
        }
        selchk = getchar();

        switch (sel)
        {
        case 0:
            printf("Push : ");

            inputChk = scanf("%d", &decimal);
            if (inputChk != 1) {
                printf("input Error : check your input \n\n");
                inputChk = getchar();                break;
            }
            else if (decimal >= 2147483648)
            {
                printf("wrong input number : input range is 0 to 2147483647 \n"); break;
            }
            inputChk = getchar();
            result[result_index] = Convert(decimal);
            //printf("input : %s\n\n",result[result_index] = Convert(decimal));
            Push(pStorageStack, result[result_index]);
            ViewStackMember(pStorageStack);
            result_index++;

            printf("\n");
            break;

        case 1:
            printf("Pop : ");
            if (IsEmptyStack(pStorageStack)) {
                printf("Stack is Empty. \n\n"); break;
            }
            inputChk = scanf("%d", &decimal);
            if (inputChk != 1) {
                printf("input Error : check your input \n\n");
                inputChk = getchar();                break;
            }
            inputChk = getchar();
            FindPopStackMember(pStorageStack, decimal);
            ViewStackMember(pStorageStack);
            printf("\n");
            break;

        case 2:
            printf("Program terminates\n ");
            selchk = 0;            break;

        default:
            printf("Check your input : select 0 or 1 or 1 \n\n");         break;
        }
        if (selchk == 0) { break; }
    }

    for (int j = 0; j < result_index; j++)
    {
        free(result[j]);
    }
    DestroyStack(pStorageStack);
    pStorageStack = NULL;
    return 0;
}