#define _CRT_SECURE_NO_WARNINGS
#include "Stack_List.h"
#include <string.h>

enum _operator {
    plus = '+',
    minus = '-',
    multi = '*',
    remainder = '%',
}operator;

enum _operand {
    zero = '0',
    one = '1', two = '2', three = '3', four = '4', five = '5', six = '6', sevnen = '7', eight = '8', nine = '9'
}operand;

bool IsOperand(char operand)
{
    if ((operand >= zero) && (operand <= nine))
    {
        return true;
    }
    else return false;
}

bool IsOperator(char op)
{
    switch (op)
    {
    case plus:
    case minus:
    case multi:
    case remainder:
    {
        return true;
        break;
    }
    default:
    {
        return false;
        break;
    }
    }
}

int orderOp(char op)
{
    int result = 0;
    switch (op)
    {
    case '(':
    case ')': result = 3; break;
    case '*':
    case '%': result = 2; break;
    case '+':
    case '-': result = 1;  break;
    default: break;
    }
    return result;
}

int orderOpChk(char op1, char op2)
{
    int a = orderOp(op1);
    int b = orderOp(op2);
    if (a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}//������ ������ ���ؼ� op1>op2�̸� 1 ������ 0 op1<op2�̸� -1 ��ȯ.

//parsing //string_input�� ���ڿ� ���� //string_token�� ��ū�� ���ڿ� ����, //size: �ѹ��� ������ �� �ִ� ��ū ������ �ִ� 64 //string_token�� �ε��� ���� ��ȯ.
int parsing(char* string_input, char* string_token[], int size, char* toToken)
{
    char* str = (char*)malloc(sizeof(char) * 1000);
    char* Arr[64] = { 0, };
    char* tok = 0;
    int cnt = 0;

    if (str) { str = strcpy(str, string_input); } // str�� ��ǲ ���ڿ� ����(��ū)
    if (size > 64) { size = 64; } // ������ �ִ� 64�� ����

    tok = strtok(str, toToken); // ""���̿� ��ū�� ���� ����
    Arr[0] = tok;
    //printf("%s\n", Arr[0]);

    for (int i = 1; tok != NULL; i++)
    {
        tok = strtok(NULL, toToken); // ""���̿� ��ū�� ���� ����
        Arr[i] = tok;
        //printf("%s\n", Arr[i]);
    }

    for (int i = 0; i < size - 1; i++)
    {
        string_token[i] = Arr[i];
        if (Arr[i] == NULL)
        {
            break;
        }
        cnt++;
    }
    string_token[cnt] = '\0';
    return cnt;
}

//EraseBlank ���ڿ��� blank�� ����. //������ blank�� ��ȯ.
int EraseBlank(char* cal)
{
    char ptr[30] = { 0, };
    int i = 0;
    int j = 0;
    int count = 0;
    while (cal[i] != '\0')
    {
        if (cal[i] != ' ')
        {
            //printf("%c", cal[i]);
            ptr[j] = cal[i];
            j++;
        }
        else
        {
            count++;
        }
        i++;
    }
    strcpy(cal, ptr);

    return count;
}

//Infix ������ ������ Postfix���·� ��ȯ
int infixToPostFix(char* Infix_input, char* toPostfix) {
    int max_size = 1000;
    Stack* pStack = CreateStack(max_size);   // Stack�޸� �Ҵ�
    int i = 0, j = 0, blankCnt = 0, operandCnt = 0, operatorCnt = 0, parenthesisCnt = 0;
    int order[256] = { 0, };

    while (Infix_input[i] != '\0')
    {
        //printf("%c", cal_input[i]);
        if (IsOperand(Infix_input[i]))
        {
            operatorCnt = 0;
            if (blankCnt >= 1 && operandCnt >= 1)
            {
                printf("\n - Error : ������ �ΰ� �������� ���ڰ� �ԷµǾ����ϴ�.\n"); return 0;
            }
            blankCnt = 0;
            operandCnt++;
            toPostfix[j++] = Infix_input[i++];
        }
        else if (Infix_input[i] == ' ')
        {
            blankCnt++;
            //operatorCnt = 0;
            //operandCnt = 0;
            i++;
        }
        else if (IsOperator(Infix_input[i]))
        {
            blankCnt = 0;
            operandCnt = 0;

            if (operatorCnt >= 1)
            {
                printf("\n - Error : �������� �����ڰ� �ԷµǾ����ϴ�.  \n"); return 0;
            }
            operatorCnt++;
            //Operator �켱���� ����� ��.
            if (IsEmptyStack(pStack)) //Stack�� �� ����� �׳� Push
            {
                toPostfix[j++] = ' ';
                Push(pStack, Infix_input[i++]);
            }
            else // �ƴ� ����� ������ �Ǵ�
            {
                switch (orderOpChk(Infix_input[i], Top(pStack)))
                {
                case 1: // ���� �Էµ� ������ �켱������ ���� ��� -> �׳� Push // (�� �ԷµǴ��� ������ �켱������ ���� PUSH
                    toPostfix[j++] = ' ';
                    Push(pStack, Infix_input[i++]);
                    break;
                case 0: // ���� �Էµ� ������ �켱������ ���ų� ���� ��� -> Pop & Push
                case -1:
                    if (Top(pStack) == '(') { toPostfix[j++] = ' '; Push(pStack, Infix_input[i++]); break; } // ���� (�� �ԷµǴ��� ������ �켱������ ���� PUSH
                    toPostfix[j++] = ' ';
                    toPostfix[j] = Pop(pStack);
                    //printf("\n%d��° �ε���:%c\n", j, toPostfix[j]);
                    j++;
                    Push(pStack, Infix_input[i++]);
                    break;
                default:
                    printf("\nError - ������ �켱������ �Ǵ��ϴ� �� ������ �߻��߽��ϴ�.\n");
                    return 0;
                }
            }
        }
        else if (Infix_input[i] == '(')
        {
            parenthesisCnt++;
            toPostfix[j++] = ' ';
            Push(pStack, Infix_input[i++]);
        }
        else if (Infix_input[i] == ')')
        {
            parenthesisCnt--;
            if (parenthesisCnt < 0) {
                printf("\n Error - �ݴ� ��ȣ�� ���� ��ȣ���� ������ �����ϴ�.\n");
                return 0;
            }
            while (Top(pStack) != '(')
            {
                toPostfix[j++] = ' ';
                toPostfix[j++] = Pop(pStack);
                //printf("\n%d��° �ε���:%c\n", j, toPostfix[j]);

            }
            Pop(pStack);
            i++;
        }
        else { printf("\n Error - �߸��� �Է��Դϴ�.\n"); return 0; }
    }
    if (parenthesisCnt > 0) {
        printf("\n Error - ���� ��ȣ�� �ݴ� ��ȣ���� ������ �����ϴ�.\n");
        return 0;
    }
    while (!IsEmptyStack(pStack))
    {
        toPostfix[j++] = ' ';
        toPostfix[j++] = Pop(pStack);
        //printf("\n%d��° �ε���:%c\n", j, toPostfix[j]);

    }
    toPostfix[j] = '\0';
    printf("PostFix with Blank : %s\n", toPostfix);
    //
    DestroyStack(pStack);
    pStack = NULL;

    return 1;
}

//Postfix���� ���, Postfix������ �Է�, ���ڸ� ���� �� �ٸ� ���ڶ�� ����� ���·� �Է�
int postFix_cal(char* Postfix_input)
{
    char* blankErased_input = (char*)malloc(sizeof(char) * 1000); //�������� ���� �Է¹��� ���ڿ�.
    char* integerToken_input[64] = { 0 , }; // ���ڸ� ������ ���ڿ� token

    int t_size = 0, index = 0, tok_index = 0, op1 = 0, op2 = 0, opcnt = 0;
    int max_size = 1000;
    int result = 0;

    Stack* pStack = CreateStack(max_size);   // ����� Stack�޸� �Ҵ�

    blankErased_input ? memset(blankErased_input, 0, sizeof(char) * 1000) : NULL;

    //��������
    if (blankErased_input && Postfix_input) { blankErased_input = strcpy(blankErased_input, Postfix_input); }
    else { printf(" \n- Error : program terminates\n "); return 0; }
    printf("(%d blank Erased) PostFix: %s\n\n", EraseBlank(blankErased_input), blankErased_input);

    //���ڸ� ������ ���ڿ� token   
    t_size = parsing(Postfix_input, integerToken_input, 64, " +-*%");
    if (t_size == 0)
    {
        printf("\n- Error : No operands to calculate. check your input of operator or operands\n"); return 0;
    }


    index = 0;
    while (blankErased_input[index] != '\0')
    {
        if (IsOperand(blankErased_input[index]))
        {
            Push(pStack, (integerToken_input[tok_index] ? atoi(integerToken_input[tok_index]) : 0));
            index = index + (int)(integerToken_input[tok_index] ? strlen(integerToken_input[tok_index]) : 0);
            tok_index++;
        }
        else {
            opcnt++;
            if (CountStackItem(pStack) >= 2)
            {
                op2 = Pop(pStack);   op1 = Pop(pStack);
            }
            else if (t_size == 1 && opcnt == 0)
            {
                Push(pStack, (integerToken_input[tok_index] ? atoi(integerToken_input[tok_index]) : 0)); break;
            }
            else { printf("\n- Error : No operands to calculate. check your input of operator or operands\n"); return 0; }

            switch (blankErased_input[index])
            {
            case plus: {Push(pStack, (op1 + op2)); break; }
            case minus: {Push(pStack, (op1 - op2)); break; }
            case multi: {Push(pStack, (op1 * op2)); break; }
            case remainder: {Push(pStack, (op1 % op2)); break; }
            default: {printf("\n- Error : wrong operator. program terminates\n"); return 0; }
            }
            index++;
        }
    }
    printf("result : %d\n", result = Pop(pStack));
    DestroyStack(pStack);// ����� Stack�޸� ����
    pStack = NULL;

    free(blankErased_input);
    return result;

}

int main()
{
    //���� �Էº�
    char* cal_input = (char*)malloc(sizeof(char) * 1000); //���� �Է¹��� ���ڿ�.
    char* toPostfix = (char*)malloc(sizeof(char) * 1000); //Postfix���·� ������ ���ڿ� �����Ҵ�
    toPostfix ? memset(toPostfix, 0, sizeof(char) * 1000) : NULL;
    cal_input ? memset(cal_input, 0, sizeof(char) * 1000) : NULL;
    int chk_input = 0;

    printf("Arithmetic Expression : ");
    chk_input = scanf("%[^\n]s", cal_input); //�������� ���� �Է� �ޱ�
    if (chk_input != 1) {
        printf("�Է¿���");
        return 0;
    }
    else { printf("Input ( by Infix Notation ) : %s\n", cal_input); } //�Է� Ȯ��

    //Infix ->Postfix ��ȯ
    if (infixToPostFix(cal_input, toPostfix) == 0) { return 0; }
    // Postfix���
    if (postFix_cal(toPostfix) == 0) { return 0; }
    //

    free(toPostfix);
    free(cal_input);

    return 0;
}