// Leetcode : Final Value of Variable After Performing Operations
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

#include <bits/stdc++.h>

using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (auto i : operations)
    {
        if (i[0] == '+' || i[2] == '+')
            x++;
        else
            x--;
    }
    return x;
}

int main()
{

    return 0;
}