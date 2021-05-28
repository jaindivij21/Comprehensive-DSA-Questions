// Kruskal's Algorithm (UNDIRECTED GRAPH)
// Helps to find the MIN SPANNING TREE :: that is a subgraph with all vertices but not all edges (v-1) and has
// minimum sum of weights among all the spanning trees those can be formed!
// Time Complexity: O(ElogE)
// Note that both Prims and Kruskal only work for weighted undirected graphs!

// Greedy Approach : Always find the lowest weighted edge and add to the minimum spanning tree. Always make sure that to be added edge isn't forming a cycle.
// Makes use of UNION-FIND algorithm to determine if the mst forms a cycle on addition of one edge or not

// Note: We take undirected graphs as bidirectional graphs
// SAMPLE INPUT at last

#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<list>

#define pp pair<pair<T,T>, int>

using namespace std;

// comparator function for min heap to sort edges in ascending order
template<typename T>
class nodeCompare {
public:
    bool operator()(pp p1, pp p2) {
        return p1.second > p2.second;
    }
};

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

    // helper function to kruskal that finds the parent to a node (union-find algo)
    T findParent(T node, map<T, T> parent) {
        if (parent[node] == node) {
            return node;
        } else {
            return findParent(parent[node], parent);
        }
    }

    // helper extra function to print the graph
    void printPQ(priority_queue<pp, vector<pp >, nodeCompare<T>> q) {
        while (!q.empty()) {
            pp top = q.top();
            q.pop();
            cout << top.first.first << " " << top.first.second << " " << top.second << endl;
        }
    }

    void kruskal() {
        // sort the edges based on the weights, so we'll use min heap for the same
        priority_queue<pp, vector<pp >, nodeCompare<T>> q;

        // Note that since we are taking bidirectional graphs, there will be 2 items in the heap that represent the same edge
        // print the heap to check it out :: therefore pop 2 times
        // insert the edges into the min heap
        for (auto node:adjList) {
            for (auto neighbor: node.second) {
                q.push(make_pair(make_pair(node.first, neighbor.first), neighbor.second));
            }
        }

        // make an output graph that stores the edges that exist in the MST (Minimum Spanning Tree)
        graph<T> output;

        // function to print the heap
        // printPQ(q);

        
        // parent array (union-find algo) : to tell if cycle is formed
        // assign all of them to themselves as their parent
        map<T, T> parent;
        for (auto node: adjList) {
            parent[node.first] = node.first;
        }


        // run loop to add edges to the MST. (vertices - 1) times edges need to be added.
        int count = 0;
        while (count != vertices - 1) {
            // extract the first edge
            pp edge = q.top();
            q.pop();
            q.pop();    // pop two times due to bidirectional edges

            // check if this edge extracted is safe to add into the MST i.e. doesnt create a cycle :: union find algo
            // finding immediate parents of source and destination of the edge being added
            T srcParent = findParent(edge.first.first, parent);
            T destParent = findParent(edge.first.second, parent);

            // if both parents arent same means the edge is safe to add otherwise not
            if (srcParent != destParent) {
                output.addEdges(edge.first.first, edge.first.second, edge.second);
                count++;
                // union
                parent[srcParent] = destParent;
            }
        }

        // now our output graph is ready, so print the results i.e. the MST graph
        output.printList();
    }
};

// function to take graph input from the user
// change the data type as per your need
graph<int> takeInput() {
    // input the graph
    int v, e;
    cout << "Enter the number of edges and vertices of the graph" << endl;
    cin >> v >> e;
    graph<int> g(v, e);

    cout << "Enter the edges and their weights => source vertex, destination vertex, edge weight" << endl;
    int src, des;
    int weight;
    for (int i = 0; i < e; i++) {
        cin >> src >> des >> weight;
        g.addEdges(src, des, weight);
    }
    return g;
}

// function to print the adjacency list
void print(graph<int> g) {
    g.printList();
}

// main kruskal function
void kruskal(graph<int> &g) {
    g.kruskal();
}

// main function
int main() {

    // declare the graph
    graph<int> g = takeInput();

    // print the adjacency list
    print(g);

    // find the minimum spanning tree using kruskal algorithm and print the edges of the MST
    kruskal(g);

    return 0;
}













// SAMPLE INPUT
//6 11

//0 1 2
//1 3 1
//0 2 4
//2 4 9
//4 5 5
//3 5 7
//4 3 11
//2 5 10
//0 3 3
//2 1 8
//2 3 6