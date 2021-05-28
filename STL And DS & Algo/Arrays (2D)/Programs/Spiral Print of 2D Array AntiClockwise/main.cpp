// anticlockwise spiral print of a 2D array
#include<iostream>

using namespace std;

void spiralprint(int arr[][100], int row, int col) {
    // set basic entities
    int startRow = 0;
    int endRow = row - 1;
    int startColumn = 0;
    int endColumn = col - 1;

    while (startRow <= endRow && startColumn <= endColumn) {
        // first column
        for (int i = startRow; i <= endRow; i++)
            cout << arr[i][startColumn] << ", ";
        startColumn++;

        // bottom row
        if (startRow < endRow) {
            for (int i = startColumn; i <= endColumn; i++)
                cout << arr[endRow][i] << ", ";
            endRow--;
        }

        // end column
        if (startColumn < endColumn) {
            for (int i = endRow; i >= startRow; i--)
                cout << arr[i][endColumn] << ", ";
            endColumn--;
        }

        // top row
        for (int i = endColumn; i >= startColumn; i--)
            cout << arr[startRow][i] << ", ";
        startRow++;
    }
}

int main() {

    int a[100][100] = {0};
    int m, n;
    cin >> m >> n;

    for (int row = 0; row <= m - 1; row++) {
        for (int col = 0; col <= n - 1; col++) {
            cin >> a[row][col];
        }
    }
    spiralprint(a, m, n);
    cout << "END" << endl;
    return 0;
}