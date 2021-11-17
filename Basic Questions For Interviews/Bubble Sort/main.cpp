// Bubble Sort using comparater

#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

void bubbleSort(vector<int> &v)
{
    for (int i = 1; i <= v.size() - 1; i++)
    {
        for (int j = 0; j <= v.size() - 1 - i; j++)
        {
            if (compare(v[j], v[j + 1]))
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> v = {1, 6, 3, 8, 4, 9};
    bubbleSort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}