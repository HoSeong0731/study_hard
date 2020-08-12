#include <stdio.h>	//입출력 헤더파일 
#include <string.h>	//문자열 헤더파일
 
struct person	//person구조체 생성  
{
	char name[20];
	char phoneNum[20];
	int age;
};
int main()	//main함수  
{
	struct person man1, man2;	//구조체 변수 man1, man2생성  
	strcpy(man1.name, "김호성");	//man1의 요소 name에 값 넣음  
	strcpy(man1.phoneNum, "010-2570-8478");	//man1의 요소 phonenum에 값 넣음 
	man1.age=20;	//man1의 요소 age에 값 넣음  
	
	printf("이름 입력: "); scanf("%s", man2.name);	//man2 요소 입력받음  
	printf("번호 입력: "); scanf("%s", man2.phoneNum);
	printf("나이 입력: "); scanf("%d", &(man2.age));
	
	printf("이름: %s \n", man1.name);	//man1 출력  
	printf("번호: %s \n", man1.phoneNum);
	printf("나이: %d \n", man1.age);
	
	printf("이름: %s \n", man2.name);	//man2 출력  
	printf("번호: %s \n", man2.phoneNum);
	printf("나이: %d \n", man2.age);
	return 0;	//메인함수 종료  
}
