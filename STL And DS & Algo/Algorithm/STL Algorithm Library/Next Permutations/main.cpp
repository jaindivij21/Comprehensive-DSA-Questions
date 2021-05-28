// Next Permutation method
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(int);
    
    // array = 1 2 3
    
    next_permutation(arr, arr+n);
    // array = 1 3 2
    for(int i = 0; i <n; i++)
        cout<<arr[i]<<" ";
    next_permutation(arr, arr+n);
    // array = 2 1 3
    for(int i = 0; i <n; i++)
        cout<<arr[i]<<" ";
    // and so on, one can get all the permutations for a data str like array and get all its permutations

    return 0;
}