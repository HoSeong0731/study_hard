#pragma once
#include <cstring>
#include <queue>
using namespace std;

class LocationHeapNode
{
private:
	int Count;
	char* Location;

public:
	LocationHeapNode();
	~LocationHeapNode();

	int GetCount();
	char* GetLoc();

	void SetCount(int count);
	void SetLoc(char* location);
};
