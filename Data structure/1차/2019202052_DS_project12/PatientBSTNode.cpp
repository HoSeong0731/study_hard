#include "PatientBSTNode.h"

PatientBSTNode::PatientBSTNode()
{
	Disease = '\0';
	Name = new char[100];
}

PatientBSTNode::~PatientBSTNode()
{

}

char* PatientBSTNode::GetName()
{
	return Name;		//return
}

char PatientBSTNode::GetDisease()
{
	return Disease;		//return
}

PatientBSTNode* PatientBSTNode::GetLeft()
{
	if (pLeft == NULL) {
		return 0;			//execute handling
	}
	return pLeft;			//return
}	

PatientBSTNode* PatientBSTNode::GetRight()
{
	if (pRight == NULL) {
		return 0;			//execute handling
	}
	return pRight;			//return
}

void PatientBSTNode::SetName(char* name)
{
	strcpy(Name, name);		//data transfer
}

void PatientBSTNode::SetDisease(char disease)
{
	Disease = disease;		//data transfer
}

void PatientBSTNode::SetLeft(PatientBSTNode* node)
{
	pLeft = node;			//data transfer
}

void PatientBSTNode::SetRight(PatientBSTNode* node)
{
	pRight = node;			//data transfer
}