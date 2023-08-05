// Leetcode: Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/

#include<iostream>

using namespace std;

bool searchMatrix(vector <vector<int>> &matrix, int target) {
    // Get the number of rows and columns in the matrix
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    // Initialize rowItr and colItr to start from the top-right element (first row, last column)
    int rowItr = 0;
    int colItr = colSize - 1;

    // Start searching from the top-right corner of the matrix
    while (rowItr < rowSize && colItr >= 0) {
        // If the target is greater than the current element, move to the next row
        if (target > matrix[rowItr][colItr]) {
            rowItr++;
        }
            // If the target is less than the current element, move to the previous column
        else if (target < matrix[rowItr][colItr]) {
            colItr--;
        }
            // If the target is equal to the current element, we found the target
        else {
            return true;
        }
    }

    // If the target is not found in the matrix, return false
    return false;
}

int main() {
    int target;
    cin >> target;

    int rows, cols;
    cin >> rows >> cols;

    vector <vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << searchMatrix(matrix, target);

    return 0;
}