#include <Stdio.h>
int main()
{
	int arr[3] = { 11,22,33 };
	int *ptr = &arr[0];
	printf("%d, %d, %d", *ptr, *(ptr + 1), *(ptr + 2));

	printf("\n%d,", *ptr);  ptr++;
	printf("%d,", *ptr);  ptr++;
	printf("%d,", *ptr);  ptr--;
	printf("%d,", *ptr);  ptr--;
	printf("%d", *ptr);  printf("\n");

	printf("�ҽ��ڵ� ���� ���� \n");
	printf("%d,", *ptr++);
	printf("%d,", *ptr++);
	printf("%d,", *ptr--);
	printf("%d,", *ptr--);
	printf("%d", *ptr);

	return 0;

}