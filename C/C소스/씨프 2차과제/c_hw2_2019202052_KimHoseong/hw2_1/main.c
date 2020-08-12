#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char benglish[26] = {
   'A','B','C','D','E',
   'F','G','H','I','J',
   'K','L','M','N','O',
   'P','Q','R','S','T',
   'U','V','W','X','Y',
   'Z' };//출력을 위한 영어
char senglish[26] = {
   'a','b','c','d','e',
   'f','g','h','i','j',
   'k','l','m','n','o',
   'p','q','r','s','t',
   'u','v','w','x','y',
   'z' };//입력받기 위한 영어
char* mos[26] = {
   ".-","-...","-.-.","-..",".",
   "..-.","--.","....","..",".---",
   "-.-",".-..","--","-.","---",
   ".--.","--.-",".-.","...","-",
   "..-","...-",".--","-..-","-.--",
   "--.." };//모스부호

int error1(char input, int num)//첫번쨰 입력 때 스페이스바 또는 엔터를 입력하였다.
{
	if ((input == ' ' || input == '\n') && num == 0)
		return 1;
}
int error2(char input, int mos, int english)//모스부호가 입력되다 영어로 변하였다.
{
	if (mos == 1 && english == 1)
		return 1;

}
int error3(char input)//다른 문자가 들어 갈 경우
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
	int i, k, num1 = 0, up = 0, exit = 0, mos_use = 0, english_use = 0, jump = 0;// i 반복문을 위함
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
				printf("예외입니다. 프로그램을 종료합니다.");
				break;
			}
			if (break2 == 1)
			{
				exit = 1;
				printf("\n코드를 해석하던 중 다른 언어가 들어왔습니다. 프로그램을 종료합니다.");
				break;
			}
			if (break3 == 1)
			{
				exit = 1;
				printf("\n영어나 모스부호가 아닌 다른 값을 입력했습니다. 프로그램을 종료합니다.");
				break;
			}

			if (print == 0)
				printf("Out:");

			if ((input == '\n' && mos_use == 1) || (input == 32 && mos_use == 1))
			{
				for (i = 0; i < 26; i++)//모스부호를 입력 받았을 때
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
				for (i = 0; i < 26; i++)//영어를 입력 받았을 때
				{
					if (input == senglish[i] || input == benglish[i])//일치 할 때마다 하나씩 값을 받는다.
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


		if (exit == 1)//첫 번째 오류에서 걸릴 경우 종료
			break;
		else if (exit == 0)
			break;
	}

	return 0;
}