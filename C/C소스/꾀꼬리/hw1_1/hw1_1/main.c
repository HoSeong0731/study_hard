#include<stdio.h>	//표준입출력헤더파일 포함  

int main()	//main함수 생성  
{
	int i = 2, j = 4;  //좌표 포인트 정하는 변수 생성  
	int x1, x2, y1, y2;	//좌표 입력 받을 변수  
	int height, width, area; //가로 세로 넓이변수  
	int temp;	//값 이동 변수  

back:	//입력받은 값에 오류가 있을경우 돌아옴. 
	printf("첫 번째 좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &x1, &y1);	//첫 번째 좌표를 입력받음  
	printf("두 번째 좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &x2, &y2);	//두 번째 좌표를 입력받음

	if ((x1 == x2) || (y1 == y2))	//x나 y값 중 같은 값이 있으면 직선이 되어버림. 
	{
		printf("잘못된 좌표를 입력하셨습니다. \n\n");
		goto back;	//좌표 값 다시 받음  
	}
	if ((x1 < x2) && (y1 < y2)) //좌표 포인트 정하는 조건  
	{
		i = 1;
		j = 3;
	}
	if (x1 > x2)	//후에 가로에 음수 값이 안나오게 함. 
	{

		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y1 > y2)	//후에 세로에 음수 값이 안나오게 함. 
	{

		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	width = x2 - x1;	//가로 계산  
	height = y2 - y1;	//세로 계산.  
	area = width * height;	//넓이 계산  

	printf("첫번째 점의 좌표 point %d (%d,%d) \n", i, x1, y1);	//첫 번째 좌표위치 출력  
	printf("첫번째 점의 좌표 point %d (%d,%d) \n", j, x2, y2);	//두 번째 좌표위치 출력  
	printf("사각형의 넓이는 가로 %d, 세로 %d로  %d 입니다.\n", width, height, area);	//넓이 출력

	return 0; 	//main함수 종료  
}
