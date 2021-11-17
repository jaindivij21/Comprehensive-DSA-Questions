// Binary Search

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &v, int s, int e, int x)
{
    if (e >= s)
    {
        int mid = (s + e) / 2;
        if (v[mid] == x)
        {
            return mid;
        }
        else if (v[mid] < x)
        {
            binarySearch(v, mid + 1, e, x);
        }
        else
        {
            binarySearch(v, s, mid - 1, x);
        }
    }
    return -1;
}

int rotatedBinary(vector<int> &v, int s, int e, int x)
{
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (v[mid] > v[e])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    int small = s;
    int left = 0;
    int right = v.size() - 1;

    if (x >= v[small] && x <= v[right])
    {
        left = small;
    }
    else
    {
        right = small - 1;
    }
    return binarySearch(v, left, right, x);
}

int main()
{
    vector<int> v = {1, 6, 3, 8, 4, 9};
    sort(v.begin(), v.end());
    bool ans = binarySearch(v, 0, v.size() - 1, 9);
    return 0;
}