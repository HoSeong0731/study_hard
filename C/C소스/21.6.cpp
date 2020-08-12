#include<stdio.h>	//표준입출력헤더파일

void ClearLineFromReadBuffer()	//버퍼에 남은 값 지우는 함수  
{
	while(getchar()!='\n');	//getchar가 줄넘김이 나올때까지 값을 없앰  
 } 
 
int main()
{
	char perID[7];	//크기가 7인 1차원 배열생성 
	char name[10];	//크기가 10인 1차원 배열생성  
	
	fputs("주민번호앞 6자리 입력: ",stdout);	//stdout에 의해 모니터에 출력  
	fgets(perID, sizeof(perID), stdin);	//주민번호6자리까지만 입력
	ClearLineFromReadBuffer();
	
	fputs("이름 입력: ",stdout );	//stdout에 의해 모니터에 출력  
	fgets(name, sizeof(name), stdin);	//입력받아 name배열에 저장  
	
	printf("주민번호: %s\n", perID);	//perID에 입력받은 값 출력  
	printf("이름: %s\n", name);	//name에 입력받은 값 출력  
	return 0;	//main함수 종료
}
