#include <stdio.h>	//����� �������  

struct person	//����ü person����  
{
	char name[20];
	char phoneNum[20];
	int age;
	double grade;
};

struct building	//����ü building����  
{
	char name[20];
	char number[20];
	char floor[10];
	char price[30];
};

int main()	//main �Լ�  
{
	struct person arr[3]={	//�� �Է�	 
		{"��ȣ��", "010-2570-8478", 20, 3.3},
		{"�ڼ���", "010-2561-4072", 20, 4.5},
		{"��ȣ��", "010-9426-6153", 20, 3.5}
	};
	
	struct building arr2[3]={	//�� �Է�  
		{"û��ô�","429-8", "2", "1000.50"},
		{"�ÿ��϶�","123-23", "10", "1000.60"},
		{"����", "692-1", "1", "3��"}
	};
	
	int i;
	for(i=0; i<3; i++)	//��� 	 
	{
		printf("%s %s %d %g \n", arr[i].name, arr[i].phoneNum, arr[i].age, arr[i].grade);
	 } 
	printf("\n"); 	//����  
	
	for(i=0; i<3; i++)	//���  
	{
		printf("%s %s %s %s \n", arr2[i].name, arr2[i].number, arr2[i].floor, arr2[i].price);
	 }
	 return 0;	//�����Լ� ����  
}
