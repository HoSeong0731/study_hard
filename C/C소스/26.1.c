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
		puts("������ �Ұ��� �մϴ�.");
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
	LData rdata = plist->arr[rpos];	//int�� 26.1������� ���� 
	
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
	/***ArrayList�� ���� �� �ʱ�ȭ***/
	List list;
	int data;
	ListInit(&list); 

	/***5���� ������ ����***/
	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);
	
	/***����� ������ ��ü ���***/
	printf("���� �������� ��: %d \n", LCount(&list));
	
	//ù ��° ������ ��ȸ
	if(LFirst(&list, &data))
	{
		printf("%d",data);
		//�� ��° ������ ������ ��ȸ
		while(LNext(&list, &data))
			printf(" %d", data); 
	 } 
	printf("\n \n");
	
	/*** ���� 22�� Ž���Ͽ� ��� ����***/
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		//�� ��° ������ ������ ��ȸ
		while(LNext(&list, &data))
			if(data == 22)
				LRemove(&list);
	 }  
	 
	/***���� �� ����� ������ ��ü ���***/
	printf("���� �������� ��: %d \n", LCount(&list));
	
	if(LFirst(&list, &data))
	{
		printf("%d",data);
		while(LNext(&list, &data))
			printf(" %d", data); 
	 } 
	printf("\n \n");
}
