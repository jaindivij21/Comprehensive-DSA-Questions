#include <bits/stdc++.h>

using namespace std;

// iterative function
void fib1(int num)
{
    if (num == 0)
        return;
    else if (num == 1)
    {
        cout << "0";
        return;
    }
    else if (num == 2)
    {
        cout << "0 1";
        return;
    }
    else if (num > 2)
    {
        int num1 = 0;
        int num2 = 1;
        cout << num1 << " " << num2 << " ";
        for (int i = 3; i <= num; i++)
        {
            int sum = num1 + num2;
            cout << sum << " ";
            num1 = num2;
            num2 = sum;
        }
        return;
    }
    else
    {
        cout << "Wrong input" << endl;
        return;
    }
}

// recursive function
int fib2(int num)
{
    if (num == 1 || num == 2)
        return num - 1;
    else
    {
        return fib2(num - 1) + fib2(num - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    // iterative
    fib1(n);

    cout << endl;

    // recursive
    for (int i = 1; i <= n; i++)
    {
        cout << fib2(i) << " ";
    }
    return 0;
}