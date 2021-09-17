// Merge Sorted Arrays:: Leetcode
// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>

using namespace std;

// main function
void merge(vector<int> &v1, int m, vector<int> &v2, int n)
{
    // pointers to both the end of numbers and index pointer to end of ans
    int index = m + n - 1, i = m - 1, j = n - 1;

    // while index doesnt reach 0, make comparisons and merge (or else if one array gets over:: thus no comparisons possible)
    while (index > 0 && (i >= 0 && j >= 0))
    {
        if (v1[i] >= v2[j])
        {
            v1[index--] = v1[i--];
        }
        else
        {
            v1[index--] = v2[j--];
        }
    }

    // after while loop check if index reached 0, if not merge the array left
    while (i >= 0)
    {
        v1[index--] = v1[i--];
    }
    while (j >= 0)
    {
        v1[index--] = v2[j--];
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> v1(m + n, 0);
    vector<int> v2(n);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v1[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v2[i] = x;
    }

    merge(v1, m, v2, n);

    for (auto i : v1)
        cout << i << " ";

    return 0;
}