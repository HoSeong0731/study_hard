#include <iostream>

#pragma once
#include "LocationNode.h"
#include "PatientNode.h"

using namespace std;

class LocationBST
{

private:
	LocationNode* Root;

public:
	LocationBST();
	~LocationBST();

	LocationNode* GetRoot();
	void Insert_Location(LocationNode* node);
	bool Insert_Patient(PatientNode* node);

	LocationNode* SearchLoc(LocationNode* current, char* name);


	bool Search(char* name);
	char* Delete(char* name);
	void Print_PRE(LocationNode* node);
	void Print_IN(LocationNode* node);
	void Print_POST(LocationNode* node);
	void Print_LEVEL(LocationNode* node);
};
