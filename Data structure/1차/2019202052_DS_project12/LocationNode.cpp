#define _CRT_SECURE_NO_WARNINGS
#include "LocationNode.h"
#include <iostream>
using namespace std;

LocationNode::LocationNode()
{
	Location = new char[100];	//Location set
}

LocationNode::~LocationNode()
{

}

char* LocationNode::GetLoc()
{
	return Location;		//return
}

PatientBST* LocationNode::GetBST()
{
	if (this == nullptr) {
		exit(1);			//exception handling
	}
	return BST;				//return
}

LocationNode* LocationNode::GetLeft()
{
	if (pLeft == NULL) {
		return 0;			//exception handling
	}
	return pLeft;			//return
}

LocationNode* LocationNode::GetRight()
{
	if (pRight == NULL) {
		return 0;			//exception handling
	}
	return pRight;			//return
}

void LocationNode::SetBST(PatientBST* bst)
{
	BST = bst;				//data transfer
}

void LocationNode::SetLoc(char* location)
{
	strcpy(Location, location);	//data transfer
}

void LocationNode::SetLeft(LocationNode* node)
{
	pLeft = node;			//data transfer
}

void LocationNode::SetRight(LocationNode* node)
{
	pRight = node;			//data transfer
}	

