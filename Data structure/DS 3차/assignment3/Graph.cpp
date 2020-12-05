#include "Graph.h"
#include "Stack.h"
#include "MinHeap.h"
#include <set>
#include <algorithm>

#define BFS_FIRST_PATH

Graph::Graph() :m_pVHead(NULL), m_vSize(0) {}
Graph::~Graph() {
    if (m_pVHead) delete m_pVHead;
}

/// add vertex with vertexNum at the end of the linked list for the vertics
void Graph::AddVertex(int vertexKey) {
	Vertex* newItem = new Vertex(vertexKey);
	m_vSize++;

	if (!m_pVHead) {
		m_pVHead = newItem;
		return;
	}

	Vertex* temp = m_pVHead;
	while (temp->GetNext())
		temp = temp->GetNext();

	temp->SetNext(newItem);
}

/// add edge from the vertex which the number is startVertexKey to the vertex which the number is endVertexKey
void Graph::AddEdge(int startVertexKey, int endVertexKey, int weight) {
	Vertex* source = FindVertex(startVertexKey);
	source->AddEdge(endVertexKey, weight);
}

/// update edge from the vertex which the number is startVertexKey to the vertex which the number is endVertexKey
void Graph::UpdateEdge(int startVertexKey, int endVertexKey, int weight) {
	Vertex* source = FindVertex(startVertexKey);
	source->UpdateEdge(endVertexKey, weight);
}

/// get the vertex which the key is vertexNum
Vertex* Graph::FindVertex(int key) {
	if (!m_pVHead) return NULL;
	Vertex* temp = m_pVHead;
	while (temp) {
		if (temp->GetKey() == key) return temp;
		temp = temp->GetNext();
	}

	return NULL;
}


void Graph::Print(ofstream& sout) {
	Vertex* ver = m_pVHead;
	while (ver) {
		Edge* edge = ver->GetHeadOfEdge();
		while (edge) {
			sout << edge->GetWeight() << " ";
			edge = edge->GetNext();
		} sout << endl;
		ver = ver->GetNext();
	}
}

/// memory free for the vertics
void Graph::Clear() {
	if(m_pVHead) delete m_pVHead;
	m_pVHead = NULL;
}

/// get the number of the vertics
int Graph::Size() const {
	return m_vSize;
}

/// Set Matrix
void Graph::SetMatrix(vector<vector<int>>& arr) {
	Vertex* ver = m_pVHead;
	while (ver) {
		Edge* edge = ver->GetHeadOfEdge();
		int row = ver->GetKey();

		while (edge) {
			int col = edge->GetKey();
			int val = edge->GetWeight();
			if (val) arr[row][col] = val;

			edge = edge->GetNext();
		}
		ver = ver->GetNext();
	}
}


//#- Algorithm Functions
// 1. Floyd
vector<vector<int>> Graph::FindShortestPathFloyd() {
	vector<vector<int>> res(m_vSize, vector<int>(m_vSize, IN_FINITY));

	SetMatrix(res);
	for (int i = 0; i < m_vSize; i++)
		res[i][i] = 0;
	for (int k = 0; k < m_vSize; k++)
		for (int i = 0; i < m_vSize; i++)
			for (int j = 0; j < m_vSize; j++)
				res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
	for (int i = 0; i < m_vSize; i++)
		for (int j = 0; j < m_vSize; j++)
			if (res[i][j] == IN_FINITY) res[i][j] = 0;

	return res;
}

//