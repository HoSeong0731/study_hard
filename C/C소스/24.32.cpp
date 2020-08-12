#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{
	char str[30];	//배열 선언
	int ch;			//변수 선언
	FILE * fp = fopen("data2.txt", "rt");	//읽기 스트림
	if (fp == NULL)	//fp가 NULL일 경우 실행
	{	
		puts("파일오픈 실패!");
		return -1;	//비정상적인 종료를 위해 -1을 반환
	}

	ch = fgetc(fp);		//fp로 부터 하나의 문자를 읽어서 변수 ch에 저장
	printf("%c \n", ch);//받아온 변수를 출력
	ch = fgetc(fp);		//fp로 부터 하나의 문자를 읽어서 변수 ch에 저장
	printf("%c \n", ch);//받아온 변수를 출력
	fgets(str, sizeof(str), fp);//fp로 부터 문자열을 받아와 str에 \n이 나올때까지 저장
	printf("%s", str);			//받아온 배열을 출력
	fgets(str, sizeof(str), fp);//fp로 부터 문자열을 받아와 str에 \n이 나올때까지 저장
	printf("%s", str);			//받아온 배열을 출력
	fgets(str, sizeof(str), fp);//fp로 부터 문자열을 받아와 str에 \n이 나올때까지 저장
	printf("%s", str);			//받아온 배열을 출력
	fgets(str, sizeof(str), fp);//fp로 부터 문자열을 받아와 str에 \n이 나올때까지 저장
	printf("%s", str);			//받아온 배열을 출력
	fgets(str, sizeof(str), fp);//fp로 부터 문자열을 받아와 str에 \n이 나올때까지 저장
	printf("%s", str);			//받아온 배열을 출력

	fclose(fp);	//스트림의 종료
	return 0;	//0값 반환 및 종료
}

