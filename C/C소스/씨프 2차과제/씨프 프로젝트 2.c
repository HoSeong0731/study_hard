//스페이드 하트 클로버 다이아 S H C D A~2 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 100000	//MAX_COLS 는 100000이라는 수를 가짐  

typedef struct card {	//카드 패에 관한 구조체 후에 족보를 위한 정보들도 구조화시킴  
   char player[11];
   int number[5];
   char shape[5];
   int straight, flush, result, high_shape;
}CARD;

void mapping(char *c);                  	      //16진수로 값 할당 함수 
void sort(char *shape, int *number);       		  //숫자 기준 오름차순 정렬함수 
int high_shape(char shape[5]);             		  //가장 높은 카드의 문양  
int straight_check(int num[]);            	  	  //스트레이트 유무 함수 
int flush_check(char color[]);              	  //플러쉬 유무 함수 
int calculation(int col, int li, char card[11]);  //계산함수  
void re_mapping(char * c);						  //16진수로 할당한 값 10, J, Q, K, A로 변환하는 함수 
void final_print(int result, int num1, int num2); //최종 출력  
//함수순서대로 메인함수에서 진행함. 

int main()
{
   FILE *f;				//파일 선언
   CARD teamA, teamB;	//구조체 변수 선언
   teamA.player == (char*)calloc(11,sizeof(char));	//동적 할당
   teamB.player == (char*)calloc(11,sizeof(char));	//동적 할당
   int select = 0;		//번호를 받을 변수 선언
   int game_number = 0;	//번호를 받을 변수 선언
   int result = 0;		//족보 계산 후 A가 이기면 1 B가 이기면 2라는 값을 가짐. 
   int num1 = 0, num2 = 0, num3 = -1;	//select의 조건에 맞게 사용하기 위한 변수
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
      if (select == 2 || select == 3)	//select이 2 또는 3일때만 
         scanf_s("%d", &game_number);
      else if (select == 4){			//4일때 무한반복 탈출
      	 printf("동적할당한 메모리 영역을 해제 합니다.");
      	 fclose(teamA.player);
      	 fclose(teamB.player);
         break;
	  }
      	 
      else if (select != 1 && select != 2 && select != 3 && select != 4)	 //다른 값 입력시 프로그램 종료  
         break;
      fopen_s(&f, "input2.txt", "rt");	//텍스트 파일을 읽기모드로 개방 
      for (k = 0; k < 4; k++)			//s배열을 만들어 한개씩 저장한다
         fgets(s[k], MAX_COLS, f);
      for (k = 0; k < 4; k++)
      {
         if (select == 3)				//3일 경우 실행
         {
            num3 = game_number - 1;		//num3값을 game_number입력 받은거에서 하나 작은 값을 저장한다.
            num2 = 2;
            asd = 1;					//3을 선택했다는 것을 표시해준다.
         }
         else if (select == 2)			//2를 선택 했다는 것을 표시한다.
         {
            num2 = 1;
            k = game_number - 1;		//game_number입력 받은 것에서 1 작은 값을 저장한다.
         }

         if (select == 2 && (k >= num3) && asd == 1)	//3에서 num3입력 받은 값과 k값이 같거나 클 때 실행
            k++;						//하나 증가시켜 뒤에있는 값을 받아온다
         if (select == 1)
            num2 = 0;					//1이 선택되면 초기화한다.
         
         if (k != num3)					//num3과 k값이 같다면 실행하지 않는다
         {
            teamA.player[10] = '\0';
            teamB.player[10] = '\0';
            memcpy(teamA.player, s[k], sizeof(char) * 10);		//player에 택스트 10개만 저장한다.
            memcpy(teamB.player, s[k] + 10, sizeof(char) * 10);	//player에 택스트 10개를 저장하는데 위에 것보다 10앞에 있는 것을 저장한다.

            for (i = 0; i < 10; i = i + 2)	//숫자와 모양을 나누어 받을 반복문
            {
               teamA.shape[j] = teamA.player[i + 1];	//모양을 저장한다.
               teamA.number[j] = teamA.player[i];		//숫자를 저장한다.
               j++;	//player에는 1,3,5...홀 수에는 모양이 짝수에는 숫자가 저장되어 있고 그것을 5개 나누어 받기 위함
            }
            j = 0;	//다른 값도 받기 위해 초기화
            for (i = 0; i < 10; i = i + 2)	//숫자와 모양을 나누어 받을 반복문
            {
               teamB.shape[j] = teamB.player[i + 1];	//모양을 저장한다
               teamB.number[j] = teamB.player[i];		//숫자를 저장한다.
               j++;	//player에는 1,3,5...홀 수에는 모양이 짝수에는 숫자가 저장되어 있고 그것을 5개 나누어 받기 위함
            }
            mapping(teamA.player);	//mapping함수 실행
            mapping(teamB.player);	//mapping함수 실행
            sort(&teamA.shape, &teamA.number);	//정렬 함수 실행
            sort(&teamB.shape, &teamB.number);	//정렬 함수 실행
            teamA.straight = straight_check(&teamA.number);	//스트레이트 유무확인
            teamB.straight = straight_check(&teamB.number);	//스트레이트 유무확인
            teamA.flush = flush_check(&teamA.shape);		//플러쉬 유무확인
            teamB.flush = flush_check(&teamB.shape);		//플러쉬 유무확인
            teamA.high_shape = high_shape(teamA.shape);		//패의 메인카드의 모양확인
            teamB.high_shape = high_shape(teamB.shape);		//패의 메인카드의 모양확인
            teamA.result = calculation(teamA.flush, teamA.straight, teamA.player);	//족보 최종 결정
            teamB.result = calculation(teamB.flush, teamB.straight, teamB.player);	//족보 최종 결정
            re_mapping(&teamA.player);	//16진수로 할당한 값 10, J, Q, K, A로 변환하는 함수
            re_mapping(&teamB.player);	//16진수로 할당한 값 10, J, Q, K, A로 변환하는 함수
            if (select == 3)	//선택된 select이 3이면 탈출 
               break;
            else if (select == 2)	//# 다시 #이 주석에 나오기 전까지 누가 어떤 패로 이겼는지 정하는 조건
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
               num2 = 0;	//초기화한다.
               break;		//탈출
            }
         }
      }
      fclose(f);	//반복문 나올 시 fclose로 f 메모리 영역 해제

   }
   return 0;
}



void mapping(char * c) {	//A, K, Q, J, 10은 16진수 E, D, C, B, A로 바꿔준다. 
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

void re_mapping(char *c ) {	//mapping함수에서 16진수로 변환한 걸 다시 바꾼다.
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

void sort(char *shape, int *number)	 //숫자를 기준으로 오름차순 정렬한다.(후에 페어 계산을 위해)
{
   int aa, i, j;
   char bb;
   for (i = 0; i < 4; i++) //버블정렬 숫자에 맞게 
   {
      for (j = i + 1; j < 5; j++)
      {
         if (number[i] > number[j])
         {
            aa = number[i];			 //카드 숫자와
            number[i] = number[j];
            number[j] = aa;

            bb = shape[i];			//카드 문양이 같이 움직인다.
            shape[i] = shape[j];
            shape[j] = bb;
         }
      }
   }
}

int high_shape(char shape[5])	//만약 같은 숫자 페어로 비겼을시 실행되어 모양을 비교한다.
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

int straight_check(int num[])	//정렬되어 있는 상태이므로 +1씩 하면서 스트레이트의 유무를 확인한다.
{
   int i;
   int c = 1;
   for (i = 0; i < 4; i++) //숫자가 연속적인가? 
   {
      if (num[i] + 1 != num[i + 1])
         if (num[i + 1] == 14 && num[i] == 5)
            c++;
         else
            break;
      c++;
   }
}

int flush_check(char color[])	//color가 다 똑같지 않으면 플러쉬는 존재하지 않는다.
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
//스트레이트, 플러쉬계산한 것도 매개변수로 들어와 최종 족보를 숫자로 정한다.
{
   if (col == 5 && li == 5) //1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때 
      if (card[8] == 14) {	//로티플
         return 1000 + card[8];
      }
      else {	//스티플
         return 900 + card[8];
      }
   else if (col == 5) //4. 카드 5장이 모두 같은 색일 때 (플러쉬)
      return 600 + card[8];

   else if (li == 5) //5. 카드 5장의 숫자가 연속적일 때 (스트레이트)
      return 500 + card[8];

   else
   {
      int num = 1;
      int num2 = 1;
      int plus = 0;
      int count = 0;
      int i, j;

      for (i = 0; i < 4; i++)	//한 번 검사했던 경우를 겹치지 않게 검사하고 모든 조건을 검사하는 알고리즘
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
      if (count == 4)	//포카드와 풀하우스는 정렬상태기준 4번으로 카운트가 같음
      {
         if (card[2] == card[6])
         {   //포카드  
            num = 4;
            plus = card[4];
         }
         else
         {
            num = 3;         //풀 하우스  
            num2 = 2;
            plus = card[4];
         }
      }
      else if (count == 2)	//트리플은 정렬기준 3만 나오지만 투페어는 예외가 있어 카운트3과 2에 나눠주었다.
      {
         if (card[0] == card[2] && card[0] == card[4])
         {//트리플  
            num = 3;
            num2 = 1;
            plus = card[4];
         }
         else if (card[2] == card[4] && card[2] == card[6])
         {//트리플  
            num = 3;
            num2 = 1;
            plus = card[4];
         }
         else if (card[4] == card[6] && card[4] == card[8])
         {//트리플  
            num = 3;
            num2 = 1;
            plus = card[4];
         }
         else
         {//투페어  
            num = 2;
            num2 = 2;
            plus = card[6];
         }
      }
      else if (count == 1)	//원페어  
      {
         num = 2;
         num2 = 1;
      }
      else	//탑  
      {
         num = 1;
         plus = card[8];
      }

      if (num == 4) //2. 카드 4장의 숫자가 같을 때 
         return 800 + plus;

      else if (num == 3)
      {
         if (num2 == 2) //3. 카드 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 
            return 700 + plus;

         else //6. 카드 3장의 숫자가 같을 때 
            return 400 + plus;
      }

      else if (num == 2)
      {
         if (num2 == 2) //7. 카드 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 
            return 300 + plus;

         else //8. 카드 2장의 숫자가 같을 때 
            return 200 + plus;
      }
      else //어떤 경우도 해당하지 않을 때 
         return 100 + plus;

   }
}

void final_print(int result, int num1, int num2)
//result에 따라 누가 이겼는지 어떤 카드로 이겼는지. 
{
   if (result == 1)
   {
      if (num2 == 0)	//select =1일때 사용
         printf("Team A wins \n");
      else
      {// num1은 calculation함수에서 반환받은 값. 
         if (num1 / 100 == 10)
            printf("로얄 스트레이트 플러쉬로 A가 이겼습니다.\n");
         else if (num1 / 100 == 9)
            printf("스트레이트 플러쉬로 A가 이겼습니다.\n");
         else if (num1 / 100 == 8)
            printf("포카드로 A가 이겼습니다.\n");
         else if (num1 / 100 == 7)
            printf("풀하우스로 A가 이겼습니다.\n");
         else if (num1 / 100 == 6)
            printf("플러쉬로 A가 이겼습니다.\n");
         else if (num1 / 100 == 5)
            printf("스트레이트로 A가 이겼습니다.\n");
         else if (num1 / 100 == 4)
            printf("트리플로 A가 이겼습니다.\n");
         else if (num1 / 100 == 3)
            printf("투페어로 A가 이겼습니다.\n");
         else if (num1 / 100 == 2)
            printf("원페어로 A가 이겼습니다.\n");
         else
            printf("탑으로 A가 이겼습니다.\n");
      }
   }
   else	
   {
      if (num2 == 0)	//select =1일때 사용
         printf("Team B wins \n");
      else
      {	// num1은 calculation함수에서 반환받은 값.
         if (num1 / 100 == 10)
            printf("로얄 스트레이트 플러쉬로 B가 이겼습니다.\n");
         else if (num1 / 100 == 9)
            printf("스트레이트 플러쉬로 B가 이겼습니다.\n");
         else if (num1 / 100 == 8)
            printf("포카드로 B가 이겼습니다.\n");
         else if (num1 / 100 == 7)
            printf("풀하우스로 B가 이겼습니다.\n");
         else if (num1 / 100 == 6)
            printf("플러쉬로 B가 이겼습니다.\n");
         else if (num1 / 100 == 5)
            printf("스트레이트로 B가 이겼습니다.\n");
         else if (num1 / 100 == 4)
            printf("트리플로 B가 이겼습니다.\n");
         else if (num1 / 100 == 3)
            printf("투페어로 B가 이겼습니다.\n");
         else if (num1 / 100 == 2)
            printf("원페어로 B가 이겼습니다.\n");
         else
            printf("탑으로 B가 이겼습니다.\n");
      }
   }
}

