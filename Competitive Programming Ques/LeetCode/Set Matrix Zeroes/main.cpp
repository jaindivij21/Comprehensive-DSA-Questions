// Set Matrix Zeroes :: Leetcode
// https://leetcode.com/problems/set-matrix-zeroes/

// Tricky part is to do the quesiton in place : I could have used the negation method where i mark all the numbers as -ve
// which needed to be made 0; but since the numbers already can be -ve this approach wont work.

#include<vector>
#include<iostream>

using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    bool colFlag = false;   // extra flag to keep track if the first column needs to be made 0
    int rows = matrix.size();
    int cols = matrix[0].size();

    // checking for 1st row
    for (int i = 0; i < cols; i++) {
        if (matrix[0][i] == 0) {
            // check if 1st col has any 0
            colFlag = true;
            break;
        }
    }
    // marking all the rows and columns first indexes as flags
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // making these indexes as 0's by looking at the flags
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    // lastly check and make changes for first row and col
    if (matrix[0][0] == 0) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
    // make changes in the first row
    if (colFlag) {
        for (int i = 0; i < cols; i++)
            matrix[0][i] = 0;
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }

    setZeroes(matrix);

    for (auto i: matrix) {
        for (auto j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}