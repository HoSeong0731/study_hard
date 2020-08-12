#include <stdio.h>	//표준입출력 헤더파일 생성
int main()	//main함수
{
	double num = 3.14; //double형 변수 생성 
	double *ptr = &num;	//num을 가르키는 ptr생성 
	double**dptr = &ptr;//ptr을 가르키는 dptr생성(이중포인터) 
	double *ptr2;	//포인터변수 ptr2생성 
	
	printf("%9p %9p \n", ptr, *dptr); //ptr의 주소, dptr이 가르키는 것의 주소출력 
	printf("%9g %9g \n", num, **dptr);//num의 저장값, dptr이 가르키는 주소가 가르키는 곳의 저장값 출력 
	ptr2 = *dptr;	//ptr2는 dptr을 가르킴 
	*ptr2 = 10.99;	//ptr2는 10.99로 바뀌며 num값 바뀜 
	printf("%9g %9g \n", num, **dptr); //num값이 바뀌어 ptr값이 바뀌고, ptr값이 바뀌어 dptr값이 바뀜 
	return 0;	//메인함수종료
}
