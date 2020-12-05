#ifndef EDGE_H
#define EDGE_H

#ifndef NULL
#define NULL	0
#endif

class Edge {
private:
    int m_key; // the key of this edge
    int m_weight; // the weight of this edge
    Edge* m_pNext; // the next pointer for the linked list of the edges

public:
    Edge(); // constructor
    Edge(int key, int weight); // copy constructor

    /// set the next pointer of this edge
    void SetNext(Edge* pNext);

    /// get the key of this edge
    int GetKey() const;
    /// get the weight of this edge
    int GetWeight() const;
    /// get the next pointer of this edge
    Edge* GetNext() const;
};

#endif