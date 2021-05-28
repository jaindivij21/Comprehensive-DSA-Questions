// Program to print the smallest and the largest element in a array

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    // input the array
    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    int arr[size];
    for(int i = 0; i < size; i++)
        cin>>arr[i];

    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i = 0; i < size; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    cout<<"The max element is: "<<maxi<<endl;
    cout<<"The min element is: "<<mini<<endl;
}