#include "Vertex.h"

// Constructor & Destructor
Vertex::Vertex() :m_key(0), m_size(0), m_pEHead(NULL), m_pNext(NULL) {}
Vertex::Vertex(int key) :m_key(key), m_size(0), m_pEHead(NULL), m_pNext(NULL) {}
Vertex::~Vertex() {
	if(m_pEHead) delete m_pEHead;
	if(m_pNext) delete m_pNext;
}

/// <summary>
/// add edge with edgeNum at the end of the linked list for the edges
/// </summary>
///
/// <param name="edgeKey">
/// the key of the vertex for the edge
/// </param>
/// <param name="weight">
/// the weight of the edge
/// </param>
void Vertex::AddEdge(int edgeKey, int weight) {
	Edge* newItem = new Edge(edgeKey, weight);
	m_size++;

	if (!m_pEHead) {
		m_pEHead = newItem;
		return;
	}

	Edge* temp = m_pEHead;
	while (temp->GetNext())
		temp = temp->GetNext();

	temp->SetNext(newItem);
}
/// <summary>
/// update edge
/// </summary>
///
/// <returns>
/// the ehad pointer of the new edge
/// </returns>
void Vertex::UpdateEdge(int key, int weight) {
	if (!FindEdge(key) || !m_pEHead) return;

	Edge* temp = m_pEHead;
	Edge* prev = NULL;
	while (temp) {
		if (temp->GetKey() == key) break;
		prev = temp;
		temp = temp->GetNext();
	}

	if (!temp) return;
	
	Edge* newItem = new Edge(key, weight);
	if(prev) prev->SetNext(newItem);
	if(m_pEHead == temp) m_pEHead = newItem;
	newItem->SetNext(temp->GetNext());
	delete temp;
}

/// <summary>
/// memory free for edges
/// </summary>
void Vertex::Clear() {
	if(m_pEHead) delete m_pEHead;
	m_pEHead = NULL;
}

/// <summary>
/// set the next pointer of this vertex
/// </summary>
void Vertex::SetNext(Vertex* pNext) {
	m_pNext = pNext;
}
/// <summary>
/// get the key of this vertex
/// </summary>
///
/// <returns>
/// the key of this vertex
/// </returns>
int Vertex::GetKey() const {
	return m_key;
}
/// <summary>
/// get the next pointer of this vertex
/// </summary>
///
/// <returns>
/// the next pointer of this vertex
/// </returns>
Vertex* Vertex::GetNext() const {
	return m_pNext;
}

/// <summary>
/// get the number of the edges
/// </summary>
///
/// <returns>
/// the number of the edges
/// </returns>
int Vertex::Size() const {
	return m_size;
}

/// <summary>
/// get the head pointer of the edge
/// </summary>
///
/// <returns>
/// the ehad pointer of the edge
/// </returns>
Edge* Vertex::GetHeadOfEdge() const {
	return m_pEHead;
}

/// <summary>
/// find the edge
/// </summary>
///
/// <returns>
/// the ehad pointer of the edge
/// </returns>
Edge* Vertex::FindEdge(int key) const {
	if (!m_pEHead) return NULL;
	Edge* temp = m_pEHead;
	while (temp) {
		if (temp->GetKey() == key) return temp;
		temp = temp->GetNext();
	}

	return NULL;
}
