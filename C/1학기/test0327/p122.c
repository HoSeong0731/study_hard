#include <stdio.h>
int main()
{
	printf("literal int size: %d \n", sizeof(7));			
	// int의 데이터크기를 묻는 것이다. int의 범위안에 있는 어떤 숫자를 입력하든 4가 출력된다.
	printf("literal double size: %d \n", sizeof(7.14));
	// double의 데이터크기를 묻는 것이다. double의 범위안에 있는 어떤 숫자를 입력하든 8이 출력된다.
	printf("literal char size: %d \n", sizeof('A'));
	// char의 데이터크기를 묻는 것이다. char의 범위안에 있는 어떤 숫자를 입력하든 4이 출력된다.
	printf("literal float size %d ", sizeof(float));
	// float의 데이터크기를 묻는 것이다. floatdl라는 자료형을 입력해도 바이트 수가 표현된다는 것을 보여주기 위해 float을 사용했다.
	return 0;

}