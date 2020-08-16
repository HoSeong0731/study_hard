#include <iostream>

int BoxVolume(int length, int width, int height)
{
	return length*width*height;
}

int BoxVolume(int length, int width)
{
	return length*width;
}

int BoxVolume(int length)
{
	return length*1*1;
}

int main()
{
	std::cout<<"[3,3,3]:"<<BoxVolume(3,3,3)<<std::endl;
	std::cout<<"[5,5,D]:"<<BoxVolume(5,5)<<std::endl;
	std::cout<<"[7,D,D]:"<<BoxVolume(7)<<std::endl;
}
