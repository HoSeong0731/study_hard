#include <stdio.h>	//ǥ�������������� ����
#include <stdlib.h>	//ǥ�ض��̺귯��������� ����  


int main()	//main�Լ�  
{
    // 1~30�� ���ڸ� �����ϰ� ������ 2���� �迭
    int data[4][4]
        = { rand()%31 , rand()%31 ,rand()%31 ,rand()%31 ,
		 rand()%31 , rand()%31 , rand()%30, rand()%31 , 
		 rand()%31 , rand()%31 , rand()%31, rand()%31 ,
		 rand()%31 , rand()%31 , rand()%31, rand()%31 };

	int data2[16] ={	//2���� �迭�� ���������� ����ϱ� ���� 1���� �迭�� ��ȯ  
	data[0][0],data[0][1],data[0][2],data[0][3],data[1][0],data[1][1],data[1][2],data[1][3],data[2][0],data[2][1],data[2][2],data[2][3],data[3][0],data[3][1],data[3][2],data[3][3]};
    int i,j,temp, result;
    
    printf("�����ϰ� �����ִ� ������ ��\n");	//������ �����ִ� �� ���  
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
        	printf("%d ", data[i][j]);
		}
			printf("\n");
    }
    
    for (i = 0; i < 16; i++)	//data2�� ���� ����  

		for (j = 0; j < 15; j++)

			if (data2[j] > data2[j + 1]) {

				temp = data2[j];

				data2[j] = data2[j + 1];

				data2[j + 1] = temp;
			}
			
	printf("1���� �迭�� ���� �� �������� ���� \n");	  
    for (int i = 0; i < 16; i++)
    {
        {
        	printf("%d ", data2[i]);	//������ ������ ���
		}
    }
    printf("\n");
 
 
 
    result = data2[15]*data2[14];	//���� �� ����  
    printf("���� ū ���� ���� ��: %d * %d = %d", data2[14], data2[15], result);	//��� ���  
    return 0;	//main�Լ� ����  
}


