// Program to print all the permutations of a string

// there will be n! permutations for a string of length of n
#include<iostream>
#include<cstring>
using namespace std;

void foo(string s, int l, int u)
{
    if(l == u)
        cout<<s<<endl;
    else
    {
        for(int i = l; i <=u; i++)
        {
            // Swapping done
            swap(s[l], s[i]);

            // Recursion called
            foo(s, l+1, u);

            //backtrack
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    int size = s.size();
    foo(s, 0, size-1);
    return 0;
}