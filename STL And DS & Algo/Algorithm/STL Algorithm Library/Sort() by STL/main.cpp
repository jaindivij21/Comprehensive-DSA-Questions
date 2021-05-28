#include<iostream>
#include<algorithm>

using namespace std;

// program to demonstrate  use of sort() function

// function to print the array
void show(int arr[], int n){
    for (int i=0; i<n; i++)
    {
        if (i == n-1)
            cout<<arr[i];
        else
            cout<<arr[i]<<",";
    }
    cout<<endl;
}

// comaprator function for the descending order
bool desc (int a, int b){
    return a < b; 
}

int main(){
    // declare array
    int arr[10] = {9, 2, 4, 6, 1, 7, 8, 5, 3, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Original Array: ";
    show(arr, n);

    // sort() function from algorithm library takes in 2 or 3 arguments. 
    // It takes in pointers (Array) or iterators (STL Data Struc) as parameters

    // ASCENDING
    sort(arr, arr +n);
    cout<< "New Ascending Array: ";
    show(arr, n);

    // DESCENDING
    sort(arr, arr +n, greater<int>());
    cout<< "New Descending Array: ";
    show(arr, n);

    sort(arr, arr+n);
    // ANOTHER METHOD OF DESCENDING ORDER
    // make your own comparator function and pass it onto the sort function
    sort(arr, arr+n, desc);
    show(arr, n);

    return 0;
}