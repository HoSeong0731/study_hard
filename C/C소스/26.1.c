#include <stdio.h>
#include "26.1.h"

void ListInit(List*plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN)
	{
		puts("저장이 불가능 합니다.");
		return ; 
	}
	plist->arr[plist->numOfData] = data;
	(plist -> numOfData)++;
}

int LFirst (List *plist, LData * pdata)
{
	if(plist->numOfData == 0)
	{
		return FALSE;
	}
	
	(plist -> curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

LData LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)
	{
		return FALSE;
	}
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];	//int형 26.1헤더파일 참조 
	
	for(i=rpos; i<num-1; i++)
	{
		plist->arr[i] = plist->arr[i+1];
	}
	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}

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
			printf(" %d", data); 
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
			printf(" %d", data); 
	 } 
	printf("\n \n");
}
