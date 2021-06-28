// B - Pleasant Pairs
// https://codeforces.com/contest/1541/problem/B
// https://codeforces.com/blog/PurpleCrayon

// 
// GOOD SOLUTION : https://www.youtube.com/watch?v=vHavxvnCxik

/*
 * The crux of this problem was TLE when we use brute force bringing the TC = O(n2). But we can reduce it to O(nlogn) by looking at some interesting information.
 *      1) Its given the numbers are distinct.
 *      2) It can be computed that the max sum 2 indexes can have is (n-1)+n = 2n-1 or simply *2n*. This means that after sorting the numbers (remember to store the indexes before)
 *         product of pair elements will also be less than 2n. So since the array is sorted, as we go ahead the numbers will only increase, So if the product exceeds 2n; we
 *         can just break the nested loop.
 *         This will ultimately bring Tc down to O(logn). The sorting will also take O(nlogn), So overall TC = O(nlogn)
 *         The reason the total number of pairs is O(nlogn) is because if the first element of the pair is x, there are only 2n/x possible values of y.
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;

        // base array

        // also make a map that stores all the positions of the numbers (since they are distinct)
        unordered_map<int, int> indexes;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
            indexes.insert(make_pair(x, i + 1));
        }

        // main logic

        // sort in O(nlogn)
        sort(v.begin(), v.end());

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long int pro = v[i] * v[j];
                if (pro >= 2 * n)
                    break;
                else {
                    long long int sum = indexes[v[i]] + indexes[v[j]];
                    if (sum == pro)
                        count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
