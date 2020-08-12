#include <stdio.h>	//입출력 헤더파일
#include <math.h>	//수학관련 헤더파일

struct point	//point 라는 이름으; 구조체 선언
{
	int xpos;	//좌표 값 저장
	int ypos;	//좌표 값 저장
	struct point * ptr;	//구조체 변수의 멤버로 구조체 포인터 변수를 선언
};
int main()
{
	struct point pos1= {1 , 1};	//구조체 변수 선언
	struct point pos2= {2 , 2 };
	struct point pos3= {3 , 3 };
	int a, b, c;	//두 점 사이의 거리를 저장 할 변수
	pos1.ptr = &pos2;	//pos1과 pos2를 연결
	pos2.ptr = &pos3;	//pos2과 pos3를 연결
	pos3.ptr = &pos1;	//pos3과 pos1를 연결

	printf("점의 연결 관계----\n");
	printf("[%d, %d]와(과) [%d, %d] 연결 \n", pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
	printf("[%d, %d]와(과) [%d, %d] 연결 \n", pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
	printf("[%d, %d]와(과) [%d, %d] 연결 \n", pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
	
	printf("연결된 점들 간의 길이---\n");	//처음에는 자기 값을 출력한 다음 연산자를 기반으로 연결된 값을 출력
	a = sqrt((double)(pos1.xpos - pos1.ptr->xpos)*(pos1.xpos - pos1.ptr->xpos) + (pos1.ypos - pos1.ptr->ypos)*(pos1.ypos - pos1.ptr->ypos));
	b = sqrt((double)(pos2.xpos - pos2.ptr->xpos)*(pos2.xpos - pos2.ptr->xpos) + (pos2.ypos - pos2.ptr->ypos)*(pos2.ypos - pos2.ptr->ypos));
	c = sqrt((double)(pos3.xpos - pos3.ptr->xpos)*(pos3.xpos - pos3.ptr->xpos) + (pos3.ypos - pos3.ptr->ypos)*(pos3.ypos - pos3.ptr->ypos));
	//거리 구하는 공식
	
	printf("1번째 좌표:%d\n", a);
	printf("2번째 좌표:%d\n", b);
	printf("3번째 좌표:%d\n", c);
	return 0;	//main함수종료  
}

