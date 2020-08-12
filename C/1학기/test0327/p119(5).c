#include<stdio.h>
int main()
{
	char abc;						//문자입력 받을 변수 abc선언
	printf("아스키코드문자입력:");
	scanf("%c", &abc);				//scanf에는 줄바꿈들어가면 안된다.
	printf("\n입력한 문자의 코드는: %d", abc);
	return 0;
}