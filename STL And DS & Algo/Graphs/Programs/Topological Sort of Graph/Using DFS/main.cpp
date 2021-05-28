   // TOPOLOGICAL SORT OF A GRAPH
// using DFS (depth first search)

/*
 *  Outputs linear ordering of the vertices of graph such that for every edge (u->v) vertex u comes before v.
 *  All the dependencies of a node are printed first, only then the dependent node is printed.
 *  Works on DAGs (Directed Acyclic Graph)
 */

#include<iostream>
#include<map>
#include<list>

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
    void dfsTopologicalSort() {
        map<T, bool> visited;   // to store all the visited nodes
        list<T> answer; // stores the list of the answer i.e. the topologically sorted graph

        // we do this so that if our graph has multiple connected components, then all the graphs are covered
        for (auto i:adjList) {
            T node = i.first;
            if (!visited[node]) {
                dfsHelper(node, visited, answer);
            }
        }

        // print the answer list
        for (auto item:answer) {
            cout << item << "->";
        }
        cout << endl;
    }

    // recursive dfs helper function
    void dfsHelper(T src, map<T, bool> &visited, list<T> &answer) {
        // mark it visited but no need to print it just yet
        visited[src] = true;

        // just like dfs calculate its neighbors
        for (auto neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited, answer);
            }
        }
        // at this point all the neighbors of a node are covered and visited
        // so we can enter the current node to the list
        answer.push_front(src); // remember to push at the front
    }
};

// main function
int main() {
    // make the graph
    graph<string> g;
    g.addEdge("English", "Programming", false);
    g.addEdge("Maths", "Programming", false);
    g.addEdge("Programming", "HTML", false);
    g.addEdge("Programming", "Python", false);
    g.addEdge("Programming", "Java", false);
    g.addEdge("Programming", "JS", false);
    g.addEdge("Python", "Web-Dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web-Dev", false);
    g.addEdge("Java", "Web-Dev", false);
    g.addEdge("Python", "Web-Dev", false);

    // print the list
    g.printList();

    // Topological Sort using dfs (depth first traversal)
    cout << "\nThe topological sort of a graph is:" << endl;
    g.dfsTopologicalSort();

    return 0;
}