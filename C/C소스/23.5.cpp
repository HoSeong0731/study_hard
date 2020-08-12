#include <stdio.h>	//표준 입출력 라이브러리
#include <windows.h>//윈도우 헤더파일  

typedef struct point	//구조체 point의 정의와 Point에 대한 typedef 선언을 위해 묶음
{
	int xpos;	//좌표 값 저장
	int ypos;	//좌표 값 저장
}Point;

typedef struct score//구조체 score의 정의와 Score에 대한 typedef 선언을 위해 묶음
{
	int r;		//국어성적 저장
	int d;		//영어성적 저장
	int t;		//수학성적 저장
	double i;	//평균값 저장
}Score;

void OrgSymTrans(Point * ptr)	//x축 대칭과 y축 대칭을 위한 함수 정의
{
	int a, b;			//임시 값을 받기 위한 변수
	a = (ptr->ypos)*-1;	//x축대칭
	b = (ptr->xpos)*-1;	//y축대칭
	ptr->xpos = a;	//연산자를 기반으로 하는 변수에 a값 저장
	ptr->ypos = b;	//연산자를 기반으로 하는 변수에 b값 저장
}

void average(Score * aaa)	//평균을 구하기 위한 함수 정의
{
	
	aaa->i = (aaa->r + aaa->d + aaa->t) / 3;	//평균값 구하기
}

void ShowPosition(Point pos)	//출력을 위한 함수 정의
{
	printf("[%d, %d] \n", pos.xpos, pos.ypos);	//출력
}

void showpoint(Score abc)	//성적을 출력하기 위한 함수
{
	printf("국어:%d 영어:%d 수학:%d\n평균:%lf", abc.r, abc.d, abc.t,abc.i);	//출력
}

int main()	//메인함수
{
	Point pos = { 7,-5 };	//구조체Point 변수pos 선언
	Score abc = { 90,98,95 };//구조체Score 변수abc 선언
	OrgSymTrans(&pos);		//대칭하기 위한 함수 호출
	ShowPosition(pos);		//바뀐 좌표값 확인하기 위한 함수 호출
	OrgSymTrans(&pos);		//대칭하기 위한 함수 호출
	ShowPosition(pos);		//바뀐 좌표 값을 확인 하기 위한 함수 호출
	average(&abc);			//평균을 구하기 위한 함수 호출
	showpoint(abc);			//성적을 출력하기 위한 함수 호출
	system("PAUSE");		//일시정지  
	return 0;	//메인함수 종료
}
