#include <stdio.h>

//���ڿ��� ����� �������� ��µǰ� �����. 100�� ������ ���ڿ���

char contrast_str(char *words, char *words1);

int main()

{
	char words[100];
	char words1[100];
	int i;
	printf("�迭�� �ٲٰ� ���� ���ڿ��� �Է��Ͻʽÿ�. \n");
	scanf("%s", words);
	printf("���ڿ��� �迭�� �ٲߴϴ�. \n");
	contrast_str(words, words1);			//���ڿ��� �迭�� �ٲٴ� �Լ� ȣ��
	printf("�ٲ� ���ڿ� : %s \n", words1);
	return 0;

}

char contrast_str(char *words, char *words1)

{
	int i, j;
	for (j = 0; j < 100; j++)
	{		
		if (words[j] == '\0')
		{
			i = j;				//���ڿ��� �� ���ڷ� �Ǿ��ִ��� ���
		}
	}

	for (j = 0; j < i; j++)
	{
		words1[j] = words[i - 1 - j]; //���ڿ� ������ ������ NULL �� �Ǿ� ������ �������� NULL ���� ������ �� �ǹǷ� -1 �߰�
	}

	words1[i] = '\0'; // �������� NULL �� �־� �ش�.(���ڿ��� ����� ����.)
	return 0;
}
//�ɸ��ð� 50��
