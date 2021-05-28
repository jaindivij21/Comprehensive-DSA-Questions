// Program to divide a string w each each substring of n length
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    cout<<"Enter the string"<<endl;
    string str;
    getline(cin, str);
    cout<<"Enter the length of equal parts"<<endl;
    int n;
    cin>>n;

    string r;

    int count = 0;
    for (int i =0; str[i]!='\0'; i+=(n+1)) {
        r = str.substr(i, n);
        cout << r << endl;
    }
}