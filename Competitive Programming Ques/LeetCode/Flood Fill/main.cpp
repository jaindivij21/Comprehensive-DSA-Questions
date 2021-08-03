// Leetcode: Flood Fill
// https://leetcode.com/problems/flood-fill/

#include<bits/stdc++.h>

using namespace std;

// Applying DFS :: Note: Here we do not need to maintain a visited array/set because that can be figured out by checking the color
void dfs(vector<vector<int>> &image, int i, int j, int newColor, int oldColor) {
    // base case :: out of boundary, color change
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size()) {
        return;
    }
    if (image[i][j] == oldColor)
        image[i][j] = newColor;
    else
        return;
    // recursive cases :: move to all the 4 neighbors
    dfs(image, i - 1, j, newColor, oldColor);
    dfs(image, i, j + 1, newColor, oldColor);
    dfs(image, i + 1, j, newColor, oldColor);
    dfs(image, i, j - 1, newColor, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    // simple ques where we need to do a bfs or dfs across the image
    int oldColor = image[sr][sc];
    if (image[sr][sc] != newColor)  // if its already the new color then no change to be done
        dfs(image, sr, sc, newColor, oldColor); // else apply DFS or even DFS
    return image;
}

int main() {
    vector<vector<int>> image(3, vector<int>(3));
    image = {{1, 1, 1},
             {1, 1, 0},
             {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    floodFill(image, sr, sc, newColor);
    return 0;
}