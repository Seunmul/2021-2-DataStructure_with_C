#define _CRT_SECURE_NO_WARNINGS
#include "Stack_Link.h"

#define START 1 // ��ũ�� ���
#define END 0

//���� ������ ��� ����� ��ȸ
void ViewStackMember(Stack* pStack)
{
    StackNode* temp = pStack->top; // temp�� pStackNode������, ���� Stack�� Top ����� �ּ��Ҵ�

    if (IsEmptyStack(pStack)) // Stack�� ��������� ��ȯ.
    {
        printf("STACK Stat : NULL\n");        return;
    }
    else // �ƴϸ� ���ø�� ��ȸ
    {
        printf("STACK Stat : ");
        for (int i = 0; i < pStack->count; i++) // ���� ����� �� ������ �ݺ�.
        {
            printf("%s ", temp->data); //���� ����� ������ ���
            temp = temp->next; // temp�� ���� ����� �ּ� �Ҵ�.
        }
        printf("(%d)\n", pStack->count);
    }
}

//Convert 10 to 12
char* decToduo(int decimal) // 10���� �Է�
{
    char* duodeci[100] = { 0, };  // �ִ� 100������ ���ڿ��� ����Ű�� �ּҸ� ��� ������ �迭 ����
    char* result = (char*)calloc(100, sizeof(char)); //calloc(ũ��, ������Ÿ��) : �Ҵ�� ���ÿ� �ʱ�ȭ ����, result : 12���� ��� ���ڿ�.
    int index = 0;//duodeci ���� �ε���

    Stack* convertStack = CreateStack(1000); // ��ȯ�� ���� ���� �Ҵ�. // linked Ÿ�Կ��� ������ X

    do {
        duodeci[index] = (char*)malloc(sizeof(char) * 3); //���ڿ� �迭 �ּҸ��� �޸� �����Ҵ�
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

    DestroyStack(convertStack);    convertStack = NULL; // Stack �޸� �����Ҵ� ����
    for (int i = 0; i < index; i++)
    {
        free(duodeci[i]); // ������ ���ڿ� �����Ϳ��� �����Ҵ� ����
    } 
    return result;
}

//Convert 12 to 10
int duoTodec(char* duodecimal) //doudecimal�� ���ڿ� �ּҸ� ����Ų��.
{
    /*
    char temp[3] = { 0, };
    int decimal = 0; 
     // index���� duodecimal�� ������ -1��ŭ ���༭ �ڸ��� ������.  
     //�迭�� �������� ���ڰ� ������� ���Ƿ� ������ ���� �״�� �Ǵ��ص� �ȴ�. // �׸� �� �� �׷��� ��.
    for (int index =0 ; index <= strlen(duodecimal) - 1; index++)
    {   
        decimal *= 12; // 12*n +12*n-1 .... 12*1 �ϴ� ���� // for�� �ȿ� ������ �ڸ����� �ϳ� �����Ѵٴ� �ǹ��̹Ƿ� *12�� ���ش�.
        if (duodecimal [index] == 'A') // �̷��� �ε����� �����ϰų�, 
        {
            temp[0] = '1'; temp[1] = '0'; //temp�� �迭�̹Ƿ� �ε��� �ϳ��� �ֱ�.
        }
        else if (*(duodecimal + index) == 'B') // ������ ������ ���� �ϳ��� �����ؾ��Ѵ�. 
        {
            temp[0] = '1'; temp[1] = '1';
        }
        else {
            temp[0] = *(duodecimal + index);            
            temp[1] = '\0'; // ���� ���꿡�� �ʿ���� ���� ������� ���� ������ �ݵ�� '\0'������.
        }
        temp[2] = '\0'; //��õ����
        decimal += atoi(temp); // decimal�� �ڱ��ڽ� ���ϱ�. // pow�� ����ؼ� �̺κп� �ŵ��������� ���³��� ��.
    }
    */
    //temp ����
    int decimal = 0;   //�迭�� �������� ���ڰ� ������� ���Ƿ� ������ ���� �״�� �Ǵ��ص� �ȴ�. // �׸� �� �� �׷��� ��. 
    char temp[2] = { 0, };
    for (int index = 0; index <strlen(duodecimal) ; index++)
    {
        decimal *= 12; // 12*n +12*n-1 .... 12*1 �ϴ� ���� // for�� �ȿ� ������ �ڸ����� �ϳ� �����Ѵٴ� �ǹ��̹Ƿ� *12�� ���ش�.
        if (duodecimal[index] == 'A')       decimal +=10;  // �̷��� �ε����� �����ϰų�, 
        else if (*(duodecimal + index) == 'B')   decimal +=11;  // ������ ������ ���� �ϳ��� �����ؾ��Ѵ�.       
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
            printf("%d (%s) \n", duoTodec(temp), temp);            free(temp); // ���ڿ� POP���� �����Ҵ� ����
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