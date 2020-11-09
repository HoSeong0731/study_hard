#include "FPGrowth.h"


FPGrowth::~FPGrowth() {
	delete fpTree;
	delete table;
	//delete fout;
}

void FPGrowth::createFPtree(FPNode* root, HeaderTable* table, list<string> item_array, int frequency) {
	list<pair<int, string>> make_sort;
	FPNode* curNode;
	FPNode* prevNode;

	//curNode = new FPNode;
	
	for(list<string>::iterator it = item_array.begin(); it != item_array.end(); it++)
		make_sort.push_back(make_pair( this->table->find_frequency(*it), *it));
	
	
	make_sort.sort(greater<pair<int, string>>());
	bool is_first = true;
	/*
	for(list<pair<int, string>>::iterator it = make_sort.begin(); it != make_sort.end(); it++){
		cout << it->first << it->second << endl;
	}
	*/
	for(list<pair<int, string>>::iterator it = make_sort.begin(); it != make_sort.end(); it++)
	{

		//cout<< it->first << it->second << endl;
		curNode = new FPNode;
		prevNode = curNode;
		frequency = 1;
		//connectNode(this->table,curNode->getItem(),curNode);
		//curNode->setItem((char*)it->first.c_str());

		if(is_first){
			if(root->getChildrenNode(it->second) == NULL){
				curNode->setItem((char*)it->second.c_str());
				curNode->setParent(fpTree);
				//curNode->setNext(curNode);
				curNode->updateFrequency(frequency);
				//cout << prevNode->getItem() << " " << prevNode->getFrequency() << endl;
			}
			else{
				auto here = root->getChildrenNode(it->second);
				here->updateFrequency(1);
				//cout << here->getParent()->getItem() << " " << prevNode->getFrequency() << endl;
			}
			is_first = false;
			continue;
			
		}
		if(prevNode->getChildrenNode(it->second) == NULL){
			curNode->setItem((char*)it->second.c_str());
			curNode->setParent(prevNode);
			prevNode->pushchildren(curNode->getItem(),curNode);
			curNode->updateFrequency(frequency);
			//cout << prevNode->getItem() << " " << prevNode->getFrequency() << endl;
		}
		else{
			curNode->getChildrenNode(it->second)->updateFrequency(frequency);
			//cout << prevNode->getChildrenNode(it->second)->getItem() << " " << prevNode->getFrequency() << endl;
		}

		
	}
	
	// 1 setting 
	// 2. new...
	//
}

void FPGrowth::connectNode(HeaderTable* table, string item, FPNode* node) {
	map<string, FPNode*>::iterator it;

	for(it = table->getdataTable().begin(); it != table->getdataTable().end() ;it++){
		if(it->second == NULL){
			it->second->setNext(node);
			break;
		}
	}

}

bool FPGrowth::contains_single_path(FPNode* pNode) {
	if (pNode->getChildren().size() == 0) return true;
	else if (pNode->getChildren().size() > 1) return false;
	return contains_single_path(pNode->getChildren().begin()->second);
}

map<set<string>, int> FPGrowth::getFrequentPatterns(HeaderTable* pTable, FPNode* pTree) {

	return {};
}



void FPGrowth::powerSet(map<set<string>, int>* FrequentPattern, vector<string> data, string item, int frequency, int* ptr, int depth) {
	if (data.size() == depth) {
		set<string> set; set.insert(item);
		for (int i = 0; i < data.size(); i++) { if (ptr[i] == 1) set.insert(data[i]); }
		FrequentPattern->insert(make_pair(set, frequency)); return;
	}
	ptr[depth] = 1;
	powerSet(FrequentPattern, data, item, frequency, ptr, depth + 1);
	ptr[depth] = 0;
	powerSet(FrequentPattern, data, item, frequency, ptr, depth + 1);
}

bool FPGrowth::printList() {
	
	list<pair<int, string>> hi = table->getindexTable();

	if(hi.size() < 1)
		return false;
	flog << "======== PRINT_ITEMLIST ========" <<endl;
	for(int n = 0; n < hi.size(); n = n){
		flog2 << hi.front().second << " " << hi.front().first << endl;
		hi.pop_front();
	}
	flog << "Success" << endl;
	flog << "=======================" << endl << endl;
	return true;
}
bool FPGrowth::printTree() {
	


	//auto gi = getTree();
	
	//for(int n = 0; n < fpTree->; n = n)
	return false;
}
void FPGrowth::saveFrequentPatterns(){

}
