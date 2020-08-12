#include <stdio.h> 	//표준 입출력 헤더파일
#include <stdlib.h> //표준 메모리라이브러리
#include <string.h> //표준 문자열라이브러리  

char * ReadString(int maxlen) //입력받는 함수  
{
   char * str = (char *)malloc(sizeof(char)*(maxlen + 1)); //4바이트 크기의 블록 n개를 힙 영역에 할당
   printf("문자열 입력: ");
   fgets(str, maxlen + 1, stdin); //fgets함수를 통해 str 입력받기
   return str; //값 반환
}

int main(void) //main함수
{
   int maxlen, len, i; 	//int형 변수 선언
   char * str; 			//char형 포인터 변수 str 선언

   printf("문자열의 최대 길이 입력: "); 
   scanf("%d", &maxlen); 
   getchar(); 			//\n 문자 지우기

   str = ReadString(maxlen); 	//ReadString함수 호출을 통해 str 입력받기

   str[strlen(str) - 1] = 0; 	//\n 문자 지우기
   len = strlen(str); 			//len에 strlen(str) 저장
   for (i = len; i > 0; i--) 	//i=len부터 i>0일 때까지 i를 1씩 감소시키면서 len번 반복
      if (str[i] == ' ') 		//str[i]가 공백이면 실행
      {
         printf("%s ", &str[i + 1]); 	//str[i+1] 출력
         str[i] = 0; 					//str[i]에 0 저장
      }
   printf("%s", &str[0]); 	//str[0] 출력
   free(str); 				//할당된 메모리 공간 해제
   return 0; 				//main함수 종료
}
