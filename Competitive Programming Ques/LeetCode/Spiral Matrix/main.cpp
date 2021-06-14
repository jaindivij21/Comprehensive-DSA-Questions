// Spiral Matrix  :: Leetcode
// https://leetcode.com/problems/spiral-matrix/

#include<bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    // ans
    vector<int> ans;

    // set boundaries
    int sr = 0;
    int er = matrix.size() - 1;
    int sc = 0;
    int ec = matrix[0].size() - 1;

    // logic
    while (sr <= er && sc <= ec) {
        // run this loop continuously

        // top
        for (int j = sc; j <= ec; j++) {
            ans.push_back(matrix[sr][j]);
        }
        sr++;
        // right
        for (int i = sr; i <= er; i++) {
            ans.push_back(matrix[i][ec]);
        }
        ec--;
        // bottom :: extra condition
        if (er >= sr) {
            for (int j = ec; j >= sc; j--) {
                ans.push_back(matrix[er][j]);
            }
            er--;
        }
        // left :: extra condition 
        if (ec >= sc) {
            for (int i = er; i >= sr; i--) {
                ans.push_back(matrix[i][sc]);
            }
            sc++;
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> v;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    vector<int> ans = spiralOrder(v);
    for (auto i: ans)
        cout << i << " ";

    return 0;
}