#include <iostream>
using namespace std;

int main()
{
	int num = 20;
	int i = 0;
	
	cout<<"true: "<<true<<endl;
	cout<<"false: "<<false<<endl;
	
	while(true)
	{
		cout<<i++<<" ";
		if(i>num)
			break;
	}	
		cout<<endl;
		
		cout<<"sizeof 1: "<<sizeof(1)<<endl;
		cout<<"sizeof 0: "<<sizeof(0)<<endl;
		cout<<"sizeof ture: "<<sizeof(true)<<endl;
		cout<<"sizeof falese: "<<sizeof(false)<<endl;
		return 0;
	
}
