// Rotate Images :: Leetcode
// https://leetcode.com/problems/rotate-image/

// O(1) SPACE COMPLEXITY

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    // easiest method to do this sort of rotation is by playing with transpose and reversal
    // ANS: Transpose the matrix and then reverse each row

    int n = matrix[0].size();

    // transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    // reverse
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main() {
    // input the size of square matrix
    int n;
    cin >> n;

    vector<vector<int>> v;
    // input the array
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    // rotate the array
    rotate(v);
    cout << endl;

    // final array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }

    return 0;
}