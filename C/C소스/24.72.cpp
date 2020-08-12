#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{
	char name[20];	//문자열 선언
	char sex;		//문자 변수 선언
	int age;		//변수 선언
	FILE * fp = fopen("data24.7.txt", "rt");	//읽기 스트림
	int i;			//반복문을 위한 변수 선언

	int ret;	//변수 선언
	while (1)	//무한반복
	{
		ret = fscanf(fp, "%s %c %d", name, &sex, &age);
		//fp에서 name,sex,age값을 읽어 온다
		if (ret == EOF)	//ret값이 EOF일때 실행한다
			break;		//반복문을 탈출한다.
		printf("%s %c %d \n", name, sex, age);
	}
	fclose(fp);	//스트림의 종료
	return 0;	//0값 반환 및 종료
}

