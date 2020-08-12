#include <stdio.h>	//입출력 헤더파일
#include <math.h>	//수학관련 헤더파일

struct point	//point 구조체 생성
{
	int xpos;
	int ypos;
};

int main()	//main함수  
{
	struct point pos1 ={1,2};	//입력(구조체 point) 
	struct point pos2 ={100,200};	//입력(구조체 point) 
	struct point * pptr = &pos1;	//입력(구조체 포인터) 
	
	(*pptr).xpos += 4;	//연산 
	(*pptr).ypos += 5;	//연산  
	
	pptr = &pos2;	//pos1에서 pos2로 변경 
	pptr ->xpos += 1;	//연산 
	pptr ->ypos += 2;	//연산  
		
	double distance=sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos)+(pos1.ypos-pos2.ypos)*(pos1.ypos-pos2.ypos)));
	//거리 연산  
	printf("%g",distance);	//출력 
	return 0; //메인함수 종료  
 } 
