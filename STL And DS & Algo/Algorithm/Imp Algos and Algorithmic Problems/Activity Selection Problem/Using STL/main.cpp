// Activity Selection Problem
// Greedy Approach

/*
 *  https://www.youtube.com/watch?v=poWB2UCuozA
 *  We will firstly sort the pairs based on their finishing times, and then pick the
 *  subsequent ones if their starting time is more or eql to the ending time of current one.
 */

#include<iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second)
        return true;
    else
        return false;
}

int main() {
    // test cases
    int t;
    cin >> t;
    while (t--) {
        // input the pairs
        int n;
        cin >> n;
        pair<int, int> arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;

        // sort the array based on their finishing times
        sort(arr, arr + n, cmp);

        // 1 accounts for the first job in the array
        int count = 1;
        int index = 0;
        // if the new job's starting time is more or eql to ending of current, incre count
        for (int i = 1; i < n; i++) {
            if (arr[i].first >= arr[index].second) {
                count++;
                index = i;
            }
        }

        // print the max works that can be done i.e count value
        cout << count << endl;


    }
    return 0;
}