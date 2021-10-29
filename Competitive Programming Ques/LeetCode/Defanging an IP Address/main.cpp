// Leetcode : Defanging an IP Address
// https://leetcode.com/problems/defanging-an-ip-address/

#include <bits/stdc++.h>

using namespace std;

string defangIPaddr(string &address)
{
    string ans;
    for (int i = 0; address[i] != '\0'; i++)
    {
        if (address[i] == '.')
        {
            ans += "[.]";
        }
        else
            ans += address[i];
    }
    return ans;
}

int main()
{

    return 0;
}