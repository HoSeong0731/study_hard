#include <stdio.h>	//����� ������� 
#include <string.h>	//���ڿ� �������
 
struct person	//person����ü ����  
{
	char name[20];
	char phoneNum[20];
	int age;
};
int main()	//main�Լ�  
{
	struct person man1, man2;	//����ü ���� man1, man2����  
	strcpy(man1.name, "��ȣ��");	//man1�� ��� name�� �� ����  
	strcpy(man1.phoneNum, "010-2570-8478");	//man1�� ��� phonenum�� �� ���� 
	man1.age=20;	//man1�� ��� age�� �� ����  
	
	printf("�̸� �Է�: "); scanf("%s", man2.name);	//man2 ��� �Է¹���  
	printf("��ȣ �Է�: "); scanf("%s", man2.phoneNum);
	printf("���� �Է�: "); scanf("%d", &(man2.age));
	
	printf("�̸�: %s \n", man1.name);	//man1 ���  
	printf("��ȣ: %s \n", man1.phoneNum);
	printf("����: %d \n", man1.age);
	
	printf("�̸�: %s \n", man2.name);	//man2 ���  
	printf("��ȣ: %s \n", man2.phoneNum);
	printf("����: %d \n", man2.age);
	return 0;	//�����Լ� ����  
}
