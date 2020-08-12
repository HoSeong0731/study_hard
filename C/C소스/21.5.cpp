#include<stdio.h>	//표준입출력헤더파일
int main()	//main함수 
{
	char perID[7];	//크기가 7인 1차원 배열 출력 
	char name[10];	//크기가 10인 1차원 배열 출력  
	
	fputs("주민번호 앞 6자리 입력 ", stdout);	//stdout에 의해 모니터에 출력  
	fgets(perID, sizeof(perID), stdin);	//주민번호6자리까지만 입력되고 남은 버퍼는 다음 fgets에 넘어감.(enter포함) 
	
	fputs("이름입력: ", stdout);	//stdout에 의해 모니터에 출력  
	fgets(name, sizeof(name), stdin);	//위에 입력받은 값의 나머지를 입력 받음  
	
	printf("주민번호: %s \n", perID);	//perID에 입력받은 값 출력  
	printf("이름: %s \n", name);	//name에 입력받은 값 출력  
	return 0;	//main함수 종료  
}
