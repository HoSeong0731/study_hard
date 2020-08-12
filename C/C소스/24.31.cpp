#include <stdio.h>	//표준라이브러리 함수

int main()			//메인함수
{
	FILE * fp = fopen("data2.txt", "wt");	//쓰기스트림
	if (fp == NULL) {						//fp가 NULL일 경우 실행
		printf("파일 오픈 실패!");
		return -1;							//비정상적인 종료를 의미하기 위해 -1을 반환
	}
	fputc('A', fp);			//문자 A를 fp가 가르키는 파일에 저장
	fputc('B', fp);			//문자 B를 fp가 가르키는 파일에 저장
	fputs("My name is Hong \n", fp);	//문자 My name is Hong를 fp가 가르키는 파일에 저장
	fputs("Your name is Yoon \n", fp);	//문자 Your name is Yoon를 fp가 가르키는 파일에 저장
	fputs("안녕하세요 \n", fp);			//문자 "안녕하세요"를 fp가 가르키는 파일에 저장
	fputs("저는 \n", fp);				//문자 저는 fp가 가르키는 파일에 저장
	fputs("김호성입니다. \n",fp);		//문자 김호성입니다.를 fp가 가르키는 파일에 저장
	fclose(fp);		//스트림의 종료
	printf("파일 오픈 성공!"); 
	return 0;		//0값 반환 및 종료
}
