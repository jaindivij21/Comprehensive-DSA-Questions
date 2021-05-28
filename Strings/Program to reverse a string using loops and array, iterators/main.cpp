// Program to reverse a string using a loop and array iterator

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin, str);

    int length =  str.length();
    for(auto itr = str.end()-1; itr != str.begin()-1; itr--)
        cout<<*itr;
    return 0;
}