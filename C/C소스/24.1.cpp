#include <stdio.h>	//표준라이브러리 함수
int main()			//메인함수
{
	FILE * fp =	fopen("data.txt", "wt");	//쓰기스트림
	//반환 값은 상태값으로 정수 값이여서 fp에 파일포인터가 들어가는게 아닌 정수값이 들어가게 됨
	
	if (fp == NULL)	//fp에 NULL값이 저장되 있을 경우 실행
	{
		puts("파일 오픈 실패!");
		return -1; 	//비정상적인 종료를 의미하기 위해 -1을 반환
	}
	
	fputc('A', fp);	//문자A를 fp가 가르키는파일에 저장한다.
	fputc('B', fp);	//문자B를 fp가 가르키는파일에 저장한다.
	fputc('C', fp);	//문자C를 fp가 가르키는파일에 저장한다.
	fputc('D', fp);	//문자D를 fp가 가르키는파일에 저장한다.
	fputc('E', fp);	//문자E를 fp가 가르키는파일에 저장한다.
	fputc('F', fp);	//문자F를 fp가 가르키는파일에 저장한다.
	fputc('G', fp);	//문자G를 fp가 가르키는파일에 저장한다.
	fputc('H', fp);	//문자H를 fp가 가르키는파일에 저장한다.
	fputc('I', fp);	//문자I를 fp가 가르키는파일에 저장한다.
	fclose(fp); 	//스트림의 종료
	printf("파일 오픈 성공!");
	return 0;	//값 반환 및 종료
}

