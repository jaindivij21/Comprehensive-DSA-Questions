// WRONG
// https://codeforces.com/problemset/problem/919/D

#include<bits/stdc++.h>

#define MAX 300001

using namespace std;

// class graph
class graph {
    int vertices;
    int edges;
    // vector of vectors
    vector<vector<int>> adjList;
public:
    // constructor
    graph() {

    }

    graph(int v, int e) {
        vertices = v;
        edges = e;
        adjList.resize(vertices);
    }

    // adds edges
    void addEdges(int src, int des) {
        adjList[src].push_back(des);
    }

    // prints the adj list
    void print(char s[]) {
        for (int i = 0; i < vertices; i++) {
            cout << s[i] << "->";
            for (auto nbr: adjList[i]) {
                cout << s[nbr] << " ";
            }
            cout << endl;
        }
    }

    // dfs traversal as it checks for the ans as well as if the graph is cyclic
    int dfs(int srcIndex, char s[]) {
        // arrays to keep track of visited and in recursion stack nodes/vertices :: all false for now
        bool *visited = new bool[vertices]{false};
        bool *inStack = new bool[vertices]{false};

        // map that stores the occurrences of each character
        map<char, int> ans;
        // insert all the string chars and initiate value to 0
        for (int i = 0; i < vertices; i++) {
            if (ans.find(s[i]) != ans.end())
                continue;
            else
                ans.insert(make_pair(s[i], 0));
        }

        // max variable that stores our ans :: passed as reference into the recursive helper function
        int max = 0;
        // helper func that updates max value and also tells if graph is cyclic
        int ifCyclic = dfsHelper(srcIndex, visited, ans, s, max, inStack);

        // if graph is cyclic return and print -1 or return and print value of max
        if (ifCyclic)
            return -1;
        else
            return max;
    }

    // main recursive helper function
    bool dfsHelper(int src, bool *v, map<char, int> ans, char s[], int &m, bool *inStack) {
        if (!v[src]) {
            // if src is unvisited
            v[src] = true;  // make it visited
            inStack[src] = true;
            ans[s[src]]++;  // make the char's count +1

            // now explore the nbrs of this vertex
            for (auto nbr: adjList[src]) {
                if (!v[nbr]) {
                    // if the nbr isn't visited :: also means there is no way it can be in recursion stack
                    // now call recursion on this nbr and check if its further edges form a cycle or not, if yes return true
                    bool temp = dfsHelper(nbr, v, ans, s, m, inStack);
                    if (temp)
                        return true;
                } else {
                    // if the node has been visited :: it may or may not be in the recursion stack
                    // if its not in recursion stack, means no cycle formed since, this node may have been visited on some other route
                    if (inStack[nbr]) {
                        // but if its there in rec stack, and ofc is already visited, means there is a cycle
                        return true;
                    }
                }
            }
            // exit for loop :: means all nbrs explored :: so just return false (BUT REMEMBER TO REMOVE THE NODE FROM RECURSION STACK)
            // if true isn't returned :: 1) the node wasn't visited and further edges also dont make a cycle
            // 2) or the node was visited but wasn't in curr recursion stack
            if (adjList[src].empty()) {
                int currMax = 0;
                for (auto itr:ans) {
                    currMax = max(currMax, itr.second);
                }
                m = max(m, currMax);
            }
            inStack[src] = false;
            return false;
        }
    }
};


int main() {
    // given
//    int vertices = 5;
//    int edges = 4;
//    char str[] = "abaca";
//    int x[] = {1, 1, 3, 4};
//    int y[] = {2, 3, 4, 5};

    int vertices, edges;
    cin >> vertices >> edges;
    char *str = new char[MAX];
    cin >> str;

    graph g(vertices, edges);

    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdges(x - 1, y - 1);
    }

    // g.print(str);

    cout << g.dfs(0, str);

    return 0;
}
