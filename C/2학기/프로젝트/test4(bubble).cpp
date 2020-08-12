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

	int data2[16] ={	//2차원 배열을 버블정렬을 사용하기 위해 1차원 배열로 변환  
	data[0][0],data[0][1],data[0][2],data[0][3],data[1][0],data[1][1],data[1][2],data[1][3],data[2][0],data[2][1],data[2][2],data[2][3],data[3][0],data[3][1],data[3][2],data[3][3]};
    int i,j,temp, result;
    
    printf("랜덤하게 섞여있는 데이터 값\n");	//기존의 섞여있는 값 출력  
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
        	printf("%d ", data[i][j]);
		}
			printf("\n");
    }
    
    for (i = 0; i < 16; i++)	//data2값 버블 정렬  

		for (j = 0; j < 15; j++)

			if (data2[j] > data2[j + 1]) {

				temp = data2[j];

				data2[j] = data2[j + 1];

				data2[j + 1] = temp;
			}
			
	printf("1차원 배열로 받은 후 오름차순 정렬 \n");	  
    for (int i = 0; i < 16; i++)
    {
        {
        	printf("%d ", data2[i]);	//정렬한 데이터 출력
		}
    }
    printf("\n");
 
 
 
    result = data2[15]*data2[14];	//곱한 값 변수  
    printf("가장 큰 값을 곱한 값: %d * %d = %d", data2[14], data2[15], result);	//결과 출력  
    return 0;	//main함수 종료  
}


