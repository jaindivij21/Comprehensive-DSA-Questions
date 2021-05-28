// Program to print all pairs of numbers in array which sum to a target

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    // input the array and the target
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;

    // sort the array
    sort(arr, arr+n);

    // to find the pair most efficiently apply the 2 pointer algorithm
    int a = 0;
    int b = n-1;

    while(a<b)
    {
        int sum = arr[a]+arr[b];
        if(sum>target)
            b--;
        else if(sum<target)
            a++;
        else
        {
            cout<<arr[a]<<" and "<<arr[b]<<endl;
            b--;
            a++;
        }
    }
    return 0;
}