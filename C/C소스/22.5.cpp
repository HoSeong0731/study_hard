#include <stdio.h>	//입출력 헤더파일  

struct person	//구조체 person생성  
{
	char name[20];
	char phoneNum[20];
	int age;
	double grade;
};

struct building	//구조체 building생성  
{
	char name[20];
	char number[20];
	char floor[10];
	char price[30];
};

int main()	//main 함수  
{
	struct person arr[3]={	//값 입력	 
		{"김호성", "010-2570-8478", 20, 3.3},
		{"박수빈", "010-2561-4072", 20, 4.5},
		{"이호윤", "010-9426-6153", 20, 3.5}
	};
	
	struct building arr2[3]={	//값 입력  
		{"청춘시대","429-8", "2", "1000.50"},
		{"시원하람","123-23", "10", "1000.60"},
		{"본가", "692-1", "1", "3억"}
	};
	
	int i;
	for(i=0; i<3; i++)	//출력 	 
	{
		printf("%s %s %d %g \n", arr[i].name, arr[i].phoneNum, arr[i].age, arr[i].grade);
	 } 
	printf("\n"); 	//개행  
	
	for(i=0; i<3; i++)	//출력  
	{
		printf("%s %s %s %s \n", arr2[i].name, arr2[i].number, arr2[i].floor, arr2[i].price);
	 }
	 return 0;	//메인함수 종료  
}
