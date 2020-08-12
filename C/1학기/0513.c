#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
	int size = 0;
	int max = 0, min = 0, sum = 0, i = 0;		//쓰레기값 들어가는 걸 방지하기 위해 0으로 초기화 
	int num = 0;
	printf("배열의 크기를 입력하세요:");
	scanf("%d", &size);							//size = 입력받은 값만큼 

	int *numPtr = malloc(sizeof(int) * size);    // {int 크기(4byte) * 입력받은 크기}만큼 동적 메모리 할당

	for (i = 0; i < size; i++)    // 입력받은 크기만큼 반복
	{
		printf("%d번째 변수의 값 입력", i);//numPtr[0]부터 순서대로 입력 
		scanf("%d", &num);				// 배열 1번째부터 순서대로 값 저장. 
		numPtr[i] = num;                // 반복문에 의해 [i]값 마다 num값 저장. 
	}

	max = min = sum = numPtr[0];	//max, min, sum 다 1번째 값으로 지정 후 비교하면서 수정 됨. 
	for(i = 1; i < num; i++)		//2번째 배열부터 반복문 실행 
	{		
		sum += numPtr[i];			//sum 수식 
		if(max<numPtr[i])			//max 수식 
		 max=numPtr[i];				//조건 일치시 max값 변경 
		if(min>numPtr[i])			//min 수식 
		 min=numPtr[i];				//조건 일치시 min값 변경 
	}
	printf("max: %d \n", max);	//max출력 
	printf("min: %d \n", min);	//min출력 
	printf("sum: %d \n", sum);	//sum출력 
	return 0;
}
