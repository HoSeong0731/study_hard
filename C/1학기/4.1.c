//출력결과 정삼각형 찍기
//출력결과 직각삼각형 찍기

#include <stdio.h>
int main()
{
	//정삼각형빌드	(%-ns를 한줄씩 내려가면서 -1취해 정삼각형을 만듦.)
	printf("%-8s *\n");
	printf("%-7s * *\n");
	printf("%-6s * * *\n\n\n");

	//직각삼각형빌드 (%-8s는 간격확보용.)
	printf("%-8s*\n");
	printf("%-8s**\n");
	printf("%-8s* *\n");
	printf("%-8s****");
	return 0;
}
