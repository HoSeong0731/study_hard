#include <stdio.h>	//표준 입출력 라이브러리
#include <windows.h>//윈도우 헤더파일  

typedef struct person	//구조체 person의 정의와 Person에 대한 typedef 선언을 위해 묶음
{
	char name[20];		//이름 저장
	char phoneNum[20];	//번호 저장
	int age;			//나이 저장
}Person;

typedef struct building	//구조체 building의 정의와 Bui에 대한 typedef 선언을 위해 묶음
{
	char name[20];	//건물 이름 저장
	char num[20];	//번지수 저장
	int a;			//층수 저장
	int b;			//가격 저장
}Bui;

void ShowPersonInfo(Person man,Bui a)		//출력을 위한 함수 정의
{
	printf("name: %s \n", man.name);		//변수에 멤버에 저장된 값 출력
	printf("phone: %s \n", man.phoneNum);	//변수에 멤버에 저장된 값 출력
	printf("age: %d \n", man.age);			//변수에 멤버에 저장된 값 출력
	printf("name: %s \n", a.name);			//변수에 멤버에 저장된 값 출력
	printf("번지수: %s \n", a.num);			//변수에 멤버에 저장된 값 출력
	printf("층수: %d \n", a.a);				//변수에 멤버에 저장된 값 출력
	printf("가격: %d \n", a.b);				//변수에 멤버에 저장된 값 출력
}

Person ReadPersonInfo(void)	//입력을 위한 함수 정의
{
	Person man;				//구조체 변수 선언
	printf("name: "); scanf("%s", man.name);		//구조체 변수의 멤버 입력
	printf("phone: "); scanf("%s", man.phoneNum);	//구조체 변수의 멤버 입력
	printf("age: "); scanf("%d", &man.age);			//구조체 변수의 멤버 입력
	return man;
}

Bui Read(void)	//입력을 위한 함수 정의
{
	Bui a;	//구조체 변수 선언
	printf("name: "); scanf("%s", a.name);	//구조체 변수에 멤버 입력
	printf("번지수: "); scanf("%s", a.num);	//구조체 변수에 멤버 입력
	printf("층수: "); scanf("%d", &a.a);	//구조체 변수에 멤버 입력
	printf("가격: "); scanf("%d", &a.b);	//구조체 변수에 멤버 입력
	return a;	//a값 반환 및 종료
}

int main()	//메인함수
{
	Person man = ReadPersonInfo();	//구조체 변수 선언 및 함수 호출

	printf("\n");					//줄 바꿈  
	Bui a = Read();					//구조체 변수 선언 및 함수 호출

	printf("\n");					//줄 바꿈  
	ShowPersonInfo(man,a);			//함수 호출
	system("PAUSE");	//일시정지  
	return 0;	//메인함수 종료
}
