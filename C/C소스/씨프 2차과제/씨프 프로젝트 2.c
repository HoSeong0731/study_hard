//�����̵� ��Ʈ Ŭ�ι� ���̾� S H C D A~2 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 100000	//MAX_COLS �� 100000�̶�� ���� ����  

typedef struct card {	//ī�� �п� ���� ����ü �Ŀ� ������ ���� �����鵵 ����ȭ��Ŵ  
   char player[11];
   int number[5];
   char shape[5];
   int straight, flush, result, high_shape;
}CARD;

void mapping(char *c);                  	      //16������ �� �Ҵ� �Լ� 
void sort(char *shape, int *number);       		  //���� ���� �������� �����Լ� 
int high_shape(char shape[5]);             		  //���� ���� ī���� ����  
int straight_check(int num[]);            	  	  //��Ʈ����Ʈ ���� �Լ� 
int flush_check(char color[]);              	  //�÷��� ���� �Լ� 
int calculation(int col, int li, char card[11]);  //����Լ�  
void re_mapping(char * c);						  //16������ �Ҵ��� �� 10, J, Q, K, A�� ��ȯ�ϴ� �Լ� 
void final_print(int result, int num1, int num2); //���� ���  
//�Լ�������� �����Լ����� ������. 

int main()
{
   FILE *f;				//���� ����
   CARD teamA, teamB;	//����ü ���� ����
   teamA.player == (char*)calloc(11,sizeof(char));	//���� �Ҵ�
   teamB.player == (char*)calloc(11,sizeof(char));	//���� �Ҵ�
   int select = 0;		//��ȣ�� ���� ���� ����
   int game_number = 0;	//��ȣ�� ���� ���� ����
   int result = 0;		//���� ��� �� A�� �̱�� 1 B�� �̱�� 2��� ���� ����. 
   int num1 = 0, num2 = 0, num3 = -1;	//select�� ���ǿ� �°� ����ϱ� ���� ����
   int i, j = 0,k=0;
   int asd = 0;
   char s[4][MAX_COLS];

   while (1)
   {
      select = 0;
      game_number = 0;
      printf("--------------------------------------------------------------\n");
      printf("1.   Print all Game result\n");
      printf("2.   Print Game(number)\n");
      printf("3.   Delete Game(number)\n");
      printf("4.   Exit\n");
      printf("--------------------------------------------------------------\n");
      printf("Select option::");
      scanf_s("%d", &select);
      if (select == 2 || select == 3)	//select�� 2 �Ǵ� 3�϶��� 
         scanf_s("%d", &game_number);
      else if (select == 4){			//4�϶� ���ѹݺ� Ż��
      	 printf("�����Ҵ��� �޸� ������ ���� �մϴ�.");
      	 fclose(teamA.player);
      	 fclose(teamB.player);
         break;
	  }
      	 
      else if (select != 1 && select != 2 && select != 3 && select != 4)	 //�ٸ� �� �Է½� ���α׷� ����  
         break;
      fopen_s(&f, "input2.txt", "rt");	//�ؽ�Ʈ ������ �б���� ���� 
      for (k = 0; k < 4; k++)			//s�迭�� ����� �Ѱ��� �����Ѵ�
         fgets(s[k], MAX_COLS, f);
      for (k = 0; k < 4; k++)
      {
         if (select == 3)				//3�� ��� ����
         {
            num3 = game_number - 1;		//num3���� game_number�Է� �����ſ��� �ϳ� ���� ���� �����Ѵ�.
            num2 = 2;
            asd = 1;					//3�� �����ߴٴ� ���� ǥ�����ش�.
         }
         else if (select == 2)			//2�� ���� �ߴٴ� ���� ǥ���Ѵ�.
         {
            num2 = 1;
            k = game_number - 1;		//game_number�Է� ���� �Ϳ��� 1 ���� ���� �����Ѵ�.
         }

         if (select == 2 && (k >= num3) && asd == 1)	//3���� num3�Է� ���� ���� k���� ���ų� Ŭ �� ����
            k++;						//�ϳ� �������� �ڿ��ִ� ���� �޾ƿ´�
         if (select == 1)
            num2 = 0;					//1�� ���õǸ� �ʱ�ȭ�Ѵ�.
         
         if (k != num3)					//num3�� k���� ���ٸ� �������� �ʴ´�
         {
            teamA.player[10] = '\0';
            teamB.player[10] = '\0';
            memcpy(teamA.player, s[k], sizeof(char) * 10);		//player�� �ý�Ʈ 10���� �����Ѵ�.
            memcpy(teamB.player, s[k] + 10, sizeof(char) * 10);	//player�� �ý�Ʈ 10���� �����ϴµ� ���� �ͺ��� 10�տ� �ִ� ���� �����Ѵ�.

            for (i = 0; i < 10; i = i + 2)	//���ڿ� ����� ������ ���� �ݺ���
            {
               teamA.shape[j] = teamA.player[i + 1];	//����� �����Ѵ�.
               teamA.number[j] = teamA.player[i];		//���ڸ� �����Ѵ�.
               j++;	//player���� 1,3,5...Ȧ ������ ����� ¦������ ���ڰ� ����Ǿ� �ְ� �װ��� 5�� ������ �ޱ� ����
            }
            j = 0;	//�ٸ� ���� �ޱ� ���� �ʱ�ȭ
            for (i = 0; i < 10; i = i + 2)	//���ڿ� ����� ������ ���� �ݺ���
            {
               teamB.shape[j] = teamB.player[i + 1];	//����� �����Ѵ�
               teamB.number[j] = teamB.player[i];		//���ڸ� �����Ѵ�.
               j++;	//player���� 1,3,5...Ȧ ������ ����� ¦������ ���ڰ� ����Ǿ� �ְ� �װ��� 5�� ������ �ޱ� ����
            }
            mapping(teamA.player);	//mapping�Լ� ����
            mapping(teamB.player);	//mapping�Լ� ����
            sort(&teamA.shape, &teamA.number);	//���� �Լ� ����
            sort(&teamB.shape, &teamB.number);	//���� �Լ� ����
            teamA.straight = straight_check(&teamA.number);	//��Ʈ����Ʈ ����Ȯ��
            teamB.straight = straight_check(&teamB.number);	//��Ʈ����Ʈ ����Ȯ��
            teamA.flush = flush_check(&teamA.shape);		//�÷��� ����Ȯ��
            teamB.flush = flush_check(&teamB.shape);		//�÷��� ����Ȯ��
            teamA.high_shape = high_shape(teamA.shape);		//���� ����ī���� ���Ȯ��
            teamB.high_shape = high_shape(teamB.shape);		//���� ����ī���� ���Ȯ��
            teamA.result = calculation(teamA.flush, teamA.straight, teamA.player);	//���� ���� ����
            teamB.result = calculation(teamB.flush, teamB.straight, teamB.player);	//���� ���� ����
            re_mapping(&teamA.player);	//16������ �Ҵ��� �� 10, J, Q, K, A�� ��ȯ�ϴ� �Լ�
            re_mapping(&teamB.player);	//16������ �Ҵ��� �� 10, J, Q, K, A�� ��ȯ�ϴ� �Լ�
            if (select == 3)	//���õ� select�� 3�̸� Ż�� 
               break;
            else if (select == 2)	//# �ٽ� #�� �ּ��� ������ ������ ���� � �з� �̰���� ���ϴ� ����
               printf("teamA:%s\nteamB:%s\n", teamA.player, teamB.player);
            if (teamA.result > teamB.result)
            {
               result = 1;
               final_print(result, teamA.result, num2);
            }
            else if (teamA.result < teamB.result)
            {
               result = 2;
               final_print(result, teamB.result, num2);
            }
            else
            {
               if (teamA.high_shape > teamB.high_shape)
               {
                  result = 1;
                  final_print(result, teamA.result, num2);
               }
               else
               {
                  result = 2;
                  final_print(result, teamB.result, num2);
               }	
            }	//#
            if (select == 2)
            {
               num2 = 0;	//�ʱ�ȭ�Ѵ�.
               break;		//Ż��
            }
         }
      }
      fclose(f);	//�ݺ��� ���� �� fclose�� f �޸� ���� ����

   }
   return 0;
}



void mapping(char * c) {	//A, K, Q, J, 10�� 16���� E, D, C, B, A�� �ٲ��ش�. 
   int i = 0;
   for (i = 0; i < 5; i++)
   {
      if (c[2 * i] == 'A')
         c[2 * i] = '0xE';
      else if (c[2 * i] == 'K')
         c[2 * i] = '0xD';
      else if (c[2 * i] == 'Q')
         c[2 * i] = '0xC';
      else if (c[2 * i] == 'J')
         c[2 * i] = '0xB';
      else if (c[2 * i] == '0')
         c[2 * i] = '0xA';
      else;
   }
}

void re_mapping(char *c ) {	//mapping�Լ����� 16������ ��ȯ�� �� �ٽ� �ٲ۴�.
   int i = 0;
   for (i = 0; i < 5; i++)
   {
      if (c[2 * i] == 'E')
         c[2 * i] = 'A';
      else if (c[2 * i] == 'D')
         c[2 * i] = 'K';
      else if (c[2 * i] == 'C')
         c[2 * i] = 'A';
      else if (c[2 * i] == 'B')
         c[2 * i] = 'J';
      else if (c[2 * i] == 'A')
         c[2 * i] = 'T';
      else;
   }
}

void sort(char *shape, int *number)	 //���ڸ� �������� �������� �����Ѵ�.(�Ŀ� ��� ����� ����)
{
   int aa, i, j;
   char bb;
   for (i = 0; i < 4; i++) //�������� ���ڿ� �°� 
   {
      for (j = i + 1; j < 5; j++)
      {
         if (number[i] > number[j])
         {
            aa = number[i];			 //ī�� ���ڿ�
            number[i] = number[j];
            number[j] = aa;

            bb = shape[i];			//ī�� ������ ���� �����δ�.
            shape[i] = shape[j];
            shape[j] = bb;
         }
      }
   }
}

int high_shape(char shape[5])	//���� ���� ���� ���� ������� ����Ǿ� ����� ���Ѵ�.
{
   if (shape[5] = 'S')
   {
      return 4;
   }
   else if (shape = 'H')
   {
      return 3;
   }
   else if (shape = 'C')
   {
      return 2;
   }
   else {
      return 1;
   }

}

int straight_check(int num[])	//���ĵǾ� �ִ� �����̹Ƿ� +1�� �ϸ鼭 ��Ʈ����Ʈ�� ������ Ȯ���Ѵ�.
{
   int i;
   int c = 1;
   for (i = 0; i < 4; i++) //���ڰ� �������ΰ�? 
   {
      if (num[i] + 1 != num[i + 1])
         if (num[i + 1] == 14 && num[i] == 5)
            c++;
         else
            break;
      c++;
   }
}

int flush_check(char color[])	//color�� �� �Ȱ��� ������ �÷����� �������� �ʴ´�.
{
   int i, c = 1;

   for (i = 1; i < 5; i++)
   {
      if (color[0] != color[i])
         break;
      c++;
   }

   return c;
}

int calculation(int col, int li, char card[11])
//��Ʈ����Ʈ, �÷�������� �͵� �Ű������� ���� ���� ������ ���ڷ� ���Ѵ�.
{
   if (col == 5 && li == 5) //1. ī�� 5���� ��� ���� ���̸鼭 ���ڰ� �������� �� 
      if (card[8] == 14) {	//��Ƽ��
         return 1000 + card[8];
      }
      else {	//��Ƽ��
         return 900 + card[8];
      }
   else if (col == 5) //4. ī�� 5���� ��� ���� ���� �� (�÷���)
      return 600 + card[8];

   else if (li == 5) //5. ī�� 5���� ���ڰ� �������� �� (��Ʈ����Ʈ)
      return 500 + card[8];

   else
   {
      int num = 1;
      int num2 = 1;
      int plus = 0;
      int count = 0;
      int i, j;

      for (i = 0; i < 4; i++)	//�� �� �˻��ߴ� ��츦 ��ġ�� �ʰ� �˻��ϰ� ��� ������ �˻��ϴ� �˰���
      {
         for (j = 0; j < 4 - i; j++)
         {
            if (card[2 * i] == card[2 + (2 * j) + (2 * i)])
            {
               count++;
               plus = card[2 + (2 * j) + (2 * i)];
            }
         }
      }
      if (count == 4)	//��ī��� Ǯ�Ͽ콺�� ���Ļ��±��� 4������ ī��Ʈ�� ����
      {
         if (card[2] == card[6])
         {   //��ī��  
            num = 4;
            plus = card[4];
         }
         else
         {
            num = 3;         //Ǯ �Ͽ콺  
            num2 = 2;
            plus = card[4];
         }
      }
      else if (count == 2)	//Ʈ������ ���ı��� 3�� �������� ������ ���ܰ� �־� ī��Ʈ3�� 2�� �����־���.
      {
         if (card[0] == card[2] && card[0] == card[4])
         {//Ʈ����  
            num = 3;
            num2 = 1;
            plus = card[4];
         }
         else if (card[2] == card[4] && card[2] == card[6])
         {//Ʈ����  
            num = 3;
            num2 = 1;
            plus = card[4];
         }
         else if (card[4] == card[6] && card[4] == card[8])
         {//Ʈ����  
            num = 3;
            num2 = 1;
            plus = card[4];
         }
         else
         {//�����  
            num = 2;
            num2 = 2;
            plus = card[6];
         }
      }
      else if (count == 1)	//�����  
      {
         num = 2;
         num2 = 1;
      }
      else	//ž  
      {
         num = 1;
         plus = card[8];
      }

      if (num == 4) //2. ī�� 4���� ���ڰ� ���� �� 
         return 800 + plus;

      else if (num == 3)
      {
         if (num2 == 2) //3. ī�� 3���� ���ڰ� ���� ������ 2�嵵 ���ڰ� ���� �� 
            return 700 + plus;

         else //6. ī�� 3���� ���ڰ� ���� �� 
            return 400 + plus;
      }

      else if (num == 2)
      {
         if (num2 == 2) //7. ī�� 2���� ���ڰ� ���� �� �ٸ� 2���� ���ڰ� ���� �� 
            return 300 + plus;

         else //8. ī�� 2���� ���ڰ� ���� �� 
            return 200 + plus;
      }
      else //� ��쵵 �ش����� ���� �� 
         return 100 + plus;

   }
}

void final_print(int result, int num1, int num2)
//result�� ���� ���� �̰���� � ī��� �̰����. 
{
   if (result == 1)
   {
      if (num2 == 0)	//select =1�϶� ���
         printf("Team A wins \n");
      else
      {// num1�� calculation�Լ����� ��ȯ���� ��. 
         if (num1 / 100 == 10)
            printf("�ξ� ��Ʈ����Ʈ �÷����� A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 9)
            printf("��Ʈ����Ʈ �÷����� A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 8)
            printf("��ī��� A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 7)
            printf("Ǯ�Ͽ콺�� A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 6)
            printf("�÷����� A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 5)
            printf("��Ʈ����Ʈ�� A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 4)
            printf("Ʈ���÷� A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 3)
            printf("������ A�� �̰���ϴ�.\n");
         else if (num1 / 100 == 2)
            printf("������ A�� �̰���ϴ�.\n");
         else
            printf("ž���� A�� �̰���ϴ�.\n");
      }
   }
   else	
   {
      if (num2 == 0)	//select =1�϶� ���
         printf("Team B wins \n");
      else
      {	// num1�� calculation�Լ����� ��ȯ���� ��.
         if (num1 / 100 == 10)
            printf("�ξ� ��Ʈ����Ʈ �÷����� B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 9)
            printf("��Ʈ����Ʈ �÷����� B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 8)
            printf("��ī��� B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 7)
            printf("Ǯ�Ͽ콺�� B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 6)
            printf("�÷����� B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 5)
            printf("��Ʈ����Ʈ�� B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 4)
            printf("Ʈ���÷� B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 3)
            printf("������ B�� �̰���ϴ�.\n");
         else if (num1 / 100 == 2)
            printf("������ B�� �̰���ϴ�.\n");
         else
            printf("ž���� B�� �̰���ϴ�.\n");
      }
   }
}

