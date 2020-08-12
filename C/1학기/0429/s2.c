#include <stdio.h>
int insert(int num)		//입력받는 함수(결과적으로는 scanf함수와 같음
{
	scanf("%d, ", &num);
	return num;
}
int maxpoint(int N1, int N2, int N3)	//최대값 계산함수
{
	if (N1 > N2)
		return(N1 > N3) ? N1 : N3;
	else
		return (N2 > N3) ? N2 : N3;
}
int minpoint(int n1, int n2, int n3)	//최소값 계산함수
{
	if (n1 < n2)
		return (n1 < n3) ? n1 : n3;
	else
		return (n1 < n3) ? n1 : n3;
}
int main()				
{
	int num1 = 0, num2 = 0, num3 = 0; 
	printf("숫자입력1:");		
	num1 = insert(num1);		//num1 값 입력받기
	printf("\n숫자입력2:");
	num2 = insert(num2);		//num2 값 입력받기
	printf("\n숫자입력3;");
	num3 = insert(num3);		//num3 값 입력받기
	printf("가장 큰 수 출력: %d \n", maxpoint(num1, num2, num3));
	printf("가장 작은 수 출력: %d \n", minpoint(num1, num2, num3));
	return 0;
}