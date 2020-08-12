#include <stdio.h>
void ShowData(const int *ptr)		//포인트변수 ptr을 이용해서 ptr이 가리키는 변수에 저장된 값을 변경할 수 없음 
{
	int * rptr = ptr;				//포인터변수 rptr = ptr이 입력되서 rptr로 ptr값 변경 가능
	printf("%d \n", *rptr);			//출력시 rptr = ptr = num = 10
	*rptr = 20;						//출력시 rptr = ptr = num = 20(const int *ptr 무의미하게 함.)
}
int main()
{
	int num = 10;
	int * ptr = &num;	//*ptr값은 &num값과 같다.
	ShowData(ptr);		//ptr값 ShowData함수에 입력.
	printf("%d", *ptr);	//바뀐 값을 보이기위해 추가함.
	return 0;
}