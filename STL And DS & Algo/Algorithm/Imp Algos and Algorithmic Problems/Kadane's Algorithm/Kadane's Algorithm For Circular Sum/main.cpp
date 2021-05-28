// Program to calculate Maximum Circular Sum
// https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

#include <iostream>
using namespace std;

// kadane algo
int kadane(int arr[], int size)
{
    int maxSum = arr[0];
    int currSum = maxSum;
    for(int i = 1; i<size; i++)
    {
        currSum = max(arr[i], currSum+arr[i]);
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

// How it works?
/*
    calculate C1 = normal kadane maximum sum
    calculate C2 = kadane(inverted array) + total sum of array
    ans = max(c1, c2)
*/

int circularSum(int a[],int n){
    int c1 = kadane(a,n);
    int c2=0;
    for(int i=0;i<n;i++){
        c2 += a[i];
        a[i] = -a[i];
    }
    c2 = c2 + kadane(a,n);
    return max(c1, c2);
}

// main program
int main() {
    // test cases
    int t;
    cin>>t;
    while(t--){
        int a[1000];
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // calling the main function
        cout<<circularSum(a,n)<<endl;
    }
    return 0;
}
