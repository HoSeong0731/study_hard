#include <stdio.h>	//표준 입출력 라이브러리
#include <windows.h>//윈도우 헤더파일  

struct point	//구조체 point의 정의와 Point에 대한 typedef 선언을 위해 묶음
{
	int xpos;	//좌표 값 저장
	int ypos;	//좌표 값 저장
};
typedef struct point Point;

typedef struct person	//구조체 person의 정의와 Person에 대한 typedef 선언을 위해 묶음
{
	char name[20];		//이름 저장
	char phoneNum[20];	//번호 저장
	int age;			//나이 저장
} Person;

typedef struct building	//구조체 building의 정의와 Bui에 대한 typedef 선언을 위해 묶음
{
	char name[20];	//건물 이름 저장
	char number[20];//번지수 저장
	int floor;		//층수 저장
	int price;		//가격 저장
} Bui;

int main()	//메인함수
{

	Point pos = { 10,20 };	//구조체Point 변수 pos선언  
	Person man = { "김호성", "010-2570-8478", 20 };	//구조체Person 변수man선언
	Bui Bu = { "청춘시대", "429-8", 6, 1000 };		//구조체Bui 변수Bu선언
	printf("%d %d \n", pos.xpos, pos.ypos);			//출력  
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);				//출력
	printf("%s %s %d %d \n", Bu.name, Bu.number, Bu.floor, Bu.price);	//출력
	system("PAUSE");	//일시정지  
	return 0;	//메인함수 종료
}
