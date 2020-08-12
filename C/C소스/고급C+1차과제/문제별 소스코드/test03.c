#include <stdio.h>

void caln1(int *n0,int  *n1,int  *n2,int  *n3,int  *n4,int  *n5,int  *n6,int  *n7,int  *n8,int  *n9,int ha)
{ 
switch (ha) {	//스위치문법을 이용해 0~9중 숫자가 나올 시 값을 증가시킴  
    case 0:
      	*n0=*n0+1;
     	break;

	case 1:
		*n1=*n1+1;
		break;
		
    case 2:
     	*n2=*n2+1;
     	break;
	
    case 3:
     	*n3=*n3+1;
     	break;

    case 4:
      	*n4=*n4+1;
      	break;
      	
 	case 5:
      	*n5=*n5+1;
      	break;
    
    case 6:
      	*n6=*n6+1;
      	break;
      	
    case 7:
      	*n7=*n7+1;
      	break;
    
    case 8:
      	*n8=*n8+1;
      	break;
      	
    case 9:
      	*n9=*n9+1;
      	break;
  }
}

int main()
{
	int num1, num2, temp, n1, n2, n3, n4;	//입력받을 두 변수, 두 숫자중 큰 걸 뒤로 보낼 temp, 자릴 수 마다 분해할 변수생성   
	int x0 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, x9 = 0;	//0~9의 숫자 증가 변수  
	
	back:	
	printf("첫 번째 숫자를 입력해주세요(0~2000):");	 
	scanf_s("%d", &num1);	//첫 번째 숫자 입력받음  
		
	if(num1<0||num1>2000){		//예외처리  
		printf("첫 번째 숫자에 잘못된 값을 입력하셨습니다.\n");
		goto back;
	}
	
	printf("두 번째 숫자를 입력해주세요(0~2000):");
	scanf_s("%d", &num2);	//두 번째 숫자 입력받음  
	
	if(num2<0||num2>2000){		//예외처리  
		printf("두 번째 숫자에 잘못된 값을 입력하셨습니다.\n");
		goto back;
	}
	
	if(num1>num2)	//두 숫자 중 작은 숫자를 앞으로 보냄  
	{
		temp = num1;
        num1 = num2;
        num2 = temp;
	}

	while(num1<=num2){	//작은 숫자가 큰 숫자가 되면 반복문 종료  
	n1 = num1 / 1000;	//1000의 자리 계산  
	n2 = (num1 -(n1*1000)) / 100;	//100의 자리 계산  
	n3 = (num1 -(n1*1000)-(n2*100)) / 10;	//10의 자리 계산  
	n4 = num1 % 10;	//1의 자리 계산
	
	if(num1>=1000){	//1000의 자리일 경우 n1~n4숫자 전부 유효  
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n1);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n2);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n3);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}
	
	if(num1<1000 && num1>=100){	//100의 자리일 경우 n2~n4숫자만 유효   
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n2);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n3);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}

	if(num1<100 && num1>=10){	//10의 자리일 경우 n3~n4숫자만 유효 
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n3);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}
	
	if(num1<10){	//1의 자리일 경우 n4숫자만 유효  
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}
	num1++;	//반복문 탈출 조건  
	}
	
	printf("0: %d \n1: %d \n2: %d \n3: %d \n4: %d \n5: %d \n6: %d \n7: %d \n8: %d \n9: %d \n",x0, x1, x2, x3, x4, x5, x6, x7, x8, x9);	//결과 출력  
	return 0;	
 } 
