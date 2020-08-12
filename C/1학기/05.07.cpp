#include<stdio.h>

const int BREAD=500;			//빵의 가격 고정 
const int SNACK=700;			//과자의 가격 고정 
const int DRINK=400;			//음료수의 가격 고정 

int main(void)
{
	int bread, snack, drink;		//빵, 과자, 음료수의 갯수를 측정하기 위해 변수 생성  
	int money;						//현재 보유한 금액을 입력받기 위해 변수 생성  
	printf("현재 당신이 소유하고 있는 금액 : ");
	scanf("%d", &money); 			//현재 자본 입력받음 

	for(bread=1; bread<money/BREAD; bread++)		//빵의 개수 < 보유금액/빵값  
	{
		for(snack=1; snack<money/SNACK; snack++)	//과자의 개수 < 보유금액/과자의 값
		{
			for(drink=1; drink<money/DRINK; drink++)//음료수의 개수 < 보유금액/음료수의 값
			{
				if(money==BREAD*bread+SNACK*snack+DRINK*drink)
				{
					printf("크림빵 %d개, ", bread);
					printf("새우깡 %d개, ", snack);
					printf("콜  라 %d개 \n", drink);
				}
			}
		}
	}

	printf("어떻게 구입하시겠습니까? \n");
	return 0;
}

/*
소소코드 진행(3500원일때 가정) 
빵:1 과자:1 음료수:1
빵:1 과자:1 음료수:2
 ...
빵:1 과자:1 음료수7 
(3500/8은 8.xx지만 int형이므로 소수점이 사라지므로 7까지만 증가) 
빵:1 과자2: 음료수1 
(for문 하나 나와서 과자로 넘어갔으므로 음료수값 1로 초기화) 
 ...
빵:1 과자2: 음료수4(if조건에 맞으므로 출력) 
*/
 
