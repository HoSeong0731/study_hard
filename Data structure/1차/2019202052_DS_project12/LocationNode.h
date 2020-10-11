#pragma once
#include "PatientBST.h"

class LocationNode
{
private:
	char* Location;
	PatientBST* BST = NULL;
	LocationNode* pLeft = NULL;
	LocationNode* pRight = NULL;

public:
	LocationNode();
	~LocationNode();

	char* GetLoc();

	PatientBST* GetBST();
	LocationNode* GetLeft();
	LocationNode* GetRight();

	void SetBST(PatientBST* bst);
	void SetLoc(char* location);
	void SetLeft(LocationNode* node);
	void SetRight(LocationNode* node);
};
