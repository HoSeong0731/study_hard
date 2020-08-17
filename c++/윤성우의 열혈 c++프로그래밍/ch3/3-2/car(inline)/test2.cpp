#include <iostream>
using namespace std;

class Calculator
{
private:
	int numOfAdd;
	int numOfMin;
	int numOfMul;
	int numOfDiv;
public:
	void Init();
	double Add(double num1, double num2);
	double Min(double num1, double num2);
	double Mul(double num1, double num2);
	double Div(double num1, double num2);
	void ShowOpCount();
};

void Calculator::Init()
{
	numOfAdd=0;
	numOfMin=0;
	numOfMul=0;
	numOfDiv=0;
}

double Calculator::Add(double num1, double num2)
{
	numOfAdd++;
	return num1 + num2;
}

double Calculator::Min(double num1, double num2)
{
	numOfMin++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2)
{
	numOfMul++;
	return num1*num2;
}

double Calculator::Div(double num1, double num2)
{
	numOfDiv++;
	return num1/num2; 
}

void Calculator::ShowOpCount()
{
	cout<<"µ¡¼À: "<<numOfAdd<<endl;
	cout<<"»¬¼À: "<<numOfMin<<endl;
	cout<<"°ö¼À: "<<numOfMul<<endl;
	cout<<"³ª´°¼À: "<<numOfDiv<<endl<<endl; 
}

int main()
{
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 ="<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 ="<<cal.Div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.2 ="<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 ="<<cal.Div(4.9, 1.2)<<endl;
	cal.ShowOpCount();
	return 0;
}
