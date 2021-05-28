// Dynamic Memory Allocation for 2D Arrays

#include<iostream>

using namespace std;

int main() {
    /*
     *  1. Every row is represented by a normal array (Horizontal)
     *  2. An (Horizontal) array will be maintained to store the starting addresses of each row
     *  3. A pointer will be maintained to store the starting address of the horizontal array i.e the array that stores
     *     starting addresses of each row's array
     */

    // A pointer of name arr that stores address and points to something that itself stores (int *) i.e addresses
    // to int numbers
    int **arr;
    int rows, columns;
    cin >> rows >> columns;

    // Create an array of row heads i.e horizontal array i.e array that stores starting addresses of rows
    arr = new int *[rows];  // int * cuz it stores addresses of ints

    // finally create a 2d array
    for (int i = 0; i < rows; i++) {
        // each row head stores address to a new array of type int
        arr[i] = new int[columns];
    }

    // now our 2d array is created
    int val = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = val;
            val++;
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}