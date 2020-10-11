#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LocationBST.h"
using namespace std;

LocationBST::LocationBST()
{
    Root = NULL;
    const char* location[7] = { "Gwangju", "Daegu", "Seoul", "Busan", "Daejeon", "Incheon", "Ulsan" };
    for (int i = 0; i < 7; i++) {
        char str[20] = " ";             //constructor location_BST
        strcpy(str, location[i]);
        LocationNode* node = new LocationNode();
        node->SetLoc(str);
        Insert_Location(node);          //insert
    } //make LocationBST
}

LocationBST::~LocationBST()
{

}

LocationNode* LocationBST::SearchLoc(LocationNode* current, char* name)
{
    if (current == NULL) return NULL;
    if (!strcmp(current->GetLoc(), name))       //search Loc
        return current;

    LocationNode* find;
    if ((find = SearchLoc(current->GetLeft(), name)) != NULL)   //finding
        return find;
    if ((find = SearchLoc(current->GetRight(), name)) != NULL)  //finding
        return find;

    return NULL;
}

LocationNode* LocationBST::GetRoot() //Root 얻고
{
    return Root;
}

void LocationBST::Insert_Location(LocationNode* node)  //삽입하고
{
    if (Root == NULL) {
        Root = node;
        return;
    }
    //insert Location
    LocationNode* current = Root;
    while (current->GetBST() || current->GetRight()) {
        if (!current->GetLeft())        //inserting
            break;
        else if (!current->GetLeft())
            break;
        else if (current->GetLeft() && (!current->GetLeft()->GetLeft() || !current->GetLeft()->GetRight()))
            current = current->GetLeft();
        else current = current->GetRight();
    }
    if (!current->GetLeft())
        current->SetLeft(node);     //inserting
    else
        current->SetRight(node);    //inserting
}

bool LocationBST::Insert_Patient(PatientNode* node)    //삽입하고
{
    return 0;//fail
}

bool LocationBST::Search(char* name)       //검색하고
{
            //fail
    return 0;
}

char* LocationBST::Delete(char* name)     //삭제하고
{
    return 0;//fail
}

void LocationBST::Print_PRE(LocationNode* node)               //PRE로 출력해주고
{
    if (node) {
        ofstream flog;
        flog.open("log.txt", ios::app); //log file open
        flog << node->GetLoc() << ' ';  //preorder
        Print_PRE(node->GetLeft());     //preorder
        Print_PRE(node->GetRight());    //preorder
        flog.close();
    }
}

void LocationBST::Print_IN(LocationNode* node)                //IN으로 출력해주고
{
    if (node) {
        ofstream flog;
        flog.open("log.txt", ios::app); //log file open
        Print_IN(node->GetLeft());      //inorder
        flog << node->GetLoc() << ' ';  //log print
        Print_IN(node->GetRight());     //inorder
        flog.close();
    }
}

void LocationBST::Print_POST(LocationNode* node)              //POST로 출력해주고 
{
    if (node) {
        ofstream flog;
        flog.open("log.txt", ios::app); //log file open
        Print_POST(node->GetLeft());    //postoreder
        Print_POST(node->GetRight());   //postorder
        flog << node->GetLoc() << ' ';  //
        flog.close();
    }
}

void LocationBST::Print_LEVEL(LocationNode* node)             //LEVEL로 출력해주고
{
    if (Root == NULL) {     //fail
        return;
    }
}
