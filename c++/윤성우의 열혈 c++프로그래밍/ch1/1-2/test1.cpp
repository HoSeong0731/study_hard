#include <iostream>

void swap(int * ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;	
}

void swap(char *ptr1, char *ptr2)
{
	char temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void swap(double *ptr1, double *ptr2)
{
	double temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main()
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout<<num1<<"  "<<num2<<std::endl;
	
	char ch1='A', ch2='Z';
	swap(&ch1, &ch2);
	std::cout<<ch1<<"  "<<ch2<<std::endl;
	
	double dbl1=1.111, dbl2=5.555;
	swap(&dbl1, &dbl2);
	std::cout<<dbl1<<"  "<<dbl2<<std::endl;
	return 0;
}
