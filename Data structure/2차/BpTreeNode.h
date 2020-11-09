#pragma once
#include "FrequentPatternNode.h"
#include "FPNode.h"
class BpTreeNode
{
private:
	BpTreeNode* pParent;
	BpTreeNode* pMostLeftChild;

public:
	BpTreeNode() {
		pParent = NULL;
		pMostLeftChild = NULL;
	}
	~BpTreeNode() {

	}

	void setMostLeftChild(BpTreeNode* pN) { pMostLeftChild = pN; }
	void setParent(BpTreeNode* pN) { pParent = pN; }

	BpTreeNode* getParent() { return pParent; }
	BpTreeNode* getMostLeftChild() { return pMostLeftChild; }

	virtual void setNext(BpTreeNode* pN) {}
	virtual void setPrev(BpTreeNode* pN) {}
	virtual BpTreeNode* getNext() { return NULL; }
	virtual BpTreeNode* getPrev() { return NULL; }

	virtual void insertDataMap(int n, FrequentPatternNode* pN) {}
	virtual void insertIndexMap(int n, BpTreeNode* pN) {}
	virtual void deleteMap(int n) {}

	virtual map<int, BpTreeNode*>* getIndexMap() { return {}; }
	virtual map<int, FrequentPatternNode*>* getDataMap() { return {}; }

};
