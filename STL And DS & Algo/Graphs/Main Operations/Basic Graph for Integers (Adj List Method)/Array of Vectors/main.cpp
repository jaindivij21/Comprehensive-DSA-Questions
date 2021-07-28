// Graphs
#include<bits/stdc++.h>

using namespace std;


// Make the graphs
class graph {
private:
    int vertices;
    // array of vectors
    vector<int> *adj;
public:
    // constructors
    explicit graph(int v) {
        vertices = v;
        adj = new vector<int>[vertices + 1];
    }

    // methods

    // add edges
    // ifBidir is true : if the graph is undirected or bidirectional
    void addEdges(int src, int des, bool ifBidir = true) {
        adj[src].push_back(des);
        if (ifBidir)
            adj[des].push_back(src);
    }

    // print graph
    void printGraph() const {
        for (int i = 0; i < vertices+1; i++) {
            if (adj[i].empty())
                continue;
            cout << "Vertex " << i << endl;
            cout << "head";
            for (int j = 0; j < adj[i].size(); j++) {
                // print the entire graph
                cout << "->" << adj[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    int ver, noOfEdges;
    cin >> ver >> noOfEdges;

    // make graph
    graph g(ver);
    for (int i = 0; i < noOfEdges; i++) {
        int src, des;
        cin >> src >> des;
        g.addEdges(src, des);
    }
    // print graph
    g.printGraph();

    return 0;
}