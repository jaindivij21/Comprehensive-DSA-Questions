// https://practice.geeksforgeeks.org/problems/count-the-triplets/0#ExpectOP
// Count the  triplets
// ********** Two pointer algorithm ******************

#include<iostream>
#include<algorithm>
using namespace std;

int twoSum(int arr[], int size, int element, int j)
{
    int count=0;
    int i = 0;
    while(i < j)
    {
        if(arr[i]+arr[j]>element)
            j--;
        else if(arr[i]+arr[j]<element)
            i++;
        else {
            count++;
            i++;
            j--;
        }
    }
    return count;
}

int findTriplets(int arr[], int size)
{
    int total=0;
    sort(arr, arr+size);
    for(int i = size-1; i > 1; i--)
    {
        total += twoSum(arr, i, arr[i], i-1);
    }
    return total;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int res = findTriplets(arr, n);
        if(res==0)
            cout<<"The count is: "<<"-1"<<endl;
        else
            cout<<"The count is: "<<res<<endl;
    }

    return 0;
}