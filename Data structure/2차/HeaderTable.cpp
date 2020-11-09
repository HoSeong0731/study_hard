#include "HeaderTable.h"
#include <iostream>

using namespace std;

HeaderTable::~HeaderTable() {
	delete fpnode;
}


void HeaderTable::insertTable(char* item, int frequency) {
	string str(item);

	for(list<pair<int, string>>::iterator it = indexTable.begin(); it != indexTable.end(); it++){
		if(it->second == str){
			it->first = it->first + 1;

			for(map<string, FPNode*>::iterator it2 = dataTable.begin(); it2 != dataTable.end(); it2++){
				if(it2->first == str){
					fpnode->updateFrequency(frequency);
				}
			}
			descendingIndexTable();
			return;
		}
	}

	indexTable.push_back(make_pair(frequency, str));
	dataTable.insert(make_pair(str, fpnode));
	descendingIndexTable();
}

int HeaderTable::find_frequency(string item){
	int frequency = 0;
	for(list<pair<int, string>>::iterator it = indexTable.begin(); it != indexTable.end(); it++){
		if(it->second == item)
			frequency = it->first;
	}
	return frequency;
}
