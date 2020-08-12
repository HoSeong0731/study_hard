#include <stdio.h>	//표준 입출력 라이브러리
#include <windows.h>//윈도우 헤더파일  

typedef struct student	//구조체 student의 정의와 Student에 대한 typedef 선언을 위해 몪음
{
	char name[20];	//이름 저장
	char num[20];	//번호 저장
	int a;	//국어 성적 저장
	int b;	//영어 성적 저장
	int c;	//수학 성적 저장
}Student;

typedef struct point	//구조체 point의 정의와 Point에 대한 typedef 선언을 위해 몪음
{
	int xpos;	//좌표 값 저장
	int ypos;	//좌표 값 저장
}Point;

typedef struct circle	//구조체 circle의 정의와 Circle에 대한 typedef 선언을 위해 몪음
{
	Point cen;	//구조체Point 변수cen 저장
	double rad;	//반지름 값 저장
	Student a;	//구조체Student 변수a 저장
}Circle;

void ShowCircleInfo(Circle *cptr)//출력을 위한 함수 정의
{
	printf("[%d, %d] \n", (cptr->cen).xpos, (cptr->cen).ypos);	//출력
	printf("radius: %g \n\n", cptr->rad);						//출력
	printf("이름:%s \n학번:%s \n국어:%d \n수학:%d \n영어:%d\n\n", (cptr->a).name, (cptr->a).num, (cptr->a).a, (cptr->a).b, (cptr->a).c);
	//출력
}
int main()	//메인함수
{
	Circle c1 = {{1,2},3.5,"김호성","2019202052",98,99,90 };	//구조체Circle 변수c1 선언
	Circle c2 = {2,4,3.9,"박수빈","2019803070",100,100,100};	//구조체Circle 변수c2 선언
	

	ShowCircleInfo(&c1);	//출력을 위한 함수 호출
	ShowCircleInfo(&c2);	//출력을 위한 함수 호출
	system("PAUSE");	//일시정지  
	return 0;	//메인함수 종료
}

