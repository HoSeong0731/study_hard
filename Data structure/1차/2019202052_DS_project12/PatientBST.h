#pragma once
#include "PatientBSTNode.h"
#include "PatientNode.h"
#include <fstream>
#include <queue>
using namespace std;

class PatientBST
{
private:
	PatientBSTNode* Root;

public:
	PatientBST();
	~PatientBST();

	PatientBSTNode* GetRoot();
	bool Insert(PatientBSTNode* node);
	bool Search(PatientBSTNode* current, char* name);
	bool Delete(char* name);
	void Print_PRE(PatientBSTNode* node);
	void Print_IN(PatientBSTNode* node);
	void Print_POST(PatientBSTNode* node);
	void Print_LEVEL();
};
