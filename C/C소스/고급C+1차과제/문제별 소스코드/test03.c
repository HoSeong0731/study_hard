#include <stdio.h>

void caln1(int *n0,int  *n1,int  *n2,int  *n3,int  *n4,int  *n5,int  *n6,int  *n7,int  *n8,int  *n9,int ha)
{ 
switch (ha) {	//����ġ������ �̿��� 0~9�� ���ڰ� ���� �� ���� ������Ŵ  
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
	int num1, num2, temp, n1, n2, n3, n4;	//�Է¹��� �� ����, �� ������ ū �� �ڷ� ���� temp, �ڸ� �� ���� ������ ��������   
	int x0 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, x9 = 0;	//0~9�� ���� ���� ����  
	
	back:	
	printf("ù ��° ���ڸ� �Է����ּ���(0~2000):");	 
	scanf_s("%d", &num1);	//ù ��° ���� �Է¹���  
		
	if(num1<0||num1>2000){		//����ó��  
		printf("ù ��° ���ڿ� �߸��� ���� �Է��ϼ̽��ϴ�.\n");
		goto back;
	}
	
	printf("�� ��° ���ڸ� �Է����ּ���(0~2000):");
	scanf_s("%d", &num2);	//�� ��° ���� �Է¹���  
	
	if(num2<0||num2>2000){		//����ó��  
		printf("�� ��° ���ڿ� �߸��� ���� �Է��ϼ̽��ϴ�.\n");
		goto back;
	}
	
	if(num1>num2)	//�� ���� �� ���� ���ڸ� ������ ����  
	{
		temp = num1;
        num1 = num2;
        num2 = temp;
	}

	while(num1<=num2){	//���� ���ڰ� ū ���ڰ� �Ǹ� �ݺ��� ����  
	n1 = num1 / 1000;	//1000�� �ڸ� ���  
	n2 = (num1 -(n1*1000)) / 100;	//100�� �ڸ� ���  
	n3 = (num1 -(n1*1000)-(n2*100)) / 10;	//10�� �ڸ� ���  
	n4 = num1 % 10;	//1�� �ڸ� ���
	
	if(num1>=1000){	//1000�� �ڸ��� ��� n1~n4���� ���� ��ȿ  
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n1);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n2);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n3);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}
	
	if(num1<1000 && num1>=100){	//100�� �ڸ��� ��� n2~n4���ڸ� ��ȿ   
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n2);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n3);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}

	if(num1<100 && num1>=10){	//10�� �ڸ��� ��� n3~n4���ڸ� ��ȿ 
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n3);
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}
	
	if(num1<10){	//1�� �ڸ��� ��� n4���ڸ� ��ȿ  
	caln1(&x0, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, n4);
	}
	num1++;	//�ݺ��� Ż�� ����  
	}
	
	printf("0: %d \n1: %d \n2: %d \n3: %d \n4: %d \n5: %d \n6: %d \n7: %d \n8: %d \n9: %d \n",x0, x1, x2, x3, x4, x5, x6, x7, x8, x9);	//��� ���  
	return 0;	
 } 
