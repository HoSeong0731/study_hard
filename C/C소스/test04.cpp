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
		 
	int leftdata[3]={};	//left������ �� ���� �迭  
	int updata[3]={};	//up������ �� ���� �迭
	int leftdiadata[3]={};	//leftdia������ �� ���� �迭
	int rightdiadata[3]={};	//rightdia	������ �� ���� �迭
 
    int i,j, result = 0;
    int left = data[0][0]*data[0][1];	//ó�� left��  
    int up =  data[0][0]*data[1][0];	//ó�� right��
    int leftdia = data[0][0]*data[1][1];	//ó�� leftdia��
    int rightdia = data[0][3]*data[1][2];	//ó�� rightdia��
    
    printf("�����ϰ� �����ִ� ������ ��\n");	//������ �����ִ� �� ���  
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
        	printf("%3d ", data[i][j]);
		}
			printf("\n");
    }
    
    for(i = 0; i < 4; i++)	//�翷�� ���� �� �ִ� �� ����. 
    {
    	for(j = 0; j < 3; j++)
    	{
    		if(data[i][j]*data[i][j+1]<data[i][j+1]*data[i][j+2])
    		{
    			left = data[i][j+1]*data[i][j+2];
    			leftdata[0] = data[i][j+1];	//�� ����  
    			leftdata[1] = data[i][j+2];	//�� ����  
    			leftdata[2] = data[i][j+1]*data[i][j+2];	//�� ����(���� ��) 
			}
		}
	}
	
	 for(i = 0; i < 4; i++)	//�� �Ʒ��� ���� �� �ִ� �� ����. 
    {
    	for(j = 0; j < 3; j++)
    	{
    		if(data[i][j]*data[i+1][j]<data[i+1][j]*data[i+2][j])
    		{
    			up = data[i+1][j]*data[i+2][j];	//�Ŀ� �񱳸� ���� ����  
    			updata[0]=data[i+1][j];	//�� ����  
    			updata[1]=data[i+2][j];	//�� ����  
    			updata[2]=data[i+1][j]*data[i+2][j];	//�� ����  (��� ��) 
			}
		}
	}

	 for( i = 0; i < 4; i++)	//���� �밢���� ���� �� �ִ� �� ����. 
	{
		for(j = 0; j < 2; j++)
		{
			if(data[i][j]*data[i+1][j+1]<data[i][j+1]*data[i+1][j+2])
			{
				leftdia = data[i][j+1]*data[i+1][j+2];	//�Ŀ� �񱳸� ���� ����
				leftdiadata[0]=data[i][j+1];	//�� ����  
				leftdiadata[1]=data[i+1][j+2];	//�� ����  
				leftdiadata[2]=data[i][j+1]*data[i+1][j+2];	//�� ����  (��� ��)  
				if(j=1)	
				{
					if(data[i][j+1]*data[i+1][j+2]<data[i+1][j-1]*data[i+2][j])
					{
						if(i=3){
							continue;
						}else{
							leftdia = data[i+1][j-1]*data[i+2][j];
						leftdiadata[0]=data[i+1][j-1];
						leftdiadata[1]=data[i+2][j];
						leftdiadata[2]=data[i+1][j-1]*data[i+2][j];
						}
						
					}
				 } 
			}
	}
	
	for( i = 0; i < 4; i++)	//������ �밢���� ���� �� �ִ� �� ����. 
	{
		for(j = 3; j > 1; j--)
		{	
			if(data[i][j]*data[i+1][j-1]<data[i][j-1]*data[i+1][j-2])
			{
				rightdia = data[i][j-1]*data[i+1][j-2];	//�Ŀ� �񱳸� ���� ����
				rightdiadata[0]=data[i][j-1];	//�� ����
				rightdiadata[1]=data[i+1][j-2];	//�� ����
				rightdiadata[2]=data[i][j-1]*data[i+1][j-2];//�� ����  (��� ��) 
				if(j=2){
					if(data[i][j-1]*data[i+1][j-2]<data[i+1][j+1]*data[i+2][j])	//���� �ٲ� ��  
					{
						if(i=3)
						{
							continue;
						}
						else {
							rightdia = data[i+1][j+1]*data[i+2][j];
							rightdiadata[0]=data[i+1][j+1];
							rightdiadata[1]=data[i+2][j];
							rightdiadata[2]=data[i+1][j+1]*data[i+2][j];	
						}
											
					}
				}
				
			}
			
		}
	}

	}
	 
	 if(result<left)		//��� �� ���ϱ� (switch�� ����� ����) 
	 {
	 	result = 1;
	 }
	 if(result<up) 
	 {
	 	result = 2;
	 }
	 if(result<leftdia)
	 {
	 	result = 3;
	 }
	 if(result<rightdia)
	 {
	 	result = 4;
	 }
	 
	 switch (result){	//switch���� �̿��� ��� ���  
	 	case 1:
	 		printf("Biggest product1: = %d X %d = %d" ,leftdata[0] ,leftdata[1], leftdata[2]);
	 		break;
	 		
		case 2:
	 		printf("Biggest product2: = %d X %d = %d" ,updata[0] ,updata[1], updata[2]);
	 		break;
	 		
		case 3:
	 		printf("Biggest product3: = %d X %d = %d" ,leftdiadata[0] ,leftdiadata[1], leftdiadata[2]);
	 		break;
	 		
		case 4:
	 		printf("Biggest product4: = %d X %d = %d" ,rightdiadata[0] ,rightdiadata[1], rightdiadata[2]);
	 		break;
	 }
    return 0;	//main�Լ� ����  
}
