#include <stdio.h>
void count(void);
int main(void)
{
	int i;
	for (i = 1; i <= 3; i++)//반복문으로 count함수 3번 실행
		count();			//count함수실행
	return 0;
}
void count(void)
{
	int acnt = 0;			//함수를 벗어날 때 마다 0으로 초기화
	static int stcnt = 0;	//static을 붙이면 정적 변수가 되므로 함수를 벗어나더라도 변수의 저장되었던 값이 사라지지 않음
	acnt += 1;
	stcnt += 1;
	printf("auto count=%d, static count= %d\n", acnt, stcnt);	//처음 1 1, 다음 1 2, 다음 1 3(for문으로 3번 반복하게끔 설정함)
}
//걸린 시간: 7분