// Program to print all the subarrays

#include<iostream>
using namespace std;

int main() {
    // size
    int n;
    cin >> n;

    // array
    int arr[1000];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    //  print subarrays
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++)
        {
            for(int k = i; k<=j; k++)
                cout<<arr[k]<<" ";
            cout<<endl;
        }
    }

}