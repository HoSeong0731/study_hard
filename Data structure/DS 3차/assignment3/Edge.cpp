#include "Edge.h"

Edge::Edge() :m_key(0), m_weight(0), m_pNext(NULL) {} // constructor
Edge::Edge(int key, int weight) :m_key(key), m_weight(weight), m_pNext(NULL) {} // copy constructor

/// set the next pointer of this edge
void Edge::SetNext(Edge* pNext) {
	m_pNext = pNext;
}

/// get the key of this edge
int Edge::GetKey() const {
	return m_key;
}

/// get the weight of this edge
int Edge::GetWeight() const {
	return m_weight;
}

/// get the next pointer of this edge
Edge* Edge::GetNext() const {
	return m_pNext;
}