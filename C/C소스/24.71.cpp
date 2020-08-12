#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{
	char name[20];	//문자열 선언
	char sex;		//문자 변수 선언
	int age;		//변수 선언
	FILE * fp = fopen("data24.7.txt", "wt");	//쓰기 스트림
	int i;			//반복문을 위한 변수 선언

	for (i = 0; i < 3; i++)	//값을 받기 위한 반복문
	{
		printf("이름 성별 나이 순 입력:");
		scanf("%s %c %d", name, &sex, &age);
		fflush(stdin);			//버퍼에 남아있는 \n의 소멸을 위해
		fprintf(fp, "%s %c %d \n ",name, sex, age);	//파일안에 출력
	}
	fclose(fp);	//스트림의 종료
	return 0;	//0값 반환 및 종료
}

