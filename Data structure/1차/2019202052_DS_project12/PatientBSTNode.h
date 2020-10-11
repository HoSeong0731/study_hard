#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

class PatientBSTNode
{
private:
	char* Name;
	char Disease;

	PatientBSTNode* pLeft;
	PatientBSTNode* pRight;

public:
	PatientBSTNode();
	~PatientBSTNode();

	char* GetName();
	char GetDisease();
	PatientBSTNode* GetLeft();
	PatientBSTNode* GetRight();

	void SetName(char* name);
	void SetDisease(char disease);
	void SetLeft(PatientBSTNode* node);
	void SetRight(PatientBSTNode* node);
};
