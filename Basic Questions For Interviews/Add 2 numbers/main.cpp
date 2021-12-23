// add two numbers

#include <bits/stdc++.h>

using namespace std;

int add(vector<int> &a, vector<int> &b)
{
    int ans = 0;
    int mul = 1;
    int i = a.size() - 1;
    int j = b.size() - 1; // pointers

    int addition;
    int carry = 0;
    while (i != -1 && j != -1)
    {
        addition = a[i] + b[j] + carry;
        carry = 0;
        if (addition >= 10)
        {
            carry = 1;
            addition = addition % 10;
        }
        ans = ans + mul * addition;
        mul *= 10;
        i--;
        j--;
    }
    if (i == -1 && j == -1)
    {
        if (carry == 1)
        {
            ans = ans + mul * carry;
        }
    }
    else if (i == -1)
    {
        while (j != -1)
        {
            addition = b[j] + carry;
            carry = 0;
            if (addition >= 10)
            {
                carry = 1;
                addition = addition % 10;
            }
            ans = ans + mul * addition;
            mul *= 10;
            j--;
        }
    }
    else
    {
        while (i != -1)
        {
            addition = a[i] + carry;
            carry = 0;
            if (addition >= 10)
            {
                carry = 1;
                addition = addition % 10;
            }
            ans = ans + mul * addition;
            mul *= 10;
            i--;
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {9, 5, 4, 9};
    vector<int> b = {2, 1, 4};
    cout << add(a, b);

    return 0;
}
