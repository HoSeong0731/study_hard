#include <stdio.h>	//ǥ�� ����� ���̺귯��
#include <windows.h>//������ �������  

struct point	//����ü point�� ���ǿ� Point�� ���� typedef ������ ���� ����
{
	int xpos;	//��ǥ �� ����
	int ypos;	//��ǥ �� ����
};
typedef struct point Point;

typedef struct person	//����ü person�� ���ǿ� Person�� ���� typedef ������ ���� ����
{
	char name[20];		//�̸� ����
	char phoneNum[20];	//��ȣ ����
	int age;			//���� ����
} Person;

typedef struct building	//����ü building�� ���ǿ� Bui�� ���� typedef ������ ���� ����
{
	char name[20];	//�ǹ� �̸� ����
	char number[20];//������ ����
	int floor;		//���� ����
	int price;		//���� ����
} Bui;

int main()	//�����Լ�
{

	Point pos = { 10,20 };	//����üPoint ���� pos����  
	Person man = { "��ȣ��", "010-2570-8478", 20 };	//����üPerson ����man����
	Bui Bu = { "û��ô�", "429-8", 6, 1000 };		//����üBui ����Bu����
	printf("%d %d \n", pos.xpos, pos.ypos);			//���  
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);				//���
	printf("%s %s %d %d \n", Bu.name, Bu.number, Bu.floor, Bu.price);	//���
	system("PAUSE");	//�Ͻ�����  
	return 0;	//�����Լ� ����
}
