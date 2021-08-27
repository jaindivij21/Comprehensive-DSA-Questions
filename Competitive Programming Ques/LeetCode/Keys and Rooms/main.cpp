// Leetcode : Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/

// DFS can solve the problem, once we visit a room, just mark it visited and add the count, after all the calls finish if the count is equal to number of rooms, means true
// otherwise false

// Time Complexity : O(n+m) : where n is the number of rooms and m is the maximum amount of keys/room. So worst case essentially becomes O(n2)

#include<bits/stdc++.h>

using namespace std;

// main dfs function
void dfs(const vector<vector<int>> &rooms, vector<bool> &visited, int &ans, int currRoom) {
    // base case : make the curr room as visited
    visited[currRoom] = true;
    ans++;

    // recursive cases :: for all the keys found in the room visit them, if they were unvisited
    for (int i = 0; i < rooms[currRoom].size(); i++) {
        if (!visited[rooms[currRoom][i]]) {
            // if the room is unvisited : visit it
            dfs(rooms, visited, ans, rooms[currRoom][i]);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int totalNumberOfRooms = rooms.size();

    // visited room array
    vector<bool> visited(rooms.size());
    fill(visited.begin(), visited.end(), false);
    int visitedRooms = 0;   // ans variable

    // start the dfs call from the first room itself
    dfs(rooms, visited, visitedRooms, 0);

    return visitedRooms == totalNumberOfRooms;
}

int main() {
    vector<vector<int>> rooms = {{1, 3},
                                 {3, 0, 1},
                                 {2},
                                 {0}};
    cout << canVisitAllRooms(rooms);

    return 0;
}