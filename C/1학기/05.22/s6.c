#include <stdio.h>	//시작시간 6시 58분  
int main()			//걸린시간 15분  
{
	int arr[6] ={1, 2, 3, 4, 5, 6}; //arr배열 생성 
	int *(ptr1) = &arr[0];			//ptr1의 값은 arr[0]번의 주소값 = 0 
	int *(ptr2) = &arr[5];			//ptr2의 값은 arr[5]번의 주소값 = 6 
	int change = 0;
	int num = 0;
	
	for( num = 0; num < 6; num++ )
	{
		printf("현재(%d번째)): %d\n", num+1, arr[num]);	//현재 상황 출력 
		
	}
	
	for(num = 0; num < 3; num++)	//6까지 가면 한바퀴 도는 상황 절반만 
	{
	change = *ptr1;					//change값에 미리 ptr1값 저장 
	*ptr1 = *ptr2;					//후에 ptr1값 바꾸기 
	*ptr2 = change;					//저장된 change값 ptr에 저장 
	ptr1 += 1;						//ptr1 = 0 에서 1로 증가 
	ptr2 += -1;						//ptr2 = 6 에서 5로 감소 
	}
	//ptr 1은 arr[0]을 지정하고 있었고, 그 둘은 같다고 해놨기 때문에 arr[0]과 arr[5]값 변경됨 
	for(num = 0; num < 6; num++)
	{
		printf("변경 값(%d번째)): %d\n", num+1, arr[num]);//변경값 출력 
	}
	return 0;
 } 
