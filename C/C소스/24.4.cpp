#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{
	FILE * src = fopen("data24.4.txt", "rt");	//읽기 스트리밍
	FILE * des = fopen("data24.44.txt", "wt");	//쓰기 스트리밍
	FILE * abc = fopen("data.txt", "rt");		//읽기 스트리밍
	int ch;//변수 선언
	if (src == NULL || des == NULL||abc==NULL)//3함수중 하나라도 null이라면 실행하지 않음
	{
		puts("파일오픈 실패!");
		return -1;				//비정상적인 종료를 위해 -1 값을 반환
	}
	while ((ch = fgetc(abc)) != EOF)	//파일의 끝을 확인하기 위함 입력함수는 오류가 발생하여도 OEF를 반환
		fputc(ch, des);					//data에 있던 값을 저장해뒀던 변수를 dst에 복사
	if (feof(abc) != 0)					//EOF반환원인을 학인하기 위함
		puts("파일 복사 완료!");
	else
		puts("파일 복사 실패!");
	fclose(abc);	//스트림의 종료
	fclose(src);	//스트림의 종료
	fclose(des);	//스트림의 종료
	return 0;		//0값 반환 및 종료
}

