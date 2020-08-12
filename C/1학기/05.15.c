#include <stdio.h>

//문자열을 뒤집어서 역순으로 출력되게 만든다. 100개 이하의 문자열로

char contrast_str(char *words, char *words1);

int main()

{
	char words[100];
	char words1[100];
	int i;
	printf("배열을 바꾸고 싶은 문자열을 입력하십시오. \n");
	scanf("%s", words);
	printf("문자열의 배열을 바꿉니다. \n");
	contrast_str(words, words1);			//문자열의 배열을 바꾸는 함수 호출
	printf("바뀐 문자열 : %s \n", words1);
	return 0;

}

char contrast_str(char *words, char *words1)

{
	int i, j;
	for (j = 0; j < 100; j++)
	{		
		if (words[j] == '\0')
		{
			i = j;				//문자열이 몇 글자로 되어있는지 계산
		}
	}

	for (j = 0; j < i; j++)
	{
		words1[j] = words[i - 1 - j]; //문자열 마지막 변수는 NULL 로 되어 있으나 역순에서 NULL 부터 나오면 안 되므로 -1 추가
	}

	words1[i] = '\0'; // 마지막엔 NULL 을 넣어 준다.(문자열로 만들기 위함.)
	return 0;
}
//걸린시간 50분
