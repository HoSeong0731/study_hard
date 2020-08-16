#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char *str1="ABC 123 ";
	char *str2="DEF 456 ";
	char str3[50];
	
	cout<<strlen(str1)<<endl;
	cout<<strlen(str2)<<endl;
	strcpy(str3, str1);
	strcat(str3, str2);
	cout<<str3<<endl;
	
	if(strcmp(str1, str2)==0)
		cout<<"문자열이 같다."<<endl;
	else
		cout<<"문자열이 같지 않다."<<endl;
	return 0;
}
