#include <stdio.h>	//입출력 헤더파일
#include <math.h>	//수학관련 헤더파일  

struct point	//point 구조체 생성  
{
	int xpos;
	int ypos;
};

int main()	//main함수  
{
	struct point arr[4];	//구조체 point변수 생성  
	int i;
	double arr2[3];	//후에 arr값의 차이를 받음  
	for(i=0; i<3; i++)	//arr에 값을 입력 받음  
	{
		printf("점의 좌표 입력: ");
		scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
	}
	
	arr[3].xpos = arr[0].xpos;	//4번째 칸에 1번째 칸의 값을 받음 
	arr[3].ypos = arr[0].ypos;	//4번쨰 칸에 1번째 칸의 값을 받음  
	
	for(i=0; i<3; i++)	//계산  
	{
		arr2[i] = sqrt((double)((arr[i].xpos-arr[i+1].xpos)*(arr[i].xpos-arr[i+1].xpos)+(arr[i].ypos-arr[i+1].ypos)*(arr[i].ypos-arr[i+1].ypos)));
	}
	
	printf("%g %g %g", arr2[0], arr2[1], arr2[2]);	//출력 
	return 0;	//메인함수 종료  
}
