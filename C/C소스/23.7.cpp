#include <stdio.h>	//표준 입출력 라이브러리
#include <math.h>	//수식관련 헤더파일  
#include <windows.h>//윈도우 헤더파일  

typedef struct point	//구조체 point의 정의와 Point에 대한 typedef 선언을 위해 묶음
{
	int xpos;	//좌표 값 저장
	int ypos;	//좌표 값 저장
} Point;

Point AddPoint(Point pos1, Point pos2)	//덧셈함수  
{
	Point pos = { pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos };
	return pos;	//pos값 되돌림  
}

Point MinPoint(Point pos1, Point pos2)	//뺄셈함수  
{
	Point pos = { pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos };
	return pos;	//pos값 되돌림  
}

int main()	//메인함수
{
	Point pos1 = { 5, 6 };	//구조체Point 변수 pos1선언
	Point pos2 = { 2, 9 };	//구조체Point 변수 pos2선언
	Point result;			//구조체Point 변수 result선언
	double Distance = sqrt((double)(pos1.xpos - pos2.xpos)*(pos1.xpos - pos2.xpos) + (pos1.ypos - pos2.ypos)*(pos1.ypos - pos2.ypos));
	//거리공식
	 
	result = AddPoint(pos1, pos2);						//덧셈함수실행  
	printf("[%d, %d] \n", result.xpos, result.ypos);	//출력  

	result = MinPoint(pos1, pos2);						//뺄셈함수실행  
	printf("[%d, %d] \n", result.xpos, result.ypos);	//출력  
	printf("%lf \n", Distance);							//출력  
	system("PAUSE");	//일시정지  
	return 0;	//메인함수 종료
}
