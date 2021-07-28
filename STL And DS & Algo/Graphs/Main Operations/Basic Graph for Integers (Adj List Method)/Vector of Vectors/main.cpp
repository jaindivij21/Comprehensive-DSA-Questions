#include<bits/stdc++.h>

using namespace std;

// graph class
class graph {
private:
    int vertices;
    vector<vector<int>> adj;    // matrix as the adjacency list
public:
    // constructor
    explicit graph(int v) {
        vertices = v;
        adj.resize(vertices + 1); // size id one extra just because the question might not have the node '0'
    }

    // method to add edges
    void addEdge(int src, int des, bool ifBidir = true) {
        adj[src].push_back(des);
        if (ifBidir)
            adj[des].push_back(src);
    }

    // method to print the adjacency matrix
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            if (adj[i].empty()) {
                // this case is for handling the case of 0th vertex not existing
                continue;
            }
            cout << "Vertex " << i << endl;
            cout << "head";
            for (auto j : adj[i]) {
                cout << "->" << j;
            }
            cout << endl;
        }
    }
};

int main() {
//    graph g(5);
    return 0;
}