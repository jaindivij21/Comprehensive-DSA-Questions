#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Making a 2D Array using pointers //basic theory behind what 2D arrays are


int main() {
    int n; //the size of outer array //or the no. of rows
    int q; //no. of code types by which we want to print the array i.e *(*(o_arr+i)+j) & o_arr[i][j]
    cin>>n>>q;

    //creating the outer array
    int **o_arr= new int*[n];
    int k;  //length of internal array //or the no. of columns
    cin>>k;

    for(int i=0; i<n;i++){

        //now entering the internal array elements
        int *i_arr= new int[k];

        for(int j=0;j<k;j++){
            cin>>i_arr[j];
        }
        o_arr[i]=i_arr;
    }

    for(int i=0; i<n;i++){
        for(int j=0;j<k;j++){
            cout<<o_arr[i][j]<<" ";
        }
    }
    cout<<"\n";
    for(int i=0; i<n;i++){
        for(int j=0;j<k;j++){
            cout<<*(*(o_arr+i)+j)<<" ";
        }
    }
    return 0;
}
