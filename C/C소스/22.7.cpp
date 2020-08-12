#include<stdio.h>	//입출력 헤더파일
#include<math.h>	//수학관련 헤더파일

struct point	//point라는 이름의 구조체 선언
{
	int xpos;	//좌표 값 
	int ypos;	//좌표 값
};

struct circle	//circle라는 이름의 구조체 선언
{
	double radius;	//반지름 저장
	struct point * center;	//구조체 변수의 멤버로 구조체 포인터 변수를 선언
};

int main()
{
	struct point cen = { 2,7 };	//구조체 변수 선언
	double rad = 5.5;	//반지름 값
	struct point ptr = cen;	//구조체 변수를 선언 뒤 cen을 가르킨다
	double arr;	//직사각형의 넓이를 저장할 변수
	struct circle ring = { rad,&cen };	//구조체 변수 선언
	
	printf("원의 반지름: %g\n", ring.radius);	//ring이라는 멤버 radius출력
	printf("원의 중심 [%d, %d]\n", (ring.center)->xpos, (ring.center)->ypos);	//좌표 값 출력
	
	ptr.xpos = ptr.xpos * 5;	//x좌표 5배 증가
	ptr.ypos = ptr.ypos * 5;	//y좌표 5배 증가
	
	arr = (ptr.xpos - cen.xpos)*(ptr.ypos - cen.ypos);	//넓이 구하는 공식
	printf("원의 중심과 5배 떨어진 점을 대각선으로 하는 직사각형의 넓이는:%lf이다", arr);	//출력  
	return 0;	//메인함수 종료  
}

