#include <stdio.h>		//10:01분시작 10:02분 종료 1분(1번 문제 소스코드 변형)
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };	//arr배열에 1,2,3,4,5값지정
	int *ptr = &arr[0];				//ptr포인터와 arr배열과 동일한 주소값을 갖게함
	int num = 0;
	while (num < 5)					//반복해서 ptr첫번째부터 5번째까지 2씩 증가시키는 반복문(ptr=arr과 동일한 주소 값사용)
	{
		*(ptr + num) += 2;			//1.*(ptr+0) = *(ptr+0) + 2 2.*(ptr+1) = *(ptr+1) + 2 ...  반복
		num++;
	}
	printf("%d, %d, %d, %d, %d", arr[0], arr[1], arr[2], arr[3], arr[4]);	//올바르게 되었는가 확인하기 위해 출력
	return 0;
}