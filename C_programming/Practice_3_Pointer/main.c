#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   //Matrix();
   // pointer_malloc_1st_dim();
   //pointer_malloc_2st_dim();
  
   //����ã��
    //�ڷ��� �� ����ô�//�̤̤̤̤̤̤̤̤̤̤̤̤̤̤�
    int m, n;

    scanf("%d %d", &m, &n); // �Է�
    n = n + 1;
    // null ���� Ȯ���� ���� +1
    char** matrix = malloc(sizeof(int*) * m); // ��� ���� �Ҵ�
    for (int i = 0; i <m; i++)
    {
        matrix[i] = malloc(sizeof(int) * n);
        memset(matrix[i], 0, sizeof(int) * n);
    }

    n = n - 1;
    
    //-- ���ڿ� �Է�
    for (int i = 0; i < m; i++)
    {
        scanf("%s", matrix[i]);
    }

    
    /*
    //-- ���ڿ�  ���
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("�����Ǻ�\n");
    printf("\n\n");
    */
    


    
    //--�����Ǻ�
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

                for (int y = i - 1; y <= i + 1; y++) // �� ĭ ������ �� ĭ �Ʒ����� �ݺ�
                {
                    for (int x = j - 1; x <= j + 1; x++) // �� ĭ ��(����)���� �� ĭ ��(������)���� �ݺ�
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


    for (int i = 0; i < m; i++)    // �޸� ����: ���� ũ�⸸ŭ �ݺ�
    {
        free(matrix[i]);                  // 2���� �迭�� ���� ���� �޸� ����
    }
  
    free(matrix);    // 2���� �迭�� ���� ���� �޸� ����

    return 0;

   
}