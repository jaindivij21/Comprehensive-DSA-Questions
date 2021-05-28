// Journey to the moon

#include<bits/stdc++.h>

using namespace std;

// Returns factorial of n
int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

// returns combination of each
int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

// graph for integers
class graph {
    int v;
    int e;
    // adj list : a vector of sets
    vector<unordered_set<int>> adjList;
public:
    // constructor : initializer list
    graph() {}

    graph(int ver, int edg) :
            v(ver), e(edg),
            adjList(v) {}

    void addEdges(int src, int des, int bidir = true) {
        adjList[src].insert(des);
        if (bidir)
            adjList[des].insert(src);
    }

    void printList() {
        for (int i = 0; i < v; i++) {
            cout << i << "->";
            for (auto const &itr : adjList[i]) {
                cout << itr << " ";
            }
            cout << endl;
        }
    }

    // helper function for dfs function
    void helper(int src, bool visited[], int &countrySize) {
        visited[src] = true;
        countrySize++;
        // visit all its nbrs
        for (auto nbr:adjList[src]) {
            if (!visited[nbr]) {
                helper(nbr, visited, countrySize);
            }
        }
    }

    // all we need to do now is :: find the number of nodes in each non connected component (where each component is a country and its nodes the astronauts)
    void dfsWConnCom(int src) {
        bool *visited = new bool[v]{false};

        int ans = nCr(v, 2);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                // if the vertex isn't visited : call the helper fx on it since it'll be a different component
                int countrySize = 0;    // returns that country size
                helper(i, visited, countrySize);
                ans -= nCr(countrySize, 2);
            }
        }
        cout << "Ans: " << ans << endl;
    }
};

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    graph g(vertices, edges);

    for (int i = 0; i < edges; i++) {
        int src, des;
        cin >> src >> des;
        g.addEdges(src, des);
    }

    // calculates connected components and nodes in each using dfs
    // ans = vC2{selecting 2 from all vertices} - forall(componentCountrySize C 2){and subtract all those cases when 2 astro are selected from same country} 
    g.dfsWConnCom(0);

    return 0;
}
