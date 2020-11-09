#ifndef _BPTREEINDEXNODE_H_
#define _BPTREEINDEXNODE_H_

#include "BpTreeNode.h"
//template <class T>
class BpTreeIndexNode : public BpTreeNode {
private:
	map <int, BpTreeNode*> mapIndex;

public:
	BpTreeIndexNode() {}


	void insertIndexMap(int n, BpTreeNode* pN) {
		mapIndex.insert(map<int, BpTreeNode*>::value_type(n, pN));
	}

	void deleteMap(int n) {
		mapIndex.erase(n);
	}

	map <int, BpTreeNode*>* getIndexMap() { return &mapIndex; }

};

#endif