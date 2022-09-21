#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   //Matrix();
   // pointer_malloc_1st_dim();
   //pointer_malloc_2st_dim();
  
   //지뢰찾기
    //자료형 잘 맞춥시다//ㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜ
    int m, n;

    scanf("%d %d", &m, &n); // 입력
    n = n + 1;
    // null 공간 확보를 위한 +1
    char** matrix = malloc(sizeof(int*) * m); // 행렬 가로 할당
    for (int i = 0; i <m; i++)
    {
        matrix[i] = malloc(sizeof(int) * n);
        memset(matrix[i], 0, sizeof(int) * n);
    }

    n = n - 1;
    
    //-- 문자열 입력
    for (int i = 0; i < m; i++)
    {
        scanf("%s", matrix[i]);
    }

    
    /*
    //-- 문자열  출력
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("문자판별\n");
    printf("\n\n");
    */
    


    
    //--문자판별
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            if (matrix[i][j] == '*')
            {
                printf("*");
                continue;
            }
            else
            {
                matrix[i][j] = 0;

                for (int y = i - 1; y <= i + 1; y++) // 한 칸 위부터 한 칸 아래까지 반복
                {
                    for (int x = j - 1; x <= j + 1; x++) // 한 칸 앞(왼쪽)부터 한 칸 뒤(오른쪽)까지 반복
                    {
                        if ((y < 0 || x < 0 || y >= m || x >= n))
                        {
                            continue;
                        }
                        else if (matrix[y][x] == '*')
                        {
                            cnt = cnt +1;
                        }
                    }
                }
            }
            printf("%d",cnt);
            matrix[i][j] = cnt;
        }
        printf("\n");
    }


    for (int i = 0; i < m; i++)    // 메모리 해제: 세로 크기만큼 반복
    {
        free(matrix[i]);                  // 2차원 배열의 가로 공간 메모리 해제
    }
  
    free(matrix);    // 2차원 배열의 세로 공간 메모리 해제

    return 0;

   
}