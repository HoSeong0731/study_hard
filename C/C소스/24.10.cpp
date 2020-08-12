#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{
	long fpos;
	int i;
	/*파일생성*/
	FILE * fp = fopen("text.txt", "wt");	//쓰기 스트림
	fputs("0123456789-", fp);				//파일의 1~9입력
	fclose(fp);	//스트림의 종료
	/*파일개방*/
	fopen("text.txt", "rt");//읽기 스트림
	fseek(fp, 0, SEEK_SET);	//0
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 1, SEEK_SET);	//1
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 0, SEEK_SET);	//0
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, -1, SEEK_END);//-
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 2, SEEK_SET);	//2
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 5, SEEK_SET);	//5
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 7, SEEK_SET);	//7
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 0, SEEK_SET);	//0
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fpos = ftell(fp);		//현제위치 저장
	fseek(fp, -1, SEEK_END);//-
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 8, SEEK_SET);	//8
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 4, SEEK_SET);	//4
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 7, SEEK_SET);	//7
	putchar(fgetc(fp));		//fp파일에 있는값 출력
	fseek(fp, 8, SEEK_SET);	//8
	putchar(fgetc(fp));		//fp파일에 있는값 출력

	fclose(fp);	//스트림의 종료
	return 0;	//0값 반환 및 종료
}

