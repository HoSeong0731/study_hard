#include<stdio.h>
int main()
{
	int cur, is;
	for (cur = 2; cur < 10; cur++)			// cur = 앞의 수를 정의 즉 2단부터 시작하며 9단까지만 하게 함.
	{
		for (is = 1; is < 10; is++)			// is = 뒤의 수를 정의 즉 1부터 시작해 9까지만 출력
		{
			printf("%d X %d = %-3d \n", cur, is, cur*is);		//%-3d로 공간확보

		}
	}
	return 0;
}
