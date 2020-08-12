#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char benglish[26] = {
   'A','B','C','D','E',
   'F','G','H','I','J',
   'K','L','M','N','O',
   'P','Q','R','S','T',
   'U','V','W','X','Y',
   'Z' };//����� ���� ����
char senglish[26] = {
   'a','b','c','d','e',
   'f','g','h','i','j',
   'k','l','m','n','o',
   'p','q','r','s','t',
   'u','v','w','x','y',
   'z' };//�Է¹ޱ� ���� ����
char* mos[26] = {
   ".-","-...","-.-.","-..",".",
   "..-.","--.","....","..",".---",
   "-.-",".-..","--","-.","---",
   ".--.","--.-",".-.","...","-",
   "..-","...-",".--","-..-","-.--",
   "--.." };//�𽺺�ȣ

int error1(char input, int num)//ù���� �Է� �� �����̽��� �Ǵ� ���͸� �Է��Ͽ���.
{
	if ((input == ' ' || input == '\n') && num == 0)
		return 1;
}
int error2(char input, int mos, int english)//�𽺺�ȣ�� �ԷµǴ� ����� ���Ͽ���.
{
	if (mos == 1 && english == 1)
		return 1;

}
int error3(char input)//�ٸ� ���ڰ� ��� �� ���
{
	if (input == 45 || input == 46)
		return 0;
	else if (input == 10 || input == 32)
		return 0;
	else if ((input > 96 && input < 123) || (input > 64 && input < 91))
		return 0;
	else
		return 1;
}



int main()
{

	char input, getin[1][10] = { 0 }, mos_jump[2] = { 0 };
	int i, k, num1 = 0, up = 0, exit = 0, mos_use = 0, english_use = 0, jump = 0;// i �ݺ����� ����
	int break1 = 0, break2 = 0, break3 = 0;
	char* English = (char*)calloc(30, sizeof(char));
	char* Mos = (char*)calloc(30, sizeof(char));
	int text, print = 0;


	while (1)
	{
		printf("In:");
		do {

			input = getchar();

			break1 = error1(input, num1);
			break2 = error2(input, mos_use, english_use);
			break3 = error3(input);
			num1 = 1;//45= "-",46=".", 32=" ", 10="\n"
			if (break1 == 1)
			{
				exit = 1;
				printf("�����Դϴ�. ���α׷��� �����մϴ�.");
				break;
			}
			if (break2 == 1)
			{
				exit = 1;
				printf("\n�ڵ带 �ؼ��ϴ� �� �ٸ� �� ���Խ��ϴ�. ���α׷��� �����մϴ�.");
				break;
			}
			if (break3 == 1)
			{
				exit = 1;
				printf("\n��� �𽺺�ȣ�� �ƴ� �ٸ� ���� �Է��߽��ϴ�. ���α׷��� �����մϴ�.");
				break;
			}

			if (print == 0)
				printf("Out:");

			if ((input == '\n' && mos_use == 1) || (input == 32 && mos_use == 1))
			{
				for (i = 0; i < 26; i++)//�𽺺�ȣ�� �Է� �޾��� ��
				{

					if (!strcmp(getin[0], mos[i]))
					{
						printf("%c", benglish[i]);
						mos_jump[0] = 0;
						mos_jump[1] = 0;
						for (k = 0; k < 10; k++)
							getin[0][k] = 0;
						break;
					}
				}
			}

			english_use = 1;
			if (english_use == 1)
			{
				for (i = 0; i < 26; i++)//��� �Է� �޾��� ��
				{
					if (input == senglish[i] || input == benglish[i])//��ġ �� ������ �ϳ��� ���� �޴´�.
					{
						printf("%s ", mos[i]);
					}
				}
				if (input == 32)
				{
					printf(" ");
				}
			}
			if (input == 32 && mos_use == 1)
			{
				up = 0;
				mos_jump[jump] = input;
				jump++;
			}
			else if ((input > 96 && input < 123) || (input > 64 && input < 91))//a=97, z=122, A=65, Z=90
				english_use = 1;

			else if (input == 45 || input == 46)
			{
				getin[0][up] = input;
				up++;
				mos_use = 1;
				jump = 0;
			}
			if (mos_jump[0] == 32 && mos_jump[1] == 32)
				printf(" ");
			print = 1;
		} while (input != '\n');


		if (exit == 1)//ù ��° �������� �ɸ� ��� ����
			break;
		else if (exit == 0)
			break;
	}

	return 0;
}