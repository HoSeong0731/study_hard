#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len)
{
	//char *str=(char*)malloc(sizeof(char)*len)
	char * str = new char[len];
	return str;
}

int main()
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy!");
	cout<<str<<endl;
	//fre(str);
	delete []str;
	return 0;
}
//C++에서는 malloc과 free 함수의 호출이 문제가 될 수도 있으므로 앞으로는 new & delete를 쓰자  
