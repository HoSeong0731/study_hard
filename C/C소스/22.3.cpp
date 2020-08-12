#include <stdio.h>	//입출력 헤더파일  

struct point	//point구조체 생성  
{
	int xpos;
	int ypos;
};

struct person	//person구조체 생성  
{
	char name[20];
	char phoneNum[20];
	int age;
	int grade; 
};

struct building	//building구조체 생성  
{
	char name[20];
	char number[20];
	int floor[3];
	char price[10];
};

int main()	//main함수  
{
	struct point pos={10, 20};	//구조체 point변수 생성 및 값 넣음  
	struct person man = {"김호성", "010-2570-8478", 20, 3.3};	//구조체 person변수 생성 및 값 넣음 
	struct building group = {"청춘시대", "429-8", 2, 1000.50};	//구조체 building변수 생성 및 값 넣음 
	
	printf("%d %d \n", pos.xpos, pos.ypos); //출력  
	printf("%s %s %d %d \n", man.name, man.phoneNum, man.age, man.grade); 
	printf("%s %s %d %s \n", group.name, group.number, group.floor, group.price); 
	return 0; //main함수 종료  
}
