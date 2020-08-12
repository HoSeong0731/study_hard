#include <stdio.h>
int main()
{
	int arr[3] = { 0,1,2 };
	printf("배열의 이름: %p \n", arr);
	printf("첫 번째 요소: %p \n", &arr[0]);
	printf("첫 번째 요소: %d \n", &arr[0]);	//10진수형 주소 값 출력
	printf("첫 번째 요소: %x \n", &arr[0]);	//16진수형 주소 값 출력(바이트 지정 없으므로 8자리 채워지지 않음.
	printf("두 번째 요소: %p \n", &arr[1]);
	printf("세 번째 요소: %p \n", &arr[0]);	
	printf("첫 번째 요소: %p \n", *arr);

	return 0;
}