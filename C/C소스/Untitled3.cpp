#include <stdio.h>
int main()
{
	int cur = 2;			//2단부터실행
	int is = 1;				//is 변수 만듦

	while (is < 10)
	{
		cur = 1;		//중첩반복문실행을 위해 1로 계속 초기화
		while (cur < 9)
		{
			cur++;		//후위증가로 구구단의 앞의 수 증가
			printf("%d X %d = %-3d ", cur, is, cur*is);					//%-3d로 공간확보
		}
		printf("\n");	//각 단을 종료하고 줄바꿈
		is++;	//단 넘김
	}
	return 0;
}
