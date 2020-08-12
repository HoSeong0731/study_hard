#include <stdio.h>
int main()
{
	int num = 1;		//num을 1로 시작해 반복문이 바로 종료되는 걸 방지.
	int result = 0;
	
	
	while (num!=0)
	{
		printf("\n정수를 입력하세요(0이면 종료 됩니다.):");
		scanf("%d", &num);			//num에 0이 오기 전까지 반복문 실행
		result = result + num;
		
	}
	printf("입력된 정수의 총 합: %d \n", result);		//총합출력
	return 0;
}