#include <stdio.h>		//표준 라이브러리 함수
int main()				//메인함수
{
	int ch, i;			//출력할 변수와 반복문을 위한 변수 선언
	FILE *fp = fopen("data.txt", "rt");	//읽기스트림  
	if (fp == NULL) {	//fp가 NULL값일 경우 실행
		puts("파일 오픈 실패!");
		return -1;		//비정상적인 종료를 의미하기 위해 -1을 반환
	}

	for (i = 0; i < 10; i++)	//출력을 위한 반복문
	{
		ch = fgetc(fp);		//fp로부터 하나의 문자를 읽어서 변수 ch에 저장
		printf("%c \n", ch);//출력을 위해
		
	}
	fclose(fp);		//스트림의 종료
	return 0;		//0값 반환 및 종료
}


