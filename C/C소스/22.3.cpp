#include <stdio.h>	//����� �������  

struct point	//point����ü ����  
{
	int xpos;
	int ypos;
};

struct person	//person����ü ����  
{
	char name[20];
	char phoneNum[20];
	int age;
	int grade; 
};

struct building	//building����ü ����  
{
	char name[20];
	char number[20];
	int floor[3];
	char price[10];
};

int main()	//main�Լ�  
{
	struct point pos={10, 20};	//����ü point���� ���� �� �� ����  
	struct person man = {"��ȣ��", "010-2570-8478", 20, 3.3};	//����ü person���� ���� �� �� ���� 
	struct building group = {"û��ô�", "429-8", 2, 1000.50};	//����ü building���� ���� �� �� ���� 
	
	printf("%d %d \n", pos.xpos, pos.ypos); //���  
	printf("%s %s %d %d \n", man.name, man.phoneNum, man.age, man.grade); 
	printf("%s %s %d %s \n", group.name, group.number, group.floor, group.price); 
	return 0; //main�Լ� ����  
}
