#include<stdio.h>	//ǥ��������������

void ClearLineFromReadBuffer()	//���ۿ� ���� �� ����� �Լ�  
{
	while(getchar()!='\n');	//getchar�� �ٳѱ��� ���ö����� ���� ����  
 } 
 
int main()
{
	char perID[7];	//ũ�Ⱑ 7�� 1���� �迭���� 
	char name[10];	//ũ�Ⱑ 10�� 1���� �迭����  
	
	fputs("�ֹι�ȣ�� 6�ڸ� �Է�: ",stdout);	//stdout�� ���� ����Ϳ� ���  
	fgets(perID, sizeof(perID), stdin);	//�ֹι�ȣ6�ڸ������� �Է�
	ClearLineFromReadBuffer();
	
	fputs("�̸� �Է�: ",stdout );	//stdout�� ���� ����Ϳ� ���  
	fgets(name, sizeof(name), stdin);	//�Է¹޾� name�迭�� ����  
	
	printf("�ֹι�ȣ: %s\n", perID);	//perID�� �Է¹��� �� ���  
	printf("�̸�: %s\n", name);	//name�� �Է¹��� �� ���  
	return 0;	//main�Լ� ����
}
