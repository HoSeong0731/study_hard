#include <stdio.h> 	//표준 입출력 헤더파일
#include <stdlib.h> //표준 메모리라이브러리

int * ReadNum(int * arr, int arrlen, int idx) //입력받는 함수  
{
   printf("정수 입력: "); 	
   scanf("%d", &arr[idx]); 	
   return arr; //arr의 값 반환
}

int main(void) //main함수
{
   int arrlen = 5; 
   int idx = 0; 
   int i; 
   int * arr = (int*)malloc(sizeof(int)*arrlen); //4*arrlen바이트를 힙 영역에 할당

   while (1) //무한반복문
   {
      arr = ReadNum(arr, arrlen, idx); 	//ReadNum함수 호출을 통해 arr 입력받기
      if (arr[idx] == -1) 				//arr[idx]가 -1이면
         break; 						//무한반복문 빠져나오기

      if (arrlen == idx + 1)//arrlen이 idx+1과 같으면
      {
         arrlen += 3; 		//arrlen에 3 더하기(3바이트 늘리기)
         arr = (int *)realloc(arr, sizeof(int)*arrlen); //다시 4*arrlen바이트를 힙 영역에 할당
      }
      idx++; //idx에 1 더하기
   }
   for (i = 0; i < idx; i++)	//i=0부터 i<idx일 때까지 idx번 반복
      printf("%d ", arr[i]);	//arr[i] 출력
   free(arr); 					//할당된 메모리 공간 해제
   return 0; //main함수 종료
}
