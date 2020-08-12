#include <stdio.h>	//표준라이브러리

typedef struct fren	//구조체 fren의 정의와 Friend에 대한 typedef 선언을 위해 묶음
{
	char name[10];	//이름 저장
	char sex;		//성별 저장
	int age;		//나이 저장

}Friend;

typedef struct bui	//구조체 fren의 정의와 Bill에 대한 typedef 선언을 위해 묶음
{
	char build[10];	//건물 이름 저장
	char num[10];	//건물 번지 저장
	int a;			//층수 저장
	int b;			//가격 저장
}Building;

int main()	//메인함수
{
	FILE * fp;		//스트림(사람) 
	FILE * ppt;		//스트림(건물) 
	Friend myfren1;	//구조체 변수 선언
	Friend myfren2;	//구조체 변수 선언
	Building bui1;	//구조체 변수 선언
	Building bui2;	//구조체 변수 선언

	/*** file write***/
	fp = fopen("friend.bin", "wb");		//쓰기 스트림(사람) 

	printf("이름, 성별, 나이 순 입력: ");
	scanf("%s %c %d", myfren1.name,&(myfren1.sex),&(myfren1.age));
	//myfren1이 멤버 fren에 접근하여 입력
	fwrite((void*)& myfren1, sizeof(myfren1), 1, fp);	//myfren1의 크기의 1개를 fp에서 myfren1의 저장
	fclose(fp);							//스트림의 종료

	ppt = fopen("Building.bin", "wb");	//쓰기 스트림(건물) 

	printf("건물이름, 번지수, 층수, 가격 순 입력:");
	scanf("%s %s %d \n", bui1.build, bui1.num, &(bui1.a));
	scanf("%d", &(bui1.b));
	//Building이 멤버 bui에 접근하여 입력
	fwrite((void*)& bui1, sizeof(bui1), 1, ppt);		//bui1의 크기의 1개를 ppt에서 bui1의 저장

	fclose(ppt);	//스트림 종료
	/*** file read ***/

	fp = fopen("friend.bin", "rb");		//읽기 스트림(사람) 

	fread((void*)&myfren2, sizeof(myfren2), 1, fp);		//myfren2의 크기의 1개를 fp 에서 myfren2를 읽는다
	printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);	//각 멤버에 접근하여 출력
	fclose(fp);	//스트림 종료

	ppt = fopen("Building.bin", "rb");	//읽기 스트림

	fread((void*)&bui2, sizeof(bui2), 1, ppt);			//bui2의 크기의 1개를 ppt에서 bui2를 읽는다
	printf("%s %s %d %d \n", bui2.build, bui2.num, bui2.a, bui2.b);	//각 멤버에 접급하여 출력
	fclose(ppt);	//스트림 종료
	return 0;		//0값 반환 및 종료
}
