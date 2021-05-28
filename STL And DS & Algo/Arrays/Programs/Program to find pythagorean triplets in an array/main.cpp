// Program to check if the array contains pythagorean triplets or not
//https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0

#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

// } Driver Code Ends


//User function template for C++
class Solution{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n)
    {
        sort(arr, arr+n);
        // 2 3 4 5 6
        for(int i = 0; i<n-2; i++)
        {
            for(int j = i+1; j<n-1; j++)
            {
                for(int k = j+1; k<n ;k++)
                {
                    if((arr[i]*arr[i]) + (arr[j]*arr[j]) == (arr[k]*arr[k]))
                        return true;
                    else
                        continue;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
// } Driver Code Ends