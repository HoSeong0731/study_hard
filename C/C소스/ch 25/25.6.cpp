#include <stdio.h> 	//ǥ�� ����� �������
#include <stdlib.h> //ǥ�� �޸𸮶��̺귯��
#include <string.h> //ǥ�� ���ڿ����̺귯��  

char * ReadString(int maxlen) //�Է¹޴� �Լ�  
{
   char * str = (char *)malloc(sizeof(char)*(maxlen + 1)); //4����Ʈ ũ���� ��� n���� �� ������ �Ҵ�
   printf("���ڿ� �Է�: ");
   fgets(str, maxlen + 1, stdin); //fgets�Լ��� ���� str �Է¹ޱ�
   return str; //�� ��ȯ
}

int main(void) //main�Լ�
{
   int maxlen, len, i; 	//int�� ���� ����
   char * str; 			//char�� ������ ���� str ����

   printf("���ڿ��� �ִ� ���� �Է�: "); 
   scanf("%d", &maxlen); 
   getchar(); 			//\n ���� �����

   str = ReadString(maxlen); 	//ReadString�Լ� ȣ���� ���� str �Է¹ޱ�

   str[strlen(str) - 1] = 0; 	//\n ���� �����
   len = strlen(str); 			//len�� strlen(str) ����
   for (i = len; i > 0; i--) 	//i=len���� i>0�� ������ i�� 1�� ���ҽ�Ű�鼭 len�� �ݺ�
      if (str[i] == ' ') 		//str[i]�� �����̸� ����
      {
         printf("%s ", &str[i + 1]); 	//str[i+1] ���
         str[i] = 0; 					//str[i]�� 0 ����
      }
   printf("%s", &str[0]); 	//str[0] ���
   free(str); 				//�Ҵ�� �޸� ���� ����
   return 0; 				//main�Լ� ����
}
