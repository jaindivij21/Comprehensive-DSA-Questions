// A Program to check if strings are rotations of each other or not

#include<iostream>
#include<cstring>
using namespace std;

bool isRotation(string a, string b)
{
    if (b.length() != a.length())
        return false;

    string temp = a + a;

    int pos = temp.find(b);
    if (pos == string::npos)
        return false;
    else
        return true;
}

int main()
{
    //  input strings
    string a,b;
    cout<<"Enter the first string:"<<endl;
    getline(cin, a);
    cout<<"Enter the second string:"<<endl;
    getline(cin, b);

    // function
    bool c = isRotation(a, b);
    if (c == 0)
        cout<<"The strings are not rotations"<<endl;
    else
        cout<<"The strings are rotations"<<endl;

    return 0;
}