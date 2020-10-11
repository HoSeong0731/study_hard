#include "PatientBST.h"

PatientBST::PatientBST()
{
    Root = NULL;        //constructor
}

PatientBST::~PatientBST()
{

}

PatientBSTNode* PatientBST::GetRoot()
{
    return Root;        //return Root
}

bool PatientBST::Insert(PatientBSTNode* node)
{
    if (Root == NULL) {
        Root = node;    //if no have root
        return false;
    }
    PatientBSTNode* current = Root;
    while (current->GetRight()) {      //inserting
        if (!current->GetLeft())
            break;
        else if (!current->GetLeft())
            break;
        else if (current->GetLeft() && (!current->GetLeft()->GetLeft() || !current->GetLeft()->GetRight()))
            current = current->GetLeft();
        else current = current->GetRight();
    }

    if (!current->GetLeft())
        current->SetLeft(node); //inserting
    else
        current->SetRight(node);//inserting

    return true;
}

bool PatientBST::Search(PatientBSTNode* current, char* name)
{
    if (current == NULL)        //execute
        return false;
    if (!strcmp(current->GetName(), name))      //preorder
        return true;
    if (Search(current->GetLeft(), name))       //preorder
        return true;
    if (Search(current->GetRight(), name))      //preorder
        return true;
    return false;
}

bool PatientBST::Delete(char* name)
{
    return true;    //fail
}

void PatientBST::Print_PRE(PatientBSTNode* node)
{
    //PRINT B PRE   //fail
}

void PatientBST::Print_IN(PatientBSTNode* node)
{
    //PRINT B IN    //fail
}

void PatientBST::Print_POST(PatientBSTNode* node)
{
    //PRINT B POST  //fail
}

void PatientBST::Print_LEVEL()
{
    //PRINT B LEVEL //fail
}