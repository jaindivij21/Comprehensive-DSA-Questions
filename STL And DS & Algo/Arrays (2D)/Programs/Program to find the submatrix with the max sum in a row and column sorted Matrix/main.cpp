// Max Submatrix sum in a row and column sorted matrix
// https://www.geeksforgeeks.org/maximum-sum-of-any-submatrix-of-a-matrix-which-is-sorted-row-wise-and-column-wise/

// Brute force solution - O(Query*N*M) time; since we loop through the entire submatrix to cal the sum

// Efficient soln: O(n) time once we have the suffix sum matrix; just check the max element from that matrix

#include<iostream>
#include<climits>

using namespace std;

int main() {
    // input the matrix
    int rows, columns;
    cout << "Enter the rows and columns" << endl;
    cin >> rows >> columns;
    int matrix[rows][columns];

    cout << "Enter the matrix" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cin >> matrix[i][j];
    }

    cout << endl;

    // Calculate the suffix sum matrix i.e. matrix that has cumulative sum of the main matrix but from bottom right corner
    int suffixSumMatrix[rows][columns];
    int sum = 0;
    for (int i = rows-1; i >= 0; i--) {
        for (int j = columns-1; j >= 0; j--) {
            if (i == rows-1 && j == columns-1)
                suffixSumMatrix[i][j] = matrix[rows-1][columns-1];
            else if (i == rows-1)
                suffixSumMatrix[i][j] = suffixSumMatrix[i][j + 1] + matrix[i][j];
            else {
                for (int x = rows-1; x >= i; x--) {
                    for (int y = columns-1; y >= j; y--) {
                        sum += matrix[x][y];
                    }
                }
                suffixSumMatrix[i][j] = sum;
                sum = 0;
            }
        }
    }

    // Print out the suffix sum matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << suffixSumMatrix[i][j] << " ";
        cout << endl;
    }

    cout<<endl;
    // find the largest element in the suffix sum matrix i.e basically the max sum
    int largest = INT_MIN;
    int x, y;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (largest < suffixSumMatrix[i][j]) {
                largest = suffixSumMatrix[i][j];
                x = i;
                y = j;
            }
        }
    }

    // Printing the max sum and the the corresponding sub matrix
    cout<<"The max sum of the any submatrix in this matrix is: "<<largest<<endl;
    cout<<"The submatrix is:"<<endl;
    for (int i = x; i < rows; i++) {
        for (int j = y; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}