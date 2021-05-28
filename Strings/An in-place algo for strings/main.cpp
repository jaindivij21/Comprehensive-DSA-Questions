// An in-place algorithm for String Transformation
// https://www.geeksforgeeks.org/an-in-place-algorithm-for-string-transformation/
// Given a string, move all even positioned elements to end of string. While moving elements, keep the relative order of all even positioned and odd positioned elements same.

#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

string stringTransform(string s, int n)
{
    string temp1;
    string temp2;

    for(int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            temp1.push_back(s[i]);
        }
        else
        {
            temp2.push_back(s[i]);
        }
    }
    temp1.append(temp2);
    cout<<"The transformed string is "<<temp1<<endl;
}

int main()
{
    string str;
    cout<<"Enter the string:";
    getline(cin, str);

    int length = str.length();
    stringTransform(str, length);

    return 0;
}