#include <stdio.h>	//표준입출력헤더파일 포함
#include <stdlib.h>	//표준라이브러리헤더파일 포함  


int main()	//main함수  
{
    // 1~30의 숫자를 랜덤하게 가지는 2차원 배열
    int data[4][4]
        = { rand()%31 , rand()%31 ,rand()%31 ,rand()%31 ,
		 rand()%31 , rand()%31 , rand()%30, rand()%31 , 
		 rand()%31 , rand()%31 , rand()%31, rand()%31 ,
		 rand()%31 , rand()%31 , rand()%31, rand()%31 };
		 
	int leftdata[3]={};	//left데이터 값 저장 배열  
	int updata[3]={};	//up데이터 값 저장 배열
	int leftdiadata[3]={};	//leftdia데이터 값 저장 배열
	int rightdiadata[3]={};	//rightdia	데이터 값 저장 배열
 
    int i,j, result = 0;
    int left = data[0][0]*data[0][1];	//처음 left값  
    int up =  data[0][0]*data[1][0];	//처음 right값
    int leftdia = data[0][0]*data[1][1];	//처음 leftdia값
    int rightdia = data[0][3]*data[1][2];	//처음 rightdia값
    
    printf("랜덤하게 섞여있는 데이터 값\n");	//기존의 섞여있는 값 출력  
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
        	printf("%3d ", data[i][j]);
		}
			printf("\n");
    }
    
    for(i = 0; i < 4; i++)	//양옆의 곱셈 중 최대 값 구함. 
    {
    	for(j = 0; j < 3; j++)
    	{
    		if(data[i][j]*data[i][j+1]<data[i][j+1]*data[i][j+2])
    		{
    			left = data[i][j+1]*data[i][j+2];
    			leftdata[0] = data[i][j+1];	//값 저장  
    			leftdata[1] = data[i][j+2];	//값 저장  
    			leftdata[2] = data[i][j+1]*data[i][j+2];	//값 저장(곱한 값) 
			}
		}
	}
	
	 for(i = 0; i < 4; i++)	//위 아래의 곱셈 중 최대 값 구함. 
    {
    	for(j = 0; j < 3; j++)
    	{
    		if(data[i][j]*data[i+1][j]<data[i+1][j]*data[i+2][j])
    		{
    			up = data[i+1][j]*data[i+2][j];	//후에 비교를 위해 저장  
    			updata[0]=data[i+1][j];	//값 저장  
    			updata[1]=data[i+2][j];	//값 저장  
    			updata[2]=data[i+1][j]*data[i+2][j];	//값 저장  (결과 값) 
			}
		}
	}

	 for( i = 0; i < 4; i++)	//왼쪽 대각선의 곱셈 중 최대 값 구함. 
	{
		for(j = 0; j < 2; j++)
		{
			if(data[i][j]*data[i+1][j+1]<data[i][j+1]*data[i+1][j+2])
			{
				leftdia = data[i][j+1]*data[i+1][j+2];	//후에 비교를 위해 저장
				leftdiadata[0]=data[i][j+1];	//값 저장  
				leftdiadata[1]=data[i+1][j+2];	//값 저장  
				leftdiadata[2]=data[i][j+1]*data[i+1][j+2];	//값 저장  (결과 값)  
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
	
	for( i = 0; i < 4; i++)	//오른쪽 대각선의 곱셈 중 최대 값 구함. 
	{
		for(j = 3; j > 1; j--)
		{	
			if(data[i][j]*data[i+1][j-1]<data[i][j-1]*data[i+1][j-2])
			{
				rightdia = data[i][j-1]*data[i+1][j-2];	//후에 비교를 위해 저장
				rightdiadata[0]=data[i][j-1];	//값 저장
				rightdiadata[1]=data[i+1][j-2];	//값 저장
				rightdiadata[2]=data[i][j-1]*data[i+1][j-2];//값 저장  (결과 값) 
				if(j=2){
					if(data[i][j-1]*data[i+1][j-2]<data[i+1][j+1]*data[i+2][j])	//열이 바뀔 때  
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
	 
	 if(result<left)		//결과 값 정하기 (switch문 사용을 위해) 
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
	 
	 switch (result){	//switch문을 이용해 결과 출력  
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
    return 0;	//main함수 종료  
}
