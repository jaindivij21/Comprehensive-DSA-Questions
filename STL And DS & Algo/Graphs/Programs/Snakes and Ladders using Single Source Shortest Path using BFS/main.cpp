// Snakes and Ladders Problem
// Solving using hash map as the adjacency list using BFS Traversal and Finding the SSSP
// This isn't a generic problem.

/*
 *  Given board is a 6x6 with a total of 36 boxes.
 *  We'll represent the board using an unweighted directed graph!
 */

#include<iostream>
#include<map>
#include<list>
#include<string>
#include<queue>

using namespace std;

class graph {
    map<int, list<int>> adjList;
public:
    graph() {
        // empty constructor
    }

    graph(int board[], int size) {
        // class constructor :: need to make the graph or adj list wrt to given board
        for (int i = 0; i <= size; i++) {
            // at every node, we can have die rolls from 1 to 6.
            for (int j = 1; j <= 6; j++) {
                // adjList[i].push_back(i + j + board[i + j]); or a better way to make sure we have unidirectional edges
                int u = i;
                int v = u + j + board[u + j];
                addEdge(u, v, false);
            }
        }
    }

    // function to add edges to the graph
    void addEdge(int u, int v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }

    // function to print the entire adjacency list
    void printList() {
        for (auto node:adjList) {
            cout << node.first << "-> ";
            for (auto neighbor : node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // main function i.e bfs function to print the shortest path from a src to the destination
    int bfs(int src, int des) {
        queue<int> q;
        map<int, bool> visited;
        map<int, int> dis;
        map<int, int> parent;   // will help us write down the path

        // push the source
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        dis[src] = 0;

        // cal the bfs traversal but no need to print it
        while (!q.empty()) {
            int temp = q.front();
            // we can print the temp variable here if we need to print the bfs traversal
            // cout << temp << " ";
            q.pop();

            for (auto neighbor: adjList[temp]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    dis[neighbor] = dis[temp] + 1;
                    parent[neighbor] = temp;
                }
            }
        }

        // after we have teh data we can print the distance of each node from the source
        // but that is not asked for

        // print the shortest path from src to parent
        // now we need to find the path from source to the destination
        cout << "Shortest path is from inputted source and destination is:" << endl;
        int temp = des;
        while (temp != src) {
            cout << temp << "<-";
            temp = parent[temp];
        }
        cout << temp << endl;

        // return sssp distance from source to des
        return dis[des];
    }
};

// question's function
void addSnakeAndLadders(int board[]) {
//    board[0] = 0;   // the starting of the array is already 0 since the game starts from 1
    board[2] = 13;  // means 2 has a ladder on it which takes us from 2 to 2+13 i.e. 15.
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;    // means 17 has a snake and it takes us down from 17 to 17-13 i.e. 4
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
}

int main() {
    // an array to represent the board i.e. where do snakes and ladders lie
    int board[50] = {0};
    int sizeOfBoard = 36;

    // adding values to the array according to the question
    addSnakeAndLadders(board);

    // graph that will represent our adjacency list
    graph g(board, sizeOfBoard);
    // g.printList();

    // answer :: parameters given are the source and the destination on the board
    cout << "Shortest path from 1 to end i.e. 36 on this board is:" << g.bfs(1, sizeOfBoard) << endl;

    return 0;
}