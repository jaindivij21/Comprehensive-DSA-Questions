// Program to reverse a string using a recursion

#include<iostream>
#include<cstring>
using namespace std;

void reverse(string a)
{
    if (a.length() == 0)
        return;
    else
    {
        reverse(a.substr(1));   // cut the string into a substring leaving one element from the left everytime; 
                                //thus getting left with just the last element
        cout<<a[0];             
    }
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin, str);

    // using substrings and recursion get to the last index of the string and print it
    reverse(str);
    return 0;
}