/*
정보은닉과 캡슐화
원하는 값은 (0~100)이지만 이 예제에서는 예외처리가 X 그거 해줘야 함.
point class에도, Rectangle class에도 
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
		cout<<"좌 상단:"<<"["<<upLeft.x<<","<<upLeft.y<<"]"<<endl;
		cout<<"우 하단:"<<"["<<lowleft.x<<","<<lowleft.y<<"]"<<endl; 
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
