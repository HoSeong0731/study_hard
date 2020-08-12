#include <stdio.h>

int main(void)
{
	int i, j; // 변수 i, j 선언
	for (i = 0; i < 11; i++) // 행을 위한 반복문
	{
		for (j = 0; j <= 10-i; j++)	 // j가 10-i보다 작으면 공백 출력하기
		{
			printf(" ");
		}
		for (j = 0; j < i ; j++) // j가 i보다 작으면 *출력		
		{
			printf("*");
		}
		for (j = 1; j < i; j++)	// j를 1부터 시작해 직각삼각형+왼쪽으로 모인 직각삼각형이 되어 2개씩 증가하는 정삼각형 출력하기
		{
			printf("*"); 
		}
		printf("\n"); // 줄 바꿈
	}
	return 0;
}