#include <stdio.h>
int main()
{
	double rad, area;
	printf("원의 반지름 입력:");		
	scanf("%lf", &rad);					//scanf에 \n 즉 줄바꿈문자가 들어가면 두번입력해야하는 오류가생긴다.(뒤에입력한 값은 무시된다.)

	area = rad * rad*3.1415;			//넓이 공식 R*R*θ
	printf("원의 넓이: %lf \n", area);
	return 0;
}