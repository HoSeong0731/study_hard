#include <stdio.h> 	//표준 입출력 라이브러리
#include <windows.h>//윈도우 헤더파일  

typedef struct student	//구조체 student의 정의와 Student에 대한 typedef 선언을 위해 몪음
{
	char name[20];	//이름 저장
	char stdnum[20];//학번 저장
	char school[20];//학교 이름저장
	char major[20];	//전공 저장
	int year;		//학년 저장
}Student;

typedef struct building	//구조체 bill의 정의와 Bill에 대한 typedef 선언을 위해 몪음
{
	char name[20];	//건물이름 저장
	char num[20];	//번지 저장
	int a;			//층수 저장
	int b;			//가격 저장
}Bui;

void Show(Bui * pptr)	//건물정보 출력하기 위한 함수 정의
{
	printf("건물이름: %s \n", pptr->name);	//구조체 변수에 멤버 출력
	printf("건물 번지: %s\n", pptr->num);	//구조체 변수에 멤버 출력
	printf("건물층수: %d \n", pptr->a);		//구조체 변수에 멤버 출력
	printf("건물 가격: %d\n", pptr->b);	//구조체 변수에 멤버 출력
}

void ShowStudentInfo(Student *sptr)	//학생정보 출력하기 위한 함수 정의
{
	printf("학생 이름: %s \n", sptr->name);			//구조체 변수에 멤버 출력
	printf("학생 고유번호: %s \n", sptr->stdnum);	//구조체 변수에 멤버 출력
	printf("학교 이름: %s \n", sptr->school);		//구조체 변수에 멤버 출력
	printf("선택 전공: %s \n", sptr->major);		//구조체 변수에 멤버 출력
	printf("학년: %d \n", sptr->year);				//구조체 변수에 멤버 출력
}

int main()	//메인함수
{
	Student arr[7];	//구조체Student 배열arr[7] 선언
	Bui bbb[3];		//구조체Bui 배열bbb[3] 선언
	int i;			//반복을 위한 변수i 선언

	for (i = 0; i < 1; i++)	//정보를 입력 받기 위한 반복문
	{
		printf("이름:"); scanf("%s", arr[i].name);	//구조체 변수 멤버 입력
		printf("번호:"); scanf("%s", arr[i].stdnum);//구조체 변수 멤버 입력
		printf("학교:"); scanf("%s", arr[i].school);//구조체 변수 멤버 입력
		printf("전공:"); scanf("%s", arr[i].major);	//구조체 변수 멤버 입력
		printf("학년:"); scanf("%d", &arr[i].year);	//구조체 변수 멤버 입력
	}
	for (i = 0; i < 1; i++)	//정보를 입력 받기 위한 반복문
	{
		printf("건물이름:"); scanf("%s", bbb[i].name);	//구조체 변수 멤버 입력
		printf("번지 수:"); scanf("%s", bbb[i].num);	//구조체 변수 멤버 입력
		printf("층수:"); scanf("%d", &bbb[i].a);		//구조체 변수 멤버 입력
		printf("가격:"); scanf("%d", &bbb[i].b);		//구조체 변수 멤버 입력
	}
	for (i = 0; i < 1; i++)	//출력을 위한 반복문
	{
		ShowStudentInfo(&arr[i]);	//함수 호출
	}
	for (i = 0; i < 1; i++)			//출력을 위한 반복문
	{
		Show(&bbb[i]);	//함수 호출
	}
	system("PAUSE");	//일시정지  
	return 0;	//메인함수 종료
}

