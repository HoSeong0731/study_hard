#include<stdio.h>

const int BREAD=500;			//���� ���� ���� 
const int SNACK=700;			//������ ���� ���� 
const int DRINK=400;			//������� ���� ���� 

int main(void)
{
	int bread, snack, drink;		//��, ����, ������� ������ �����ϱ� ���� ���� ����  
	int money;						//���� ������ �ݾ��� �Է¹ޱ� ���� ���� ����  
	printf("���� ����� �����ϰ� �ִ� �ݾ� : ");
	scanf("%d", &money); 			//���� �ں� �Է¹��� 

	for(bread=1; bread<money/BREAD; bread++)		//���� ���� < �����ݾ�/����  
	{
		for(snack=1; snack<money/SNACK; snack++)	//������ ���� < �����ݾ�/������ ��
		{
			for(drink=1; drink<money/DRINK; drink++)//������� ���� < �����ݾ�/������� ��
			{
				if(money==BREAD*bread+SNACK*snack+DRINK*drink)
				{
					printf("ũ���� %d��, ", bread);
					printf("����� %d��, ", snack);
					printf("��  �� %d�� \n", drink);
				}
			}
		}
	}

	printf("��� �����Ͻðڽ��ϱ�? \n");
	return 0;
}

/*
�Ҽ��ڵ� ����(3500���϶� ����) 
��:1 ����:1 �����:1
��:1 ����:1 �����:2
 ...
��:1 ����:1 �����7 
(3500/8�� 8.xx���� int���̹Ƿ� �Ҽ����� ������Ƿ� 7������ ����) 
��:1 ����2: �����1 
(for�� �ϳ� ���ͼ� ���ڷ� �Ѿ���Ƿ� ������� 1�� �ʱ�ȭ) 
 ...
��:1 ����2: �����4(if���ǿ� �����Ƿ� ���) 
*/
 
