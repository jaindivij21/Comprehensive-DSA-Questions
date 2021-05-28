// Bi-partite graph :: 2 color problem

#include<bits/stdc++.h>

using namespace std;

class graph {
    int v;
    list<int> *adjList;
public:
    graph() {}

    graph(int ver) {
        v = ver;
        adjList = new list<int>[v];
    }

    void addEdge(int src, int des, bool bidir = true) {
        adjList[src].push_back(des);
        if (bidir)
            adjList[des].push_back(src);
    }

    void printList() {
        for (int i = 0; i < v; i++) {
            cout << i << "->";
            for (auto nbr: adjList[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    bool isBipartite(int src) {
        // need to apply basic BFS
        // queue for bfs
        queue<int> q;
        q.push(src);

        // all the colors are -1 i.e. not set for now or are unvisited (saves space as we dont have to make separate array)
        int *colors = new int[v];

        for (int i = 0; i < v; i++)
            colors[i] = -1;

        // source node is colored by 0
        colors[src] = 0;

        // work till the queue isn't empty
        while (!q.empty()) {
            // pop the top element
            int front = q.front();
            q.pop();

            // explore all the neighbors of this node and if they are unvisited then add them to the queue
            for (auto nbr:adjList[front]) {
                if (colors[nbr] == -1) {
                    // node not yet visited
                    colors[nbr] = 1 - colors[front];
                    q.push(nbr);
                } else {
                    // if node already visited check its color, if same as front return false
                    if (colors[nbr] == colors[front]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
//    g.addEdge(0, 3);

    if (g.isBipartite(0)) {
        cout << "Yes. It's bipartite" << endl;
    } else {
        cout << "No, its not a bi-partite" << endl;
    }

    return 0;
}
