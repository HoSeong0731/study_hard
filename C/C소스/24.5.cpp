#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{
	FILE * src = fopen("data24.4.txt", "rt");	//읽기 스트리밍
	FILE * des = fopen("data24.44.txt", "wt");	//쓰기 스트리밍
	char str[20];								//문자열을 저장하기 위한 배열

	if (src == NULL || des == NULL) {	//두개중 하나라도 만족하지 않을 시 실행하지 않음
		puts("파일 오픈 실패!");
		return -1;						//비정상적인 종료를 위해 -1 값을 반환
	}
	while (fgets(str, sizeof(str), src) != NULL)//파일의 끝을 확인하기 위함 입력함수는 오류가 발생하여도 OEF를 반환
		fputs(str, des);						//str에 있던 값을 저장해뒀던 값 des에 복사
	if (feof(src) != 0)							//EOF반환원인을 학인하기 위함
		puts("파일복사 완료!");
	else
		puts("파일복사 실패!");
	fclose(src);	//스트림의 종료
	fclose(des);	//스트림의 종료
	
	FILE * fp = fopen("data.txt", "rt");		//읽기스트림  
	FILE * des2 = fopen("data24.44.txt", "wt");	//쓰기 스트림  
	char tstr[20];	//배열

	if (fp == NULL || des2 == NULL) {		//둘중하나라도 만족하지 않을 경우 실행하지 않음
		puts("파일 오픈 실패!");
		return -1;								//비정상적인 종료를 위해 -1 값을 반환
	}
	while (fgets(tstr, sizeof(fp), fp) != NULL)	//파일의 끝을 확인하기 위함 입력함수는 오류가 발생하여도 OEF를 반환
		fputs(tstr, des2);						//strs에 있던 값을 저장해뒀던 값을 dst에 복사
	if (feof(fp) != 0)							//EOF반환원인을 학인하기 위함
		puts("파일복사 완료!");
	else
		puts("파일복사 실패!");
	fclose(fp);		//스트림의 종료
	fclose(des2);	//스트림의 종료
	return 0;		//0값 반환 및 종료
}
