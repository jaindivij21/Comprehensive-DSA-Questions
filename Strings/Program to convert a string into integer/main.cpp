// Implement the STOI Function
// Program to convert a string into interger

#include<iostream>
#include<cstring>

using namespace std;

int convert(string str)
{
    int ans = 0;
    int p = 1;
    for(int i = str.length() - 1; i >= 0; i--)
    {
        ans += ((str[i]-'0')*p);
        p *= 10;
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    int x = convert(s);
    
    // Print out the string multiplied by 10 
    cout<<x*10;

    return 0;
}