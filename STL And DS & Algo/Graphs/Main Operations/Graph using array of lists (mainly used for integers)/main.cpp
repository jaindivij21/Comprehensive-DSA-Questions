// Graph Data Structure :: Main Operations
// Implementation using adjacency list using array of lists.
// USED MAINLY WHEN STORING ONLY INTEGERS IN THE GRAPH AS ITS SIMPLER

#include<iostream>
#include<list>

using namespace std;

class Graph {
    // implement the graph using adjacency list i.e. array of lists
    int vertices;
    list<int> *l; // this is a dynamic array as we wanna make it at runtime of data type list
public:
    // constructor
    Graph(int v) {
        vertices = v;
        // Array of linked lists
        l = new list<int>[vertices];
    }
    
    // deconstructor
    ~Graph(){
        delete l;
    }

    // Add edges function
    void addEdge(int u, int v, bool bidir = true) {
        l[u].push_back(v);
        if (bidir) {
            l[v].push_back(u);
        }
    }

    // print the adjacency list
    void printList() {
        for (int i = 0; i < vertices; i++) {
            cout << i << "->";
            // l[i] is a linked list
            for (auto vertex : l[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }


};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.addEdge(4, 3);
    g.addEdge(0, 4);

    g.printList();

    return 0;
}