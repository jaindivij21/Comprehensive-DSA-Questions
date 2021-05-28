// Graph Data Structure :: Main Operations
// Implementation using adjacency list using array of lists.

// Breadth First Traversal (BFS)
/*
 *  Iterative Traversal
 *  Uses Queues
 *  Used to compute SHORTEST PATH in Unweighted Graph :: therefore can add this functionality also
 *  TC: O(V+E)
 */

#include<iostream>
#include<list>
#include<queue>

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

    void bfs(int src, int des) {
        // input source is take as the parameter
        // traverse all the nodes of the graph

        // to store the nodes/numbers to be discovered
        queue<int> q;
        // make a bool array to keep track of all the nodes/numbers visited. Initially all are 0 i.e. false.
        bool *visited = new bool[vertices]{0};

        // added functionality

        // store SHORTEST DISTANCE OF THE NODE FROM THE SOURCE (initially all are 0) (considering unit len/eddge)
        int *dis = new int[vertices]{0};
        // stores the parent of each node :: will help us in printing the shortest path from source to each node
        int *parent = new int[vertices]{-1};


        q.push(src);
        // we define the parent of src as -1
        parent[src] = -1;
        dis[src] = 0;   // dis is 0
        visited[src] = true;

        while (!q.empty()) {
            // till the queue isn't empty
            // pop the front most element in the queue and print it
            int node = q.front();
            q.pop();

            // printing the node
            cout << node << " ";

            // push the neighbors of the node into the queue so that they can be explored in the future
            // but make surr if the node has been visited once, then dont push into the queue
            for (int neighbor : l[node]) {
                if (visited[neighbor]) {
                    // if the neighbor has already been visited continue
                    continue;
                } else {
                    // else add it to the queue
                    q.push(neighbor);
                    visited[neighbor] = true;
                    dis[neighbor] = dis[node] + 1;
                    parent[neighbor] = node;
                }
            }
        }
        // after printing the bfs traversal, print the shortest dis of each vertex and shortest path between src and dest 
        cout << endl;
        shortestDistancePrint(dis, parent, des, src);
        
    }

    // print the shortest distance of each node
    void shortestDistancePrint(int *dis, int *parents, int des, int src) {
        cout << "The shortest distance of each vertex from src is:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << "->" << dis[i] << endl;
        }
        cout << endl;
        cout << "Shortest path is:" << endl;
        int temp = des;
        while (temp != -1) {
            cout << temp << "<-";
            temp = parents[temp];
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);

    g.printList();

    cout << "\nBFS Traversal is:" << endl;
    g.bfs(0, 3);

    return 0;
}
