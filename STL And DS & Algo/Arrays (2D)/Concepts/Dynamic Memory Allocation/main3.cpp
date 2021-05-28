// Dynamic Memory Allocation for 2D Arrays
// short form (easier method to do this)

// https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new/936709#936709

#include<iostream>

using namespace std;

int main() {
    // if you use compile time constants i.e. a predefined array size for COLUMNS
    // but rows can be runtime
    // faster method and better as you use dereference operator to access values

    // input rows
    int rows;
    cin >> rows;

    // input columns
    int columns;
    cin >> columns;

    // declare array (input rows (runtime constant) but need to put columns (compile time))
    auto arr = new int[rows * columns];

    // input the 2d array
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> *(arr + i * columns + j);

    // output the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++)
            cout << *(arr + i * columns + j) << " ";
        cout << endl;
    }
    return 0;
}
































