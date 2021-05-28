// Two Sum Problem
//  In an array find the triplets which add up to 0 

// ****************** TWO POINTER ALGORITHM *********************
// o(n)


#include<iostream>
#include<algorithm>
using namespace std;

bool checkSum(int arr[], int size, int sum, int i)
{
    int j = size-1;
    
    while(i<j)
    {
        if(arr[i]+arr[j]<sum)
            i++;
        else if(arr[i]+arr[j]>sum)
            j--;
        else
            return true;
    }
    return false;
}

bool foo(int arr[], int size)
{
    // sort the array
    sort(arr, arr+size);

    for(int i = 0; i<size-2; i++)
    {
        if(checkSum(arr, size-i-1, -arr[i], i+1))
            return true;
    }
    return false;
}

int main()
{
    cout<<"Enter the array size:";
    int sizeOfArr;
    cin>>sizeOfArr;
    int arr[sizeOfArr];
    cout<<"Enter the array elements:"<<endl;
    for(int i =0; i< sizeOfArr; i++)
        cin>>arr[i];

    bool result = foo(arr, sizeOfArr);
    
    if(result == 1)
        cout<<"Yes there exists 3 elements that sum up to "<<"0"<<endl;
    else
        cout<<"No there exists no 3 elements that sum up to "<<"0"<<endl;
 
    
    return 0;
}