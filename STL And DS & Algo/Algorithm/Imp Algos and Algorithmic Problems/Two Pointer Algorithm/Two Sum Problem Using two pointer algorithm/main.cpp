// Two Sum Problem
//  In an array find the two numbers which add up to X 

// ****************** TWO POINTER ALGORITHM *********************
// o(n)

#include<iostream>
#include<algorithm>
using namespace std;

bool foo(int arr[], int size, int sum)
{
    int i = 0;
    int j = size-1;
    // sort the array
    sort(arr, arr+size);

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

int main()
{
    int reqdSum;
    cout<<"Enter the reqd Sum:";
    cin>>reqdSum;
    cout<<"Enter the array size:";
    int sizeOfArr;
    cin>>sizeOfArr;
    int arr[sizeOfArr];
    cout<<"Enter the array elements:"<<endl;
    for(int i =0; i< sizeOfArr; i++)
        cin>>arr[i];

    bool result = foo(arr, sizeOfArr, reqdSum);
    
    if(result == 1)
        cout<<"Yes there exists two elements that sum up to "<<reqdSum<<endl;
    else
        cout<<"No there exists no two elements that sum up to "<<reqdSum<<endl;
 
    
    return 0;
}