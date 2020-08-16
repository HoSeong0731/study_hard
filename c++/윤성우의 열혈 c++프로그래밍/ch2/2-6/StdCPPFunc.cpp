/*
C++에서 C언어의 표준함수 호출하기
c를 더하고 .h를 빼라
ex) stdio.h -> cstdio, stdlib.h -> cstdlib
*/
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char str1[]="Result";
	char str2[30];
	
	strcpy(str2, str1);
	printf("%s: %f \n", str1, sin(0.14));
	printf("%s: %f \n", str2, abs(-1.25));
	return 0;
}
