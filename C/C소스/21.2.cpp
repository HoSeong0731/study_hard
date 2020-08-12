#include <stdio.h>	//표준입출력헤더파일 
int main()	//main함수 
{
	int ch;		//문자입력받을 변수 생성 
		
	while (1)	//무한반복  
	{
		ch = getchar();	//문자입력받음  
		if (ch == EOF)	//ctrl + z키 입력받으면 조건에 성립함. 
		{
			break;		//가장 가까운 반복문 탈출  
			
		}
		putchar(ch);	//입력받은 문자 출력
	}
	return 0;	//main함수종료  
}
