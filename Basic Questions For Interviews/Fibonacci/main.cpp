// Fibonacci

#include <bits/stdc++.h>

using namespace std;

// 0 1 1 2 3 5 8 ....
int fibo(int n)
{
    if (n <= 1)
        return n;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << fibo(i - 1);
    }
    return 0;
}