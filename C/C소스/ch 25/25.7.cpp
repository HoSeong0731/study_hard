#include <stdio.h> 	//ǥ�� ����� �������
#include <stdlib.h> //ǥ�� �޸𸮶��̺귯��

int * ReadNum(int * arr, int arrlen, int idx) //�Է¹޴� �Լ�  
{
   printf("���� �Է�: "); 	
   scanf("%d", &arr[idx]); 	
   return arr; //arr�� �� ��ȯ
}

int main(void) //main�Լ�
{
   int arrlen = 5; 
   int idx = 0; 
   int i; 
   int * arr = (int*)malloc(sizeof(int)*arrlen); //4*arrlen����Ʈ�� �� ������ �Ҵ�

   while (1) //���ѹݺ���
   {
      arr = ReadNum(arr, arrlen, idx); 	//ReadNum�Լ� ȣ���� ���� arr �Է¹ޱ�
      if (arr[idx] == -1) 				//arr[idx]�� -1�̸�
         break; 						//���ѹݺ��� ����������

      if (arrlen == idx + 1)//arrlen�� idx+1�� ������
      {
         arrlen += 3; 		//arrlen�� 3 ���ϱ�(3����Ʈ �ø���)
         arr = (int *)realloc(arr, sizeof(int)*arrlen); //�ٽ� 4*arrlen����Ʈ�� �� ������ �Ҵ�
      }
      idx++; //idx�� 1 ���ϱ�
   }
   for (i = 0; i < idx; i++)	//i=0���� i<idx�� ������ idx�� �ݺ�
      printf("%d ", arr[i]);	//arr[i] ���
   free(arr); 					//�Ҵ�� �޸� ���� ����
   return 0; //main�Լ� ����
}
