// Maximum Subarray : Leetcode
// https://leetcode.com/problems/maximum-subarray/

// Kadane's Algorithm

#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> const v) {
    int finalAns = v[0];
    int largest = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (largest + v[i] > v[i]) {
            largest += v[i];
        } else {
            largest = v[i];
        }
        finalAns = max(finalAns, largest);
    }
    return finalAns;
}

int main() {
    int size;
    cin >> size;

    vector<int> v;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << maxSubArray(v);

    return 0;
}
