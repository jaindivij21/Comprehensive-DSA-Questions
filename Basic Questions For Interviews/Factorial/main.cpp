// Factorial

#include <bits/stdc++.h>

using namespace std;

int fact(int num)
{
    if (num == 1)
        return 1;
    else
        return num * fact(num - 1);
}

int main()
{
    cout << fact(5);
    return 0;
}