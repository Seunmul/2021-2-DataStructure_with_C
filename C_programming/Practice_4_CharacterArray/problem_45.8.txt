#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /*the grown - ups' response, this time, was to advise me to lay aside my drawings of boa constrictors, 
    whether from the inside or the outside, and devote myself instead to geography, history, arithmetic, 
    and grammar. That is why, at the age of six, I gave up what might have been a magnificent career as a painter. 
    I had been disheartened by the failure of my Drawing Number One and my Drawing Number Two. Grown-ups never 
    understand anything by themselves, and it is tiresome for children to be always and forever explaining things to the.*/
    char *s1=malloc(sizeof(char)*1001);
    scanf("%[^\n]s",s1);


    char* tok=strtok(s1," ,.");
    int cnt = 0;

    while(tok !=NULL)
    {
       
        if (tok != NULL && strcmp(tok, "the") == 0) // 자른 문자열을 the와 비교, 단, NULL이면 안됨.NULL일 경우 strcmp함수 사용 시 에러
            cnt++;
        tok = strtok(NULL, " ,.");
    }
    printf("%d", cnt);
    return 0;
}