// TOPOLOGICAL SORT OF A GRAPH
// using modified BFS (breadth first search)

/*
 *  Outputs linear ordering of the vertices of graph such that for every edge (u->v) vertex u comes before v.
 *  All the dependencies of a node are printed first, only then the dependent node is printed.
 *  Works on DAGs (Directed Acyclic Graph)
 *
 *  Tc: O(V+E)
 *  A queue and map/array is used for storing in degree of each vertex, algo starts from finding vertices with 0 in degree.
 */

#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>
class graph {
    // adjacency list
    map<T, list<T>> adjList;
public:
    graph() {
        // empty constructor
    }

    // function to add edges to the graph
    void addEdge(T u, T v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }

    // function to print the adjacency list
    void printList() {
        for (auto node:adjList) {
            cout << node.first << " -> ";
            for (auto neighbor: node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // topological sort
    void bfsTopologicalSort() {
        // queue to implement the topological sort using bfs like method
        queue<T> q;

        // maps to keep track of the visited nodes, also one to store the current in degree of nodes
        map<T, bool> visited;
        map<T, int> inDegree;

        // initiate the initial values to these data structures
        for (auto node : adjList) {
            visited[node.first] = false;
            inDegree[node.first] = 0;
        }

        // set the initial in degrees of each node using the adjacency list
        for (auto node:adjList) {
            for (auto neighbor : node.second) {
                inDegree[neighbor]++;
            }
        }

        // find the node with 0 in degree and push in queue
        for (auto node: adjList) {
            if (inDegree[node.first] == 0)
                q.push(node.first);
        }

        // until the queue is empty
        while (!q.empty()) {
            // pop the item and print it. and then update the in degrees and push the ones with 0 in degree
            T node = q.front();
            q.pop();
            // print the node
            cout << node << " ";

            // update the in degrees
            for (auto neighbor:adjList[node]) {
                // reduce the in degree for all these neighbors
                inDegree[neighbor]--;

                // push the nodes with 0 in degree from the list of neighbors (after subtraction)
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }
};

// main function
int main() {
    // make the graph
    graph<string> g;

    g.addEdge("Programming", "HTML", false);
    g.addEdge("Programming", "Python", false);
    g.addEdge("Programming", "Java", false);
    g.addEdge("Programming", "JS", false);
    g.addEdge("Python", "Web-Dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web-Dev", false);
    g.addEdge("Maths", "Programming", false);
    g.addEdge("Java", "Web-Dev", false);
    g.addEdge("Python", "Web-Dev", false);
    g.addEdge("English", "Programming", false);

    // print the list
    g.printList();

    // Topological Sort using dfs (depth first traversal)
    cout << "\nThe topological sort of a graph is:" << endl;
    g.bfsTopologicalSort();

    return 0;
}