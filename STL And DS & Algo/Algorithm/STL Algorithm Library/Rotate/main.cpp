// Rotate method
#include<iostream>
#include<algorithm>

// helps you rotate any array/vector about any index
// all you need to do is pass on the address of first last and axis's index or iterator

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    // old array
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }    
    
    // rotate the array
    rotate(arr, arr+2, arr+n);  // rotate the array about the index 2

    // new array
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }    
    
    return 0;
}