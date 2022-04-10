// Program to add two numbers
#include <bits/stdc++.h>
using namespace std;

int add(vector<int> &a, vector<int> &b)
{
    int ans = 0;
    int mul = 1;
    int carry = 0;

    int p1 = a.size() - 1;
    int p2 = b.size() - 1;

    while (p1 >= 0 && p2 >= 0)
    {
        int add = carry + a[p1] + b[p2];
        if (add >= 10)
        {
            carry = 1;
            add %= 10;
        }
        else
        {
            carry = 0;
        }
        ans += mul * add;
        mul *= 10;
        p1--;
        p2--;
    }
    while (p1 >= 0)
    {
        int add = carry + a[p1];
        if (add >= 10)
        {
            carry = 1;
            add %= 10;
        }
        else
        {
            carry = 0;
        }
        ans += mul * add;
        mul *= 10;
        p1--;
    }
    while (p2 >= 0)
    {
        int add = carry + b[p2];
        if (add >= 10)
        {
            carry = 1;
            add %= 10;
        }
        else
        {
            carry = 0;
        }
        ans += mul * add;
        mul *= 10;
        p2--;
    }
    if (carry == 1)
        ans += mul * carry;
    return ans;
}

int main()
{
    vector<int> a = {9, 9, 9};
    vector<int> b = {9, 9};

    cout << add(a, b) << endl;

    return 0;
}