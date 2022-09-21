#define _CRT_SECURE_NO_WARNINGS
#include "Stack_Link.h"

#define START 1 // 매크로 사용
#define END 0

//현재 스택의 모든 멤버를 조회
void ViewStackMember(Stack* pStack)
{
    StackNode* temp = pStack->top; // temp는 pStackNode형으로, 현재 Stack의 Top 노드의 주소할당

    if (IsEmptyStack(pStack)) // Stack이 비어있으면 반환.
    {
        printf("STACK Stat : NULL\n");        return;
    }
    else // 아니면 스택멤버 조회
    {
        printf("STACK Stat : ");
        for (int i = 0; i < pStack->count; i++) // 스택 멤버의 총 수까지 반복.
        {
            printf("%s ", temp->data); //현재 노드의 데이터 출력
            temp = temp->next; // temp에 다음 노드의 주소 할당.
        }
        printf("(%d)\n", pStack->count);
    }
}

//Convert 10 to 12
char* decToduo(int decimal) // 10진수 입력
{
    char* duodeci[100] = { 0, };  // 최대 100가지의 문자열을 가리키는 주소를 담는 포인터 배열 선언
    char* result = (char*)calloc(100, sizeof(char)); //calloc(크기, 사이즈타입) : 할당과 동시에 초기화 해줌, result : 12진수 출력 문자열.
    int index = 0;//duodeci 참조 인덱스

    Stack* convertStack = CreateStack(1000); // 변환을 위한 스택 할당. // linked 타입에서 사이즈 X

    do {
        duodeci[index] = (char*)malloc(sizeof(char) * 3); //문자열 배열 주소마다 메모리 동적할당
        duodeci[index] != NULL ? sprintf(duodeci[index], "%d", decimal % 12) : free(duodeci[index]);
        Push(convertStack, duodeci[index]);
        decimal = decimal / 12;
        index < 100 ? index++ : printf("\n evaluation error\n");
    } while (decimal != 0);

    while (IsEmptyStack(convertStack) == false)
    {
        if (result == NULL) break;
        else {
            switch (atoi(Top(convertStack)))
            {
            case 11:
                strcat(result, "B");     Pop(convertStack);                break;
            case 10:
                strcat(result, "A");    Pop(convertStack);                break;
            default:
                strcat(result, Pop(convertStack));                break;
            }
        }
    }

    DestroyStack(convertStack);    convertStack = NULL; // Stack 메모리 동적할당 해제
    for (int i = 0; i < index; i++)
    {
        free(duodeci[i]); // 저장한 문자열 포인터에서 동적할당 해제
    } 
    return result;
}

//Convert 12 to 10
int duoTodec(char* duodecimal) //doudecimal은 문자열 주소를 가리킨다.
{
    /*
    char temp[3] = { 0, };
    int decimal = 0; 
     // index에는 duodecimal의 길이의 -1만큼 해줘서 자릿수 맞추자.  
     //배열의 좌측부터 숫자가 순서대로 들어가므로 들어오는 숫자 그대로 판단해도 된다. // 그림 한 번 그려볼 것.
    for (int index =0 ; index <= strlen(duodecimal) - 1; index++)
    {   
        decimal *= 12; // 12*n +12*n-1 .... 12*1 하는 구조 // for문 안에 들어오면 자릿수가 하나 증가한다는 의미이므로 *12를 해준다.
        if (duodecimal [index] == 'A') // 이렇게 인덱스로 접근하거나, 
        {
            temp[0] = '1'; temp[1] = '0'; //temp는 배열이므로 인덱스 하나씩 넣기.
        }
        else if (*(duodecimal + index) == 'B') // 포인터 연산을 통해 하나씩 접근해야한다. 
        {
            temp[0] = '1'; temp[1] = '1';
        }
        else {
            temp[0] = *(duodecimal + index);            
            temp[1] = '\0'; // 앞의 연산에서 필요없는 값이 들어있을 수도 있으니 반드시 '\0'해주자.
        }
        temp[2] = '\0'; //마천가지
        decimal += atoi(temp); // decimal에 자기자신 더하기. // pow를 사용해서 이부분에 거듭제곱으로 나태내도 됨.
    }
    */
    //temp 없이
    int decimal = 0;   //배열의 좌측부터 숫자가 순서대로 들어가므로 들어오는 숫자 그대로 판단해도 된다. // 그림 한 번 그려볼 것. 
    char temp[2] = { 0, };
    for (int index = 0; index <strlen(duodecimal) ; index++)
    {
        decimal *= 12; // 12*n +12*n-1 .... 12*1 하는 구조 // for문 안에 들어오면 자릿수가 하나 증가한다는 의미이므로 *12를 해준다.
        if (duodecimal[index] == 'A')       decimal +=10;  // 이렇게 인덱스로 접근하거나, 
        else if (*(duodecimal + index) == 'B')   decimal +=11;  // 포인터 연산을 통해 하나씩 접근해야한다.       
        else     
        {   temp[0] = *(duodecimal + index);             decimal += atoi(temp);    }
    }
    return decimal;
}

int main()
{
    int sel = 0, selchk = START, inputChk = 0, decimal = 0;
    char* temp;
    Stack* pStorageStack = CreateStack(1000);

    while (selchk)
    {
        printf("Push(0), Pop(1), Exit(2) : ");

        if (!scanf(" %d", &sel)) {
            printf("input error, program terminates"); break;
        }

        switch (sel)
        {
        case 0:
            printf("Push : ");

            inputChk = scanf(" %d", &decimal);
            if (inputChk != 1) {
                printf("input Error : check your input \n\n");                             break;
            }
            else if (decimal >= 2147483648)
            {
                printf("wrong input number : input range is 0 to 2147483647 \n"); break;
            }
            Push(pStorageStack, decToduo(decimal));
            ViewStackMember(pStorageStack);
            printf("\n");
            break;

        case 1:
            printf("Pop : ");
            if (IsEmptyStack(pStorageStack))
            {
                printf("Stack is Empty. \n\n"); break;
            }
            temp = Pop(pStorageStack);
            printf("%d (%s) \n", duoTodec(temp), temp);            free(temp); // 문자열 POP이후 동적할당 해제
            ViewStackMember(pStorageStack);
            printf("\n");
            break;

        case 2:
            printf("Program terminates\n ");
            selchk = END;            break;

        default:
            printf("Check your input : select 0 or 1 or 1 \n\n");         break;
        }
    }

    DestroyStack(pStorageStack);
    pStorageStack = NULL;
    return 0;
}