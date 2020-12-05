#define _CRT_SECURE_NO_WARNINGS
#ifndef SOLUTION_H
#define SOLUTION_H

#include "Result.h"
#include "Graph.h"
#include <fstream>

class Manager {
private:
    // the filepath for the result log
    const char* RESULT_LOG_PATH = "log.txt";
    // the file stream for the result log
    std::ofstream fout;
    // graph instance to manage the vertics.
    Graph m_graph;

private:
    Result Load(const char* filepath);
    Result Print();
    Result Update();

    Result FindPathDfs(int startVertexKey, int endVertexKey);
    Result FindShortestPathDijkstraUsingSet(int startVertexKey, int endVertexKey);
    Result FindShortestPathDijkstraUsingMinHeap(int startVertexKey, int endVertexKey);
    Result FindShortestPathBellmanFord(int startVertexKey, int endVertexKey);
    Result FindShortestPathFloyd();
    Result RabinKarpCompare(const char* CompareString, const char* ComparedString);

public:
    int count;
    vector<string> name_list;

public:
    ~Manager();
    void Run(const char* filepath);
    void tokenize(string const&, const char, vector<string>&);
    void tokenize(string const&, const char, vector<int>&);

    void PrintError(int);
    void PrintError(string, int);
    void PrintError(string, string);
    void PrintSuccess(string);
    void PrintSuccessHeader(string);
    void PrintSuccessFooter(string);
};

#endif
