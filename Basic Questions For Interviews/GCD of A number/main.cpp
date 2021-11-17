// GCD of two number : Recursive

#include <bits/stdc++.h>

using namespace std;

// Euclidien Algo
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int gcd, int n1, int n2)
{
    return (n1 * n2) / gcd;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    int gcdNum = gcd(n1, n2);
    int lcmNum = lcm(gcd, n1, n2);

    cout << gcdNum << lcmNum;

    return 0;
}