// Sum of all elements of all the submatrices of a matrix
// https://www.geeksforgeeks.org/sum-of-all-submatrices-of-a-given-matrix/
// Efficient soln O(N^2)

#include<iostream>

using namespace std;

// The method for this problem is that instead of calculating all the submatrices, we will calculate
// contribution of each block by checking the number of submatrices it will come in
int main() {

    // Enter the n and n
    int n;
    cout << "Enter the number of n and n" << endl;
    cin >> n;

    int sum = 0;

    // input the 2D array
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Number of ways to choose
            // from top-left elements
            int top_left = (i + 1) * (j + 1);
            // Number of ways to choose
            // from bottom-right elements
            int bottom_right = (n - i) * (n - j);
            // total sum will be element mul by all the submatrices its a part of
            sum += (top_left * bottom_right * matrix[i][j]);
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}