#include <stdio.h>
int main()
{
   int arr1[4][4];
   int arr2[4][4][4];
   int i,j,k,max;

   for (i = 0; i < 4; i++)
   {
      
      scanf("%d %d %d %d ", &arr1[i][0], &arr1[i][1], &arr1[i][2], &arr1[i][3]);
      printf("\n");
   }
   
      for (i = 0; i < 3; i++)
      {
         for (j = 0; j < 3; j++)
         {
            arr2[0][i][j]=arr1[i][j] * arr1[i][j + 1];//행
         }
      }
      for (j = 0; j < 3; j++)
      {
         for (i = 0; i < 3; i++)
         {
            arr2[1][i][j] = arr1[i][j] * arr1[i+1][j];//열
         }
      }
      for (i = 0; i < 3; i++)
      {
         for (j = 0; j < 3; j++)
         {
            arr2[2][i][j] = arr1[i][j + 1] * arr1[i + 1][j];//왼쪽 부터 인 대각선
         }
      }

      for (i = 0; i <3; i++)
      {
         for (j = 0; j < 3; j++)
         {
            arr2[3][i][j] = arr1[i][j + 1] * arr1[i + 1][j];//오른쪽 부터 인 대각선
         }
      }
      for (k = 0; k < 4; k++)
      {
         for (i = 0; i < 4; i++)
         {
            for (j = 0; j < 4; j++)
            {
               printf("%d     ", arr2[k][i][j]);

                  max = arr2[k][i][j];
               
            }
         }
         printf("\n");
      }
      printf("max값: %d", max);
      return 0;
}
