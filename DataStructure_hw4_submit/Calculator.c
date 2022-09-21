#define _CRT_SECURE_NO_WARNINGS
#include "Stack_Array.h"
#include <string.h>

//Calculator.c
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
}//연산자 순서를 비교해서 op1>op2이면 1 같으면 0 op1<op2이면 -1 반환.

//parsing //string_input에 문자열 기입 //string_token에 토큰한 문자열 저장, //size: 한번에 저장할 수 있는 토큰 개수는 최대 64 //string_token의 인덱스 개수 반환.
int parsing(char* string_input, char* string_token[], int size, char* toToken)
{
    char* str = (char*)malloc(sizeof(char) * 1000);
    char* Arr[64] = { 0, };
    char* tok = 0;
    int cnt = 0;

    if (str) { str = strcpy(str, string_input); } // str에 인풋 문자열 복사(토큰)
    if (size > 64) { size = 64; } // 사이즈 최대 64로 조절

    tok = strtok(str, toToken); // ""사이에 토큰할 문자 기입
    Arr[0] = tok;
    //printf("%s\n", Arr[0]);

    for (int i = 1; tok != NULL; i++)
    {
        tok = strtok(NULL, toToken); // ""사이에 토큰할 문자 기입
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

//EraseBlank 문자열의 blank를 제거. //제거한 blank수 반환.
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

//Infix 형태의 수식을 Postfix형태로 변환
int infixToPostFix(char* Infix_input, char* toPostfix) {
    int max_size = 1000;
    Stack* pStack = CreateStack(max_size);   // Stack메모리 할당
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
                printf("\n - Error : 공백을 두고 연속으로 숫자가 입력되었습니다.\n"); return 0;
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
                printf("\n - Error : 연속으로 연산자가 입력되었습니다.  \n"); return 0;
            }
            operatorCnt++;
            //Operator 우선순위 고려할 것.
            if (IsEmptyStack(pStack)) //Stack이 빈 경우라면 그냥 Push
            {
                toPostfix[j++] = ' ';
                Push(pStack, Infix_input[i++]);
            }
            else // 아닌 경우라면 조건을 판단
            {
                switch (orderOpChk(Infix_input[i], Top(pStack)))
                {
                case 1: // 현재 입력된 연산자 우선순위가 높은 경우 -> 그냥 Push // (가 입력되더라도 연산자 우선순위가 높아 PUSH
                    toPostfix[j++] = ' ';
                    Push(pStack, Infix_input[i++]);
                    break;
                case 0: // 현재 입력된 연산자 우선순위가 같거나 낮은 경우 -> Pop & Push
                case -1:
                    if (Top(pStack) == '(') { toPostfix[j++] = ' '; Push(pStack, Infix_input[i++]); break; } // 만약 (가 입력되더라도 연산자 우선순위가 높아 PUSH
                    toPostfix[j++] = ' ';
                    toPostfix[j] = Pop(pStack);
                    //printf("\n%d번째 인덱스:%c\n", j, toPostfix[j]);
                    j++;
                    Push(pStack, Infix_input[i++]);
                    break;
                default:
                    printf("\nError - 연산자 우선순위를 판단하는 중 에러가 발생했습니다.\n");
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
                printf("\n Error - 닫는 괄호가 여는 괄호보다 개수가 많습니다.\n");
                return 0;
            }
            while (Top(pStack) != '(')
            {
                toPostfix[j++] = ' ';
                toPostfix[j++] = Pop(pStack);
                //printf("\n%d번째 인덱스:%c\n", j, toPostfix[j]);
                
            }
            Pop(pStack);
            i++;
        }
        else { printf("\n Error - 잘못된 입력입니다.\n"); return 0; }
    }
    if (parenthesisCnt > 0) {
        printf("\n Error - 여는 괄호가 닫는 괄호보다 개수가 많습니다.\n");
        return 0;
    }
    while (!IsEmptyStack(pStack))
    {
        toPostfix[j++] = ' ';
        toPostfix[j++] = Pop(pStack);
        //printf("\n%d번째 인덱스:%c\n", j, toPostfix[j]);
        
    }
    toPostfix[j] = '\0';
    printf("PostFix with Blank : %s\n", toPostfix);
    //
    DestroyStack(pStack);
    pStack = NULL;

    return 1;
}

//Postfix형태 계산, Postfix형태의 입력, 숫자를 받을 때 다른 숫자라면 띄워진 형태로 입력
int postFix_cal(char* Postfix_input)
{
    char* blankErased_input = (char*)malloc(sizeof(char) * 1000); //공백제거 수식 입력받을 문자열.
    char* integerToken_input[64] = { 0 , }; // 숫자만 저장할 문자열 token

    int t_size = 0, index = 0, tok_index = 0, op1 = 0, op2 = 0, opcnt = 0;
    int max_size = 1000;
    int result = 0;

    Stack* pStack = CreateStack(max_size);   // 계산결과 Stack메모리 할당

    blankErased_input ? memset(blankErased_input, 0, sizeof(char) * 1000) : NULL;

    //공백제거
    if (blankErased_input && Postfix_input) { blankErased_input = strcpy(blankErased_input, Postfix_input); }
    else { printf(" \n- Error : program terminates\n "); return 0; }
    printf("(%d blank Erased) PostFix: %s\n\n", EraseBlank(blankErased_input), blankErased_input);

    //숫자만 저장할 문자열 token   
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
    printf("Result : %d\n", result = Pop(pStack));
    DestroyStack(pStack);// 계산결과 Stack메모리 제거
    pStack = NULL;

    free(blankErased_input);
    return 1;

}

//Calculator.c
int main()
{
    //수식 입력부
    char* cal_input = (char*)malloc(sizeof(char) * 1000); //수식 입력받을 문자열.
    char* toPostfix = (char*)malloc(sizeof(char) * 1000); //Postfix형태로 저장할 문자열 동적할당
    toPostfix ? memset(toPostfix, 0, sizeof(char) * 1000) : NULL;
    cal_input ? memset(cal_input, 0, sizeof(char) * 1000) : NULL;
    int chk_input = 0;

    printf("Arithmetic Expression : ");
    chk_input = scanf("%[^\n]s", cal_input); //공백포함 수식 입력 받기
    if (chk_input != 1) {
        printf("입력오류");
        return 0;
    }
    else { printf("Input ( by Infix Notation ) : %s\n", cal_input); } //입력 확인

    //Infix ->Postfix 변환
    if (infixToPostFix(cal_input, toPostfix) == 0) { return 0; }
    // Postfix계산
    if (postFix_cal(toPostfix) == 0) { return 0; }
    //

    free(toPostfix);
    free(cal_input);

    return 0;
}