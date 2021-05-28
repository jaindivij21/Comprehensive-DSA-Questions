// Program to rotate a 2D Matrix by 90 degrees anti clockwise
// Check out for important observation *TRY TO MAKE TRANSPOSE*
// O(1) SPACE COMPLEDXITY              \

#include<algorithm>
#include<iostream>

using namespace std;

void rotateArray(int arr[][100], int n) {
    //  important thing to notice in this competitive problem is that if once you reverse the elements of each row
    //  the result matrix become transpose of the final/result matrix

    // reverse each row
    for (int i = 0; i < n; i++)
        reverse(arr[i], arr[i] + n);
    // transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j)
                swap(arr[i][j], arr[j][i]);
        }
    }
}

int main() {
    // input the size of square matrix
    int n;
    cin >> n;
    int arr[100][100];

    // input the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    // rotate the array
    rotateArray(arr, n);
    cout << endl;

    // final array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}