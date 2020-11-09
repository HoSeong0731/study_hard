#include "Manager.h"
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void Manager::run(const char* command)
{
	fin.open(command);
	flog.open("log.txt", ios::app);

	if(!fin)
	{
		flog << "File Open Error" << endl;
		return;
	}

	char cmd[100];
	char* context = NULL;

	while (!fin.eof())
	{
		fin.getline(cmd, 100);

		char* tmp = strtok_r(cmd, " ", &context);

		if(strcmp(tmp, "LOAD") == 0){
			if(LOAD())
				printSuccessCode(tmp);
			else
				printErrorCode(100);
			
		}
		else if (strcmp(tmp, "BTLOAD") == 0)
		{
			if(BTLOAD())
				printSuccessCode(tmp);
			else 
				printErrorCode(200);
		}
		else if(strcmp(tmp, "PRINT_ITEMLIST") == 0){
			if(PRINT_ITEMLIST())
				continue;
			else
				printErrorCode(300);
			
		}
		else if(strcmp(tmp, "PRINT_FPTREE") == 0){
			if(PRINT_FPTREE())
				printSuccessCode(tmp);
			else 
				printErrorCode(400);
		}
		else if(strcmp(tmp, "PRINT_MIN") == 0){
			char* token = NULL;
			char* item = strtok_r(context, " ", &token);
			int min_frequency = atoi(token);
			if(PRINT_MIN(item, min_frequency))
				printSuccessCode(tmp);
			else 
				printErrorCode(500);
		}
		else if(strcmp(tmp, "PRINT_CONFIDENCE") == 0){
			char* token2 = NULL;
			char* item2 = strtok_r(context, " ", &token2);
			double rate = atof(token2);
			if(PRINT_CONFIDENCE(item2, rate) == 0)
				printSuccessCode(tmp);
			else 
				printErrorCode(600);
		}
		else if(strcmp(tmp, "PRINT_RANGE") == 0){
			char* token3 = NULL;
			char* item3 = strtok_r(context, " ", &token3);
			char* start2 = strtok_r(NULL, " ", &token3);

			int start = atoi(start2);
			int end = atoi(token3);

			if(PRINT_RANGE(item3, start, end) == 0)
				printSuccessCode(tmp);
			else 
				printErrorCode(700);
		}
		else if(strcmp(tmp, "SAVE") == 0){
			if (SAVE())
				printSuccessCode(tmp);
			else 
				printErrorCode(800);
		}
		else if(strcmp(tmp, "EXIT") == 0){
			printSuccessCode(tmp);
			break;
		}
		else{
			flog << "======== ERROR ========" << endl;
			flog << "Command Error" << endl;
			flog << "=======================" << endl << endl;
		}
	}
	flog.close();
	fin.close();
	return;
}

bool Manager::LOAD()
{
	char data[200];
	char* token = NULL;
	char* temp = NULL;

	if(LOADCHECK != 0)
		return false;

	ifstream ifs;
	ifs.open("market.txt");

	if(!ifs.is_open()){
		ifs.close();
		return 0;
	}

	while (!ifs.eof()){
		ifs.getline(data, 200);
		if(strlen(data) == 0) break;


		token = strtok_r(data, "\t", &temp);
		fpgrowth->getHeaderTable()->insertTable(token, 1);

		char* ITEM = strtok_r(temp, "\t", &token);
		fpgrowth->getHeaderTable()->insertTable(ITEM, 1);

		while (ITEM){
			ITEM = strtok_r(NULL, "\t", &token);
			fpgrowth->getHeaderTable()->insertTable(ITEM, 1);
			if(strlen(token) == 0)break;
		}
	}

	ifs.clear();
	ifs.seekg(0, ios::beg);
	
	while (!ifs.eof()){
		ifs.getline(data, 200);
		if(strlen(data) == 0) break;
		string str(data);
		list<string> item;

		token = strtok(data, "\t");
		while (token != NULL) {
			item.push_back(token);
			token = strtok(NULL, "\t");
		}

		fpgrowth->createFPtree(fpgrowth->getTree(), NULL, item, -1);
	}

	LOADCHECK = 1;
	return true;
}




bool Manager::BTLOAD()
{
	
	flog << "unimplemented BTLOAD" << endl;
	return false;
}

bool Manager::PRINT_ITEMLIST() {
	fpgrowth->printList();
}

bool Manager::PRINT_FPTREE() {
	fpgrowth->printTree();
	flog << "unimplemented PRINT_FPTREE" << endl;
	return false;
}

bool Manager::PRINT_MIN(char* item, int min_frequency) {
	flog << "unimplemented PRINT_MIN" << endl;
	return false;
}

bool Manager::PRINT_CONFIDENCE(char* item, double rate) {
	flog << "unimplemented PRINT_CONFIDENCE" << endl;
	return false;
}

bool Manager::PRINT_RANGE(char* item, int start, int end) {
	flog << "unimplemented PRINT_RANGE" << endl;
	return false;
}

bool Manager::SAVE(){
	flog << "unimplemented SAVE" << endl;
	return false;
}

void Manager::printErrorCode(int n) {				//ERROR CODE PRINT
	flog << "======== ERROR " << n << " ========" << endl;
	flog << "=======================" << endl << endl;
}

void Manager::printSuccessCode(char *act) {//SUCCESS CODE PRINT 
	flog << "========" << act << "========" <<endl;
	flog << "Success" << endl;
	flog << "=======================" << endl << endl;
}

