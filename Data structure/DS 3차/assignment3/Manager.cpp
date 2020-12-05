#include "Manager.h"

#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <iterator>

Manager::~Manager() {
    if (fout.is_open()) fout.close();
}

void Manager::Run(const char* filepath) {
    fout.open(RESULT_LOG_PATH);

    ifstream fin;
    fin.open(filepath);

    // If Not Exist Command File
    if (!fin) return PrintError("SYSTEM", "CommandFileNotExist");

    // Loop Command
    string line;
    while (getline(fin, line)) {
        vector<string> val;
        tokenize(line, ' ', val);

        // Chk comment line and Continue
        if (val[0].find("//") != string::npos) continue;
        else if (val[0] == "LOAD") {
            Result res = Load((char *)val[1].c_str());
            if (res == Success) {
                PrintSuccess("LOAD");
                PrintError(0);
            } else PrintError("LOAD", res);
        } else if (val[0] == "UPDATE") {
            Result res = Update();
            if (res == Success) {
                PrintSuccess("UPDATE");
                PrintError(0);
            } else PrintError("LOAD", res);
        } else if (val[0] == "PRINT") {
            Result res = Print();
            if (res == Success) PrintError(0);
            else PrintError("PRINT", res);
        } else if (val[0] == "BFS") {
            if (val.size() != 3) {
                PrintError("BFS", VertexKeyNotExist);
                continue;
            }

            Result res = FindPathDfs(stoi(val[1]), stoi(val[2]));
            if (res == Success) PrintError(0);
            else PrintError("BFS", res);
        } else if (val[0] == "DIJKKSTRA") {
            if (val.size() != 3) {
                PrintError("DIJKKSTRA", VertexKeyNotExist);
                continue;
            }

            Result res = FindPathDfs(stoi(val[1]), stoi(val[2]));
            if (res == Success) PrintError(0);
            else PrintError("DIJKKSTRA", res);
        } else if (val[0] == "DIJKSTRAMIN") {

        } else if (val[0] == "BELLMANFORD") {

        } else if (val[0] == "FLOYD") {
            Result res = FindShortestPathFloyd();
            if (res == Success) PrintError(0);
            else PrintError("FLOYD", res);
        } else PrintError(val[0], "NonDefinedCommand");
    }

    fin.close();
}

/// <summary>
/// make a graph
/// </summary>
///
/// <param name="filepath">
/// the filepath to read to make the graph
/// </param>
///
/// <returns>
/// Result::Success if load is successful.
/// Result::LoadFileNotExist if file is not exist.
/// </returns>
Result Manager::Load(const char* filepath) {
    ifstream data;
    data.open(filepath);

    // Chk File Exist
    if (!data) return LoadFileNotExist;

    string line;
    getline(data, line);
    count = stoi(line);

    for(int i=0; i<count; i++) {
        m_graph.AddVertex(i);
        getline(data, line);
        
        vector<int> weight;
        string name = line.substr(0, line.find(" / "));
        string weight_str = line.substr(line.find(" / ")+3, line.length());

        name_list.push_back(name);
        tokenize(weight_str, ' ', weight);
        for (int e = 0; e < weight.size(); e++) {
            //if (!weight[e] || i == e) continue; ???
            m_graph.AddEdge(i, e, weight[e]);
        }
    }

    data.close();
    return Success;
}

/// <summary>
/// update a graph
/// </summary>
///
/// <returns>
/// Result::Success if update is successful.
/// Result::FaildtoUpdatePath if update failed.
/// </returns>
Result Manager::Update() {
    // vector<vector<int>> cost(n, vector<int>(n, 100)); // Cost Graph Table

    // Calc Rules
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            int prev_weight = m_graph.FindVertex(i)->FindEdge(j)->GetWeight();
            if (i == j || prev_weight == 0) continue;

            vector<int> rule(3, 0);
            string source = name_list[i];
            string target = name_list[j];
            string source_owner = source.substr(0, source.find("'s"));
            string target_owner = target.substr(0, target.find("'s"));

            // Step 1
            for (int l = 0; l <= target_owner.length() - 5; l++)
                if (RabinKarpCompare((char*)source_owner.c_str(), (char*)target_owner.substr(l, 5).c_str()) == EqualRabin) {
                    // Update Cost
                    prev_weight = int(ceil(prev_weight * 0.9));
                    m_graph.UpdateEdge(i, j, prev_weight);
                    rule[0] = 10;
                    break;
                }
            
            // Step 2
            if (rule[0] && source_owner.length() >= 10 && target_owner.length() >= 10) {
                for (int l = 0; l <= target_owner.length() - 10; l++)
                    if (RabinKarpCompare((char*)source_owner.c_str(), (char*)target_owner.substr(l, 10).c_str()) == EqualRabin) {
                        prev_weight = int(ceil(prev_weight * 0.9));
                        m_graph.UpdateEdge(i, j, prev_weight);
                        rule[1] = 10;
                        break;
                    }
            }

            // Step 3
            vector<string> source_words, target_words;
            tokenize(source, ' ', source_words); source_words.erase(source_words.begin());
            tokenize(target, ' ', target_words); target_words.erase(target_words.begin());
            for (auto w : source_words) {
                Result res = NotEqualRabin;
                for (auto o : target_words) {
                    if (w.length() != o.length()) continue;

                    res = RabinKarpCompare((char*)w.c_str(), (char*)o.c_str());
                    if(res == EqualRabin) {
                        prev_weight = int(ceil(prev_weight * 0.8));
                        m_graph.UpdateEdge(i, j, prev_weight);
                        rule[2] = 20;
                        break;
                    }
                }

                if (res == EqualRabin) break;
            }
        }
    }

    return Success;
}

/// <summary>
/// print out the graph as matrix form
/// </summary>
///
/// <returns>
/// Result::Success if the printing is successful
/// Result::GraphNotExist if there is no graph
/// </returns>
Result Manager::Print() {
    if (!m_graph.Size()) return GraphNotExist;
    PrintSuccessHeader("PRINT");
    m_graph.Print(fout);
    PrintSuccessFooter("PRINT");

    return Success;
}

/// <summary>
/// find the path from startVertexKey to endVertexKey with BFS (stack and queue)
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindPathDfs(int startVertexKey, int endVertexKey) {
    return Success;
}

/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using std::set
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindShortestPathDijkstraUsingSet(int startVertexKey, int endVertexKey) {

    return Success;
}

/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using MinHeap
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
//Result Manager::FindShortestPathDijkstraUsingMinHeap(int startVertexKey, int endVertexKey) {
//    // TODO: implement
//}

/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Bellman-Ford
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::NegativeCycleDetected if exception has occurred.
/// Result::Success otherwise.
/// </returns>
//Result Manager::FindShortestPathBellmanFord(int startVertexKey, int endVertexKey) {
//    // TODO: implement
//}
//

Result Manager::FindShortestPathFloyd() {
    if (!m_graph.Size()) return GraphNotExist;
    PrintSuccessHeader("FLOYD");
    vector<vector<int>> res = m_graph.FindShortestPathFloyd();
    for (auto row : res) {
        for (auto val : row)
            fout << val << " ";
        fout << endl;
    }

    PrintSuccessFooter("FLOYD");
    return Success;
}

Result Manager::RabinKarpCompare(const char* CompareString, const char* ComparedString) {
    string str = string(CompareString);
    string pattern = string(ComparedString);

    int str_len(str.length()), pattern_len(pattern.length());
    int str_hash(0), pattern_hash(0), power(1);
    if (pattern_len > str_len) return NotEqualRabin;

    for (auto& c : str) c = toupper(c);
    for (auto& c : pattern) c = toupper(c);

    // Set Inital Hash
    for (int i = 0; i < pattern_len; i++) {
        str_hash = str_hash + str[pattern_len - i - 1] * power;
        pattern_hash = pattern_hash + pattern[pattern_len - i - 1] * power;
        if (i < pattern_len - 1) power = power * 2;
    }

    if (str_hash == pattern_hash) return EqualRabin;
    for (int i = 1; i <= str_len - pattern_len; i++) {
        if (str_hash == pattern_hash) return EqualRabin;
        str_hash = 2 * (str_hash - str[i - 1] * power) + str[pattern_len - 1 + i];
    }

    return NotEqualRabin;
}


// Message Func
void Manager::PrintError(int num) {
    fout << "===================" << endl;
    fout << "Error code: " + to_string(num) << endl;
    fout << "===================" << endl << endl;
}
void Manager::PrintError(string act, int num) {
    fout << "======== " << act << " ========" << endl;
    fout << "Error code: " + to_string(num) << endl;
    fout << "========="; for (int i = 0; i < act.size(); i++) fout << "="; fout << "=========" << endl << endl;
}
void Manager::PrintError(string act, string err) {
    fout << "======== " << act << " ========" << endl;
    fout << err << endl;
    fout << "========="; for (int i = 0; i < act.size(); i++) fout << "="; fout << "=========" << endl << endl;
}
void Manager::PrintSuccess(string act) {
    fout << "======== " << act << " ========" << endl;
    fout << "SUCCESS" << endl;
    fout << "========="; for (int i = 0; i < act.size(); i++) fout << "="; fout << "=========" << endl << endl;
}
void Manager::PrintSuccessHeader(string act) {
    fout << "======== " << act << " ========" << endl;
}
void Manager::PrintSuccessFooter(string act) {
    fout << "========="; for (int i = 0; i < act.size(); i++) fout << "="; fout << "=========" << endl << endl;
}

// #-- Common Func --#
void Manager::tokenize(string const& str, const char delim, vector<string>& out) {
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim))
        out.push_back(s);
}
void Manager::tokenize(string const& str, const char delim, vector<int>& out) {
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim))
        out.push_back(stoi(s));
}