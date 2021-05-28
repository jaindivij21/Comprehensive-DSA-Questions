// form the biggest number from the array elements
// use comparater function
/*
 *  Interesting concept::
 *      While comparing 2 numbers say x and y, check if xy is greater or yx is greater
 *      If xy is greater than, x > y otherwise the latter
 */

#include<iostream>
#include<algorithm>
using namespace std;

// bool compare(int a, int b)
// {
//     // get xy and yx
//     int xy = stoi(to_string(a).append(to_string(b)));
//     int yx = stoi(to_string(b).append(to_string(a)));
//     if (xy > yx)
//         return true;
//     else
//         return false;
// }

// BETTER TRY: instead of converting the strings back into ints to compare, we are comparing the string directly
int compare(int a, int b)
{
    string xy = to_string(a).append(to_string(b));
    string yx = to_string(b).append(to_string(a));
    return xy.compare(yx) > 0 ? 1: 0; 
}
int main()
{
    int t;
    cin>>t;
    // test cases
    while(t--)
    {
        // input the array
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];

        // find the largest number
        sort(arr, arr+n, compare);

        // print the output array
        for(int i = 0; i < n; i++)
            cout<<arr[i];
        cout<<endl;
    }

    return 0;
}