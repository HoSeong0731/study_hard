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

int main()	//메인함수
{
	Point pos1 = { 1,2 };	//구조체Point 변수 pos1선언
	Point pos2;				//구조체Point 변수 pos2선언
	pos2 = pos1;
	Grade man1 = { "김호성", "4.5" };	//구조체Grade 변수 man1선언
	Grade man2;							//구조체Grade 변수 man2선언
	man2 = man1;
	
	printf("크기: %d \n", sizeof(pos1));			//출력
	printf("[%d, %d] \n", pos1.xpos, pos1.ypos);	//출력
	
	printf("크기: %d \n", sizeof(pos2));			//출력
	printf("[%d, %d] \n", pos2.xpos, pos2.ypos);	//출력
	printf("이름: %s, 성적: %s \n", man1.name, man1.point);	//출력
	printf("이름: %s, 성적: %s", man2.name, man2.point);	//출력
	system("PAUSE");	//일시정지  
	return 0;	//메인함수 종료
}
