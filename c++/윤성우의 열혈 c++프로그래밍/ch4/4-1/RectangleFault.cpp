/*
�������а� ĸ��ȭ
���ϴ� ���� (0~100)������ �� ���������� ����ó���� X �װ� ����� ��.
point class����, Rectangle class���� 
*/

#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;		
 };

class Rectangle
{
public:
	Point upLeft;
	Point lowleft;

public:
	void ShowRecInfo()
	{
		cout<<"�� ���:"<<"["<<upLeft.x<<","<<upLeft.y<<"]"<<endl;
		cout<<"�� �ϴ�:"<<"["<<lowleft.x<<","<<lowleft.y<<"]"<<endl; 
	}
};

int main()
{
	Point pos1={-2,4};
	Point pos2={5, 9};
	Rectangle rec={pos2, pos1};
	rec.ShowRecInfo();
	return 0;
}
