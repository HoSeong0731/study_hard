#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{
	/*파일생성*/
	FILE *fp = fopen("text.txt", "wt");	//쓰기 스트림
	fputs("ABCDEFGHIJKLM", fp);			//파일에 A~M까지 입력한다
	fclose(fp);		//스트림의 종료
	/*파일개방*/
	fopen("text.txt", "rt");	//읽기 스트림
	/*SEEK_END test*/
	fseek(fp, -2, SEEK_END);	//끝에서 두번 앞으로 간다
	putchar(fgetc(fp));
	/*SEEK_SET test*/
	fseek(fp, 2, SEEK_SET);		//처음위치에서 뒤로 두번 간다
	putchar(fgetc(fp));
	/*SEEK_CUR test*/
	fseek(fp, 2, SEEK_CUR);		//현위치에서 두번 뒤로 간다
	putchar(fgetc(fp));
	fclose(fp);					//스트림의 종료
	return 0;					//0값 반환 및 종료
}

