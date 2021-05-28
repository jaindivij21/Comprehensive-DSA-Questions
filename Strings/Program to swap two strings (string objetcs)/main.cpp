// program to swap two strings

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    string s1;
    string s2;

    cout<<"Input both the strings "<<endl;
    getline(cin, s1);
    getline(cin, s2);

    cout<<s1<<" "<<s2<<endl;
    s1.swap(s2);
    cout<<s1<<" "<<s2<<endl;

    return 0;
}