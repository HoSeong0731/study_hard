#pragma once
#include "PatientNode.h"
#include "LocationBST.h"
#include "LocationHeap.h"

class Manager
{
private:
	queue <PatientNode*>* ds_queue;
	PatientBST* ds_patient;
	LocationBST* ds_bst;
	LocationHeap* ds_heap;
	ifstream fin;
	ofstream flog;

	char* Name;
	float Temperature;
	char Cough;
	char* Location;
public:
	Manager();
	~Manager();

	void run(const char* command);
	bool LOAD();
	bool ADD(char* data);
	bool QPOP(char* number);
	bool SEARCH(char* data);
	bool PRINT(char* data);
	bool BPOP();

	void PrintErrorCode(int num);
	void PrintSuccess(char* act);
};
