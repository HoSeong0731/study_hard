#include <stdio.h>
#include "26.1.h"

int main()
{
	/***ArrayList의 생성 및 초기화***/
	List list;
	int data;
	ListInit(&list); 

	/***5개의 데이터 저장***/
	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);
	
	/***저장된 데이터 전체 출력***/
	printf("현재 데이터의 수: %d \n", LCount(&list));
	
	//첫 번째 데이터 조회
	if(LFirst(&list, &data))
	{
		printf("%d",data);
		//두 번째 이후의 데이터 조회
		while(LNext(&list, &data))
			printf("%d", data); 
	 } 
	printf("\n \n");
	
	/*** 숫자 22를 탐색하여 모두 제거***/
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		//두 번째 이후의 데이터 조회
		while(LNext(&list, &data))
			if(data == 22)
				LRemove(&list);
	 }  
	 
	/***삭제 후 저장된 데이터 전체 출력***/
	printf("현재 데이터의 수: %d \n", LCount(&list));
	
	if(LFirst(&list, &data))
	{
		printf("%d",data);
		while(LNext(&list, &data))
			printf("%d", data); 
	 } 
	printf("\n \n");
}

