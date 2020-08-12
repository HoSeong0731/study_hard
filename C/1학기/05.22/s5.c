#include <stdio.h>		// 걸린시간 15분 
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };	//arr배열에 1,2,3,4,5값지정
	int *(ptr) = &arr[4];				//ptr = arr[4]
	int num = 5;
	int sum = 0;
	while (num > 0)					//반복해서 ptr첫번째부터 5번째까지 2씩 증가시키는 반복문(ptr=arr과 동일한 주소 값사용)
	{
		sum += *(ptr--);			//1. sum += 5, 2. sum += 9.... 
		num--;						//반복문 종료 조건
		 
	}
	printf("합계: %d", sum);	//올바르게 되었는가 확인하기 위해 출력
	return 0;
}
