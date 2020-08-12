#include <stdio.h>
int main()
{
	int cur = 2;		//2단부터 출력하기 위함.
	int is = 1;			//쓰레기값이 저장되는 걸 방지하기위해 1을 넣음.(안넣어도 무방)

	while (cur < 10)
	{
		is = 1;		//중첩된 반복문 실행을 위해 is초기화
		while (is < 10)
		{
			printf("%d X %d = %-3d ", cur, is, cur*is);		//%-3d로 공간확보
			is++;		//is후위증가로 2*1 3*1 4*1순으로 실행
		}
		printf("\n");	//뒤에 숫자 기준으로 1단부터 실행후 줄바꿈
		cur++;			//앞에 숫자 증가
	}
	return 0;
}