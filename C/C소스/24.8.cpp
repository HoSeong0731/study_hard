#include <stdio.h>	//ǥ�ض��̺귯��

typedef struct fren	//����ü fren�� ���ǿ� Friend�� ���� typedef ������ ���� ����
{
	char name[10];	//�̸� ����
	char sex;		//���� ����
	int age;		//���� ����

}Friend;

typedef struct bui	//����ü fren�� ���ǿ� Bill�� ���� typedef ������ ���� ����
{
	char build[10];	//�ǹ� �̸� ����
	char num[10];	//�ǹ� ���� ����
	int a;			//���� ����
	int b;			//���� ����
}Building;

int main()	//�����Լ�
{
	FILE * fp;		//��Ʈ��(���) 
	FILE * ppt;		//��Ʈ��(�ǹ�) 
	Friend myfren1;	//����ü ���� ����
	Friend myfren2;	//����ü ���� ����
	Building bui1;	//����ü ���� ����
	Building bui2;	//����ü ���� ����

	/*** file write***/
	fp = fopen("friend.bin", "wb");		//���� ��Ʈ��(���) 

	printf("�̸�, ����, ���� �� �Է�: ");
	scanf("%s %c %d", myfren1.name,&(myfren1.sex),&(myfren1.age));
	//myfren1�� ��� fren�� �����Ͽ� �Է�
	fwrite((void*)& myfren1, sizeof(myfren1), 1, fp);	//myfren1�� ũ���� 1���� fp���� myfren1�� ����
	fclose(fp);							//��Ʈ���� ����

	ppt = fopen("Building.bin", "wb");	//���� ��Ʈ��(�ǹ�) 

	printf("�ǹ��̸�, ������, ����, ���� �� �Է�:");
	scanf("%s %s %d \n", bui1.build, bui1.num, &(bui1.a));
	scanf("%d", &(bui1.b));
	//Building�� ��� bui�� �����Ͽ� �Է�
	fwrite((void*)& bui1, sizeof(bui1), 1, ppt);		//bui1�� ũ���� 1���� ppt���� bui1�� ����

	fclose(ppt);	//��Ʈ�� ����
	/*** file read ***/

	fp = fopen("friend.bin", "rb");		//�б� ��Ʈ��(���) 

	fread((void*)&myfren2, sizeof(myfren2), 1, fp);		//myfren2�� ũ���� 1���� fp ���� myfren2�� �д´�
	printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);	//�� ����� �����Ͽ� ���
	fclose(fp);	//��Ʈ�� ����

	ppt = fopen("Building.bin", "rb");	//�б� ��Ʈ��

	fread((void*)&bui2, sizeof(bui2), 1, ppt);			//bui2�� ũ���� 1���� ppt���� bui2�� �д´�
	printf("%s %s %d %d \n", bui2.build, bui2.num, bui2.a, bui2.b);	//�� ����� �����Ͽ� ���
	fclose(ppt);	//��Ʈ�� ����
	return 0;		//0�� ��ȯ �� ����
}
