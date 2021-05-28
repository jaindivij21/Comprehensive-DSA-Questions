// PRATA Problem
// https://www.spoj.com/problems/PRATA/

#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int pratasCooked(int arr[], int mid, int cookNo) {
    int temp = 1;
    int p = 0;
    int currTime = 0;
    while (currTime <= mid) {
        p++;
        currTime += temp * arr[cookNo];
        temp++;
    }
    p--;
    return p;
}

int minPratas(int arr[], int pratas, int cooks) {
    int ans = INT_MAX;    // stores the final ans i.e minimum time

    // limits

    // AP Formula
    // time taken by the fastest cook to cook all the pratas (cuz ofc when all cooks work together, their time will be less than this)
    int r = (pratas / 2) * (arr[0] + 10 * arr[0]);
    int l = 0;

    // binary technique
    while (l <= r) {
        int totalPratas = 0;
        int mid = l + (r - l) / 2;
        // for this value of mid we need to cal and check if we can cook at least mid number of pratas by using all available cooks
        for (int i = 0; i < cooks; i++) {
            totalPratas += pratasCooked(arr, mid, i);
        }
        // if pratas cooked in mid time is more or equal to reqd pratas try to get a less value of ans
        if (totalPratas >= pratas) {
            // update value of ans
            ans = min(mid, ans);
            // update right pointer
            r = mid - 1;
        }
            // else try to litle more value of mid i.e more minimum time
        else {
            // update left pointer
            l = mid + 1;
        }
    }
    return ans;
}


int main() {
    // test cases
    int t;
    cin >> t;
    while (t--) {
        // all the inputs
        int pratas;
        cin >> pratas;
        int cooks;
        cin >> cooks;

        // input the ranks
        int arr[cooks];
        for (int i = 0; i < cooks; i++)
            cin >> arr[i];

        // main function
        cout << "The minimum time to cook " << pratas << " pratas:" << minPratas(arr, pratas, cooks) << endl;
    }
    return 0;
}