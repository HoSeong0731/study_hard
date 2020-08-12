#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computer(void)	//��ǻ�� ���� �Լ� 
{
	int sel = rand() % 3 + 1;	//������ ���ϱ� 
	if (sel == 1)
		printf("��ǻ�ʹ� ���� ����, ");
	else if (sel == 2)
		printf("��ǻ�ʹ� ���� ����, ");
	else
		printf("��ǻ�ʹ� �� ����, ");

	return sel;
}

int user(void)	//���� UI �Լ� 
{
	int sel;
	printf("������ 1, ������ 2, ���� 3 : ");
	scanf("%d", &sel);	//���� ���� 
 
	if (sel == 1)
		printf("����� ���� ����, ");
	else if (sel == 2)
		printf("����� ���� ����, ");
	else
		printf("����� �� ����, ");

	return sel;
}

int WhoWin(int s1, int s2)	//���� �̱��� ���ϴ� �Լ�
{
	if (s1 == s2)	// ���º� 
		return 0;
	else if (s1 % 3 == (s2 + 1) % 3)	// ��ǻ�� ��
		return 1;
	else			// ���� �� 
		return -1;
}

int main(void) 
{
	int com, usr;	//��ǻ�Ϳ� �������� 
	int result;		//�ݺ��� ���� Ż�� 
	int win = 0, same = 0;	//��, ���� ��� 
	srand((int)time(NULL));	//������ 

 	while (1)	//���ѹݺ�(���ǿ� ������ ����)
	{
		usr = user();		//������ ���� UI����
		com = computer();	//��ǻ�� �ڵ����� 
		result = WhoWin(com, usr);		//���� �̱���� ���ϴ� �Լ� ���� 

		if (result == 1)
		{
			printf("����� �̰���ϴ�. \n");
			win++;	//�¸����� 
		}
		else if (result == -1)
		{
			printf("����� �����ϴ�. \n");
			break;	//�ݺ��� Ż��
		}
		else
		{
			printf("�����ϴ�. \n");
			same++;	//���º����� 
		}
	}
	
	printf("������ ���: %d��, %d�� \n", win, same);	//�·� ��� 
	return 0;	//main�Լ�����
}
