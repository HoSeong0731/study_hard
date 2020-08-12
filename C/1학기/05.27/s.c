#include <stdio.h>

void bubble(int *);

void print(int *);



void main() {


	int* a[9];
	int* p = a;
	for (int i = 0; i < 9; i++)		//입력 받기
	{
		printf("0~9사이의 숫자 한번씩 입력 %d번째", i + 1);
		scanf("%d", p++);		//후위 증가로 포인터 1~9까지 입력받게 함.
	}
	bubble(a);
	return 0;
}

void bubble(int *a) {

	int temp;
	printf("정렬 전 배열 a");
	print(a);			//초기에 받은 값 출력

	for (int i = 0; i < 8; i++) {			//8번 비교 후 다시 (1,2)값 비교로 돌아옴

		for (int j = 0; j < 8; j++) {		//1.(1,2)값 비교, 2. (2,3)값 비교....

			if (*(a + j) > *(a + j + 1)) {

				temp = *(a + j + 1);			//(a+j+1)번째 값을 temp에 저장

				*(a + j + 1) = *(a + j);		//(a+j+1)번째 값과 (a=j)값을 같게 해서 (a+j)값으로 (a+j+1)값 변경

				*(a + j) = temp;				//(a=j)값을 temp와 같게 해서 (a+j+1)번째 값으로 (a+j)값 변경

			}
			

		}
		

	}
		printf("정렬 후 배열 a");
		print(a);		//변경값출력
		printf("\n");

}

void print(int *a) {

	for (int i = 0; i < 9; i++)

		printf("%3d", *(a + i));		//3칸확보후 a+i값 출력

	printf("\n");		//9개 출력후 줄바꿈

}

