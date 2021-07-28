
#include<bits/stdc++.h>

using namespace std;

class graph {
    int v;
    int e;
    vector<unordered_set<int>> adjList;
public:

    graph() {
    }

//    // For constructing, initializer lists are more efficient, see syntax below
//    graph(int vertices, int edges):
//            v{vertices}, e{edges},
//            adjList{v} // suppress warning with static_cast<std::size_t>(v)
//    {}

    // OR

    graph(int vertices, int edges) {
        v = vertices;
        e = edges;
        adjList.resize(v);
    }

    void addEdge(int src, int des, bool bidir = true) {
        adjList[src].insert(des);
        if (bidir) {
            adjList[des].insert(src);
        }
    }

    void printList() const {
        for (int i = 0; i < v; i++) {
            cout << i << "->";
//          for (int it : adjList[i])  --> adjList[i] is a set and iterator points to each member of set which is integer
            for (const auto &it : adjList[i])
                cout << it << " ";
            cout << std::endl;
        }
    }
};

int main() {
    cout << "Enter the number of vertices and edges" << endl;
    int ver, edg;
    cin >> ver >> edg;

    graph g(ver, edg);

    // Sample Input: 5,3 :: 0 1, 2 3, 0 4

    for (int i = 0; i < edg; i++) {
        int src, des;
        cin >> src >> des;
        g.addEdge(src, des);
    }

    g.printList();

    return 0;
}


