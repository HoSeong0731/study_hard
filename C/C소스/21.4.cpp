#include<stdio.h>	//표준입출력헤더파일
int main()	//main함수 
{
	char str[7];	//크기가 6인 1차원 배열 생성 
	int i;	//반복문을 위한 변수 생성  
	
	for(i=0; i<3; i++)	//3번 반복함  
	{
		fgets(str, sizeof(str), stdin);	// null값이 있으므로 6개씩 입력받음(6개이하일경우 전부 채우지 않고 출력 후 넘어감) 
	 	printf("Read %d: %s \n", i + 1, str);	//6개씩 출력됨(남은 숫자는 다음 반복에 출력 단, 6개를 정확히 채울경우 enter까지 있으므로 다음으로 넘어가짐.) 
	 } 
	 
	return 0;	//main함수 종료  
}
