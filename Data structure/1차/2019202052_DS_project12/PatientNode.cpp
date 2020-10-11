#define _CRT_SECURE_NO_WARNINGS
#include "PatientNode.h"

PatientNode::PatientNode()
{
    Name = new char[100];
    Temperature = 0;
    Cough = '\0';               //constructor
    Location = new char[100];
}

PatientNode::~PatientNode()
{

}

char* PatientNode::GetName()
{
    return Name;                //return
}

float PatientNode::GetTemp()
{
    return Temperature;         //return
}

char PatientNode::GetCough()
{
    return Cough;               //return
}

char* PatientNode::GetLoc()
{   
    return Location;            //return
}

void PatientNode::SetName(char* name)
{
    strcpy(Name, name);         //data transfer
}

void PatientNode::SetTemp(float temp)
{
    Temperature = temp;         //data transfer
}

void PatientNode::SetCough(char cough)
{
    Cough = cough;              //data transfer
}

void PatientNode::SetLoc(char* location)
{
    strcpy(Location, location); //data transfer
}
