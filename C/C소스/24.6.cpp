#include <stdio.h>	//표준라이브러리
int main()			//메인함수
{	
	FILE * src = fopen("data24.4.bin", "rb");	//바이너리 모드로 파일을 읽는다
	FILE * des = fopen("data24.44.bin", "wb");	//바이너리 모드로 파일을 쓴다
	char buf[20];	//문자형 배열을 생성
	int readCnt;
	if (src == NULL || des == NULL) {	//두 함수 모두 null값일떄 실행
		puts("파일오픈 실패!");
		return -1;						//비정상적인 종료를 위해 -1 값을 반환
	}
	while (1)	//무한반복
	{
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
			//1의 크기의 데이터를 buf의 크기만큼 buf에서 읽어서 src에 저장해라
		if (readCnt < sizeof(buf))	//readCnt의 크기가 buf의 크기보다 작을 경우 실행
		{	//크기가 같지 않을 떄
			if (feof(src) != 0)		//EOF반환원인을 확인
			{
				fwrite((void*)buf, 1, readCnt, des);
				//1크기의 데이터 readCnt개를 buf으로 부터 읽어서 des에 저장한다
				puts("파일복사 완료");
				break;	//가까운 반복문을 탈출한다.
			}

			else	//위 조건과 일치하지 않을 경우 실행
				puts("파일복사 실패");
			break;	//가까운 반복문을 탈출한다
		}
		fwrite((void*)buf, 1, sizeof(buf), des);//크기가 같을떄
		//1크기의 데이터 but의 크기만큼 buf로 부터 읽어서 des에 저장한다.
	}
	fclose(src);	//스트림의 종료
	fclose(des);	//스트림의 종료
	return 0;		//0값 반환 및 종료
}

