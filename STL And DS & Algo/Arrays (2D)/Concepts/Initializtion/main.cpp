// In C/C++, initialization of a multidimensional arrays can have left most dimension as optional

#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[][2] = {{1, 2}, {3, 4}}; // Works
// int a[][] = {{1, 2}, {3, 4}}; // Doesn't Work
return 0;
}

// Initialize all the indices with 0
    // int arr[10][10] = {0}; works only with compile time constants
    //  int arr[rows][columns] = {0}; doesn't work with runtime constants 