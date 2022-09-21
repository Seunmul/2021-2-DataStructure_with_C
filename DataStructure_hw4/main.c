#define _CRT_SECURE_NO_WARNINGS
//#include "Stack_Array.h"
#include "Stack_List.h"

void Convert();
void Reverse();
void Calculator();

int main()
{
    int sel = 0;
    int chk=0,getchk = 0;
    printf("/.main\n");
    printf("1: Reverse.c\n");
    printf("2: Convert.c\n");
    printf("3: Calculator.c\n");
    printf("Choose the number of program: ");
    chk=scanf("%d", &sel);
    getchk=getchar();
    if (chk != 1)
    {
        printf("입력오류");
        return 0;
    }
    switch (sel)
    {
        printf("\n");
        case 1:
        {
            Reverse();           break;
        }
        case 2:
        {
            Convert();            break;
        }
        case 3:
        {
            Calculator();        break;
        }
        default:     break;
    }
    return 0;
}