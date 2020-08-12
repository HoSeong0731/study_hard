#include <stdio.h>	//표준 입출력 라이브러리
#include <windows.h>//윈도우 헤더파일  

typedef struct point	//구조체 point의 정의와 Point에 대한 typedef 선언을 위해 묶음
{
	int xpos;	//좌표 값 저장
	int ypos;	//좌표 값 저장
} Point;

typedef struct grade	//구조체 grade의 정의와 Grade에 대한 typedef 선언을 위해 묶음
{
	char name[20];	//학생의 이름 저장 
	char point[20];	//학생의 성적 저장  
} Grade;

void Showpoint(Grade num)	//구조체 Grade를 출력   
{
	printf("이름: %s 성적: %s \n", num.name, num.point);	//출력
}	

void ShowPosition(Point pos)//구조체 Point를 출력  
{
	printf("[%d, %d] \n", pos.xpos, pos.ypos);	//출력
}

Grade GetCurrentgrade()		//구조체 Grade를 입력  
{
	Grade num;	//구조체Grade 변수num선언
	printf("학생의 이름을 입력하세요: ");	//출력
	scanf("%s", num.name);					//입력  
	printf("\n학생의 성적을 입력하세요:");	//출력
	scanf("%s", num.point);					//입력
	return num;		//num값을 되돌림  
}

Point GetCurrentPosition()	//구조체 Point를 입력  
{
	Point cen;	//구조체Point 변수cen선언
	printf("Input current pos(x): ");	//출력
	scanf("%d", &cen.xpos);				//입력
	printf("Input current pos(y): ");	//출력
	scanf("%d", &cen.ypos);				//입력
	return cen;		//cen값을 되돌림  
}

int main()	//메인함수
{
	Point curPos = GetCurrentPosition();//구조체Point 변수curPos선언
	ShowPosition(curPos);				//curPos출력  
	Grade grade = GetCurrentgrade();	//구조체Grade 변수grade선언
	Showpoint(grade);				  	//grade출력 
	system("PAUSE");	//일시정지  	
	return 0;	//메인함수 종료
}
