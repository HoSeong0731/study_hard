#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{	
	FILE * src = fopen("data24.4.bin", "rb");	//���̳ʸ� ���� ������ �д´�
	FILE * des = fopen("data24.44.bin", "wb");	//���̳ʸ� ���� ������ ����
	char buf[20];	//������ �迭�� ����
	int readCnt;
	if (src == NULL || des == NULL) {	//�� �Լ� ��� null���ϋ� ����
		puts("���Ͽ��� ����!");
		return -1;						//���������� ���Ḧ ���� -1 ���� ��ȯ
	}
	while (1)	//���ѹݺ�
	{
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
			//1�� ũ���� �����͸� buf�� ũ�⸸ŭ buf���� �о src�� �����ض�
		if (readCnt < sizeof(buf))	//readCnt�� ũ�Ⱑ buf�� ũ�⺸�� ���� ��� ����
		{	//ũ�Ⱑ ���� ���� ��
			if (feof(src) != 0)		//EOF��ȯ������ Ȯ��
			{
				fwrite((void*)buf, 1, readCnt, des);
				//1ũ���� ������ readCnt���� buf���� ���� �о des�� �����Ѵ�
				puts("���Ϻ��� �Ϸ�");
				break;	//����� �ݺ����� Ż���Ѵ�.
			}

			else	//�� ���ǰ� ��ġ���� ���� ��� ����
				puts("���Ϻ��� ����");
			break;	//����� �ݺ����� Ż���Ѵ�
		}
		fwrite((void*)buf, 1, sizeof(buf), des);//ũ�Ⱑ ������
		//1ũ���� ������ but�� ũ�⸸ŭ buf�� ���� �о des�� �����Ѵ�.
	}
	fclose(src);	//��Ʈ���� ����
	fclose(des);	//��Ʈ���� ����
	return 0;		//0�� ��ȯ �� ����
}

