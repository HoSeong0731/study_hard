#pragma once

#include <cstring>
#include <map>
#include <cmath>
using namespace std;
class FPNode
{
private:
	char* item;
	int frequency;
	FPNode* parent;
	FPNode* next;
	map<string, FPNode*> children;
	
public:
	FPNode();
	~FPNode();
	void setParent(FPNode* node) { this->parent = node; }
	void setNext(FPNode* node) { next = node; }
	void pushchildren(string item, FPNode* node) { children.insert(map<string, FPNode*>::value_type(item, node)); }
	void setItem(char* item) { strcpy(this->item, item); }
	void updateFrequency(int frequency) { this->frequency += frequency; }

	char* getItem() { return item; }
	int getFrequency() { return frequency; }
	FPNode* getParent() { return parent; }
	FPNode* getNext() { return next; }
	FPNode* getChildrenNode(string item);
	map<string, FPNode*> getChildren() { return children; }
};


