#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char benglish[26] = {
   'A','B','C','D','E',
   'F','G','H','I','J',
   'K','L','M','N','O',
   'P','Q','R','S','T',
   'U','V','W','X','Y',
   'Z' };//출력을 위한 영어
char senglish[26] = {
   'a','b','c','d','e',
   'f','g','h','i','j',
   'k','l','m','n','o',
   'p','q','r','s','t',
   'u','v','w','x','y',
   'z' };//입력받기 위한 영어
char * mos[26] = {
   ".-","-...","-.-.","-..",".",
   "..-.","--.","....","..",".---",
   "-.-",".-..","--","-.","---",
   ".--.","--.-",".-.","...","-",
   "..-","...-",".--","-..-","-.--",
   "--.." };//모스부호

int error1(char input, int num) //첫번쨰 입력 때 스페이스바 또는 엔터를 입력하였다.
{
   if ((input == ' ' || input == '\n') && num == 0)
      return 1;
}
int error2(char input,int mos,int english)//모스부호가 입력되다 영어로 변하였다.(반대경우 에서도) 
{
   if ( mos == 1 && english==1)
      return 1;

}
int error3(char input) //다른 문자가 들어 갈 경우
{
   if (input == 45 || input == 46)
      return 0;
   else if (input == 10 || input == 32)
      return 0;
   else if ((input > 96 && input < 123) || (input > 64 && input < 91))
      return 0;
   else
      return 1;
}



int main()
{

   char input, getin[1][10] = { 0 }, mos_jump[2];
   //input 입력 받을 값
   //getin input에 값을 getin에 저장
   //mos_jump 스페이스바(10)이 두번 입력되면 모스부호도 띄어쓰기를 위한 변수 설정
   int i, k, num1=0, up=0, exit=0, mos_use=0, english_use=0, jump=0;// i 반복문을 위함
   int Error1 = 0, Error2 = 0, Error3 = 0;
   char * English = (char*)calloc(30,sizeof(char));	//30칸짜리 동적할당 
   char * Mos = (char*)calloc(30, sizeof(char));	//30칸짜리 동적할당  
   int text, print=0;
   

   while (1)
   {  
      printf("In:");
      do {	//한글자씩 변환되는 게 반복되는 dowhile문  
         
         input = getchar();	//사용자에게 값을 입력받음  
         
         Error1 = error1(input, num1);					//오류확인1 (num1이 0은 무조건 참인 조건) 
         Error2 = error2(input, mos_use, english_use);	//오류확인2 
         Error3 = error3(input);						//오류확인3 
         num1 = 1;//45= "-",46=".", 32=" ", 10="\n"
         if (Error1 == 1)
         {
            exit = 1;
            printf("예외입니다. 프로그램을 종료합니다.");
            break; 	//dowhile문 탈출  
         }
         if (Error2 == 1)
         {
            exit = 1;
            printf("\n코드를 해석하던 중 다른 언어가 들어왔습니다. 프로그램을 종료합니다.");
            break; 	//dowhile문 탈출   
         }
         if (Error3 == 1)
         {
            exit = 1;
            printf("\n영어나 모스부호가 아닌 다른 값을 입력했습니다. 프로그램을 종료합니다.");
            break; 	//dowhile문 탈출   
         }
        
         if (print == 0)	//처음에만 out을 출력하기 위함. 첫번째 바퀴 마지막에서 print = 1로 바꿔줌. 
            printf("Out:");

         if ((input == '\n' && mos_use == 1) || (input == 32 && mos_use == 1))
         {
            for (i = 0; i < 26; i++)//모스부호를 입력 받았을 때
            {

               if (!strcmp(getin[0], mos[i]))	//mos[i]값이 0이 아니면 실행 
               {
                  printf("%c", benglish[i]);	//대문자 출력  
                  mos_jump[0] = 0;				
                  mos_jump[1] = 0;
                  for (k = 0; k < 10; k++)		//모스부호는 여러글자 영어는 한글자씩 이므로  
                     getin[0][k] = 0;
                  break;		//영어를 입력 받았을 때로 넘어가지 않기 위해 필요.  
               }
            }
         }
         
         do{
         	for (i = 0; i < 26; i++)//영어를 입력 받았을 때
            {
               if (input == senglish[i] || input == benglish[i])//일치 할 때마다 하나씩 값을 받는다.
               {
                  printf("%s ", mos[i]);	//포인터로 할당한 구조체 변수에서 실행  
               }
            }
		 }while(0);	//처음에 무조건 값을 안받는 오류를 해결하기 위함(처음 do while문이 돌때는 english_use값이 무조건 0임.) 
         if(english_use==1)
         {
            
            if (input == 32)	//아스키코드 값으로 스페이스바가 32임.  
            {
               printf(" ");
            }
         }
         if (input == 32&&mos_use==1)
         {
            up = 0;					//한개가 입력되고 증가 -다음 값을 받을 준비를 한다.
            mos_jump[jump] = input;	//모스 부호에 사용을 알린다.
            jump++;					//점프 값을 초기화해준다.
         }
         else if ((input > 96 && input < 123) || (input > 64 && input < 91))//a=97, z=122, A=65, Z=90
            english_use=1;
      
         else if (input == 45 || input == 46)
         {
            getin[0][up] = input;	//input에 입력값을 배열에 하나하나 저장한다.
            up++;			//한개가 입력되고 증가 -다음 값을 받을 준비를 한다.
            mos_use = 1;	//모스 부호에 사용을 알린다.
            jump = 0;		//점프 값을 초기화해준다.
         }
         if (mos_jump[0] == 32 && mos_jump[1] == 32)
            printf(" ");	//출력
         print = 1;			//out을 출력을 안하기 위해 증가시킨다.
      } while (input != '\n');	//input값이 \n이 올때까지 반복한다.  
      
      
      if (exit == 1)	//오류가 걸리면 무한반복 탈출  
         break;
      else if (exit == 0)	
         break;			//정상적으로 dowhile문이 종료되어도 탈출  
   }

   return 0;			//main함수 종료  
}
