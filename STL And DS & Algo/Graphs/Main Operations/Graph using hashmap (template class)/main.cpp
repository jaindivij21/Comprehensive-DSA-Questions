// Graph Data Structure :: Main Operations
// Implementation using adjacency list using hashmap.
// MADE USING HASH MAP : where key is of type T and value is a list of type T

#include<iostream>
#include<map>
#include<list>
#include<string>

using namespace std;

// template for generic graph - any kind of data
template<typename T>
class Graph {
    // map of key value pair :: T and list of T to which the key node is pointing to
    map<T, list<T>> g;
public:
    Graph() {
        // empty constructor
    }

    // function to add edges
    void addEdge(T u, T v, bool bidir = true) {
        // edges are assumed to be bidirectional by default
        g[u].push_back(v);
        if (bidir) {
            g[v].push_back(u);
        }
    }

    // function to print the adjacency list
    void printList() {
        for (auto row:g) {
            // returns a pair into row variable : where row.first is the key and row.second is list of values
            cout << row.first << "->";
            for (auto value: row.second) {
                // returns a T data type on each iteration which are the values for the key
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Siachen");

    g.printList();

    return 0;
}