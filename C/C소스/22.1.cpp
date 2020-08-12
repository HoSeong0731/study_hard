#include <stdio.h>	//입출력 헤더파일 
#include <math.h>	//수학관련 헤더파일  
struct point	//point 구조체 생성  
{
	int xpos;
	int ypos;
};

int main()	//main함수  
{
	struct point pos1, pos2;	//구조체 변수 pos1, pos2생성  
	double distance;	//지름 구하기 위한 변수 생성  
	
	fputs("point1 pos: ", stdout);	 
	scanf("%d %d", &pos1.xpos, &pos1.ypos);	//pos1에 x,y 넣음  
	
	fputs("point2 pos: ", stdout);
	scanf("%d %d", &pos2.xpos, &pos2.ypos);	//pos2에 x,y 넣음  
	
	distance=sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos)+(pos1.ypos-pos2.ypos)*(pos1.ypos-pos2.ypos)));
	//sqrt = math헤더파일에 있는 수학함수로 제곱근을 반환한다. 
	printf("이 원의 지름은 %g이며, 넓이는 %g입니다.",distance, (distance/2)*(distance/2)*3.14);
	return 0;
}
