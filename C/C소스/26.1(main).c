#include <stdio.h>
#include "26.1.h"

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
			printf("%d", data); 
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
			printf("%d", data); 
	 } 
	printf("\n \n");
}

