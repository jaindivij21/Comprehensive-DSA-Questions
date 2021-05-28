// Prims's Algorithm (UNDIRECTED GRAPH)
// Helps to find the MIN SPANNING TREE :: that is a subgraph with all vertices but not all edges (v-1) and has minimum sum of weights among all the spanning trees
// Time Complexity: O(ElogV)

// Note: We take undirected graphs as bidirectional graphs
// SAMPLE INPUT at last

// Greedy Approach :  We start from one vertex and keep adding edges with the lowest weight until we reach our goal.

#include <bits/stdc++.h>

using namespace std;

template<typename T>
class graph {
    // graph made using adjacency List => key:T, Value:List of Pairs of T and Weights (int) associated.
    map<T, list<pair<T, int>>> adjList;
    int vertices;
    int edges;
public:
    graph() {
        // empty constructor
    }

    // constructor
    graph(int v, int e) {
        vertices = v;
        edges = e;
    }

    // add edges function
    void addEdges(T u, T v, int w, bool bidir = true) {
        adjList[u].push_back(make_pair(v, w));
        if (bidir) {
            adjList[v].push_back(make_pair(u, w));
        }
    }

    // print the list function
    void printList() {
        cout << "NodeFrom->NodeTo1:Weight1 NodeTo2:Weight2...." << endl;
        for (auto node: adjList) {
            cout << node.first << "->";
            for (auto neighbor: node.second) {
                cout << neighbor.first << ":" << neighbor.second << " ";
            }
            cout << endl;
        }
    }

    // finds the vertex that has not been visited with least weight associated with it
    T find(map<T, bool> isVisited, map<T, int> weights, int v) {
        T minVertex;
        int minWeight = -1;
        // for every node, checks if the node is unvisited and either its first node or weight of node is minWeight, then update minVertex
        for (auto node:adjList) {
            if (!isVisited[node.first] && (minWeight == -1 || minWeight > weights[node.first])) {
                minVertex = node.first;
                minWeight = weights[node.first];
            }
        }
        // lastly we return the vertex or node with least weight (or least weighted incoming edge)
        return minVertex;
    }

    void prim() {
        map<T, bool> isVisited;
        map<T, T> parent;
        map<T, int> weights;

        T srcNode;
        int i = 0;

        for (auto node: adjList) {
            if (i == 0) {
                // to calculate the source node
                srcNode = node.first;
            }
            weights[node.first] = INT_MAX;
            isVisited[node.first] = false;
            i++;
        }

        // make the src node's parent as -1 and weight as 0
        parent[srcNode] = -1;
        weights[srcNode] = 0;

        for (i = 0; i < vertices - 1; i++) {
            // find the min weighted edge (or vertex)
            T minVertex = find(isVisited, weights, vertices);

            // mark that vertex as visited
            isVisited[minVertex] = true;

            // now for this min weighted vertex, update its neighbor's parents and and weights
            for (auto neighbor:adjList[minVertex]) {
                if (!isVisited[neighbor.first]) {
                    if (weights[neighbor.first] > neighbor.second) {
                        weights[neighbor.first] = neighbor.second;
                        parent[neighbor.first] = minVertex;
                    }
                }
            }
        }
        for (auto node:adjList) {
            if (node.first == srcNode) {
                continue;
            }
            cout << node.first << "--" << parent[node.first] << " : with a edge weight of " << weights[node.first];
            cout << endl;
        }
    }
};

int main() {
    // input the graph
    int v, e;
    cout << "Enter the number of edges and vertices of the graph" << endl;
    cin >> v >> e;
    graph<int> g(v, e);

    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdges(x, y, w);
    }

    cout << "\nAdjacency List" << endl;
    g.printList();

    cout << endl;
    cout << "The MST using Prim's:" << endl;
    g.prim();
}
