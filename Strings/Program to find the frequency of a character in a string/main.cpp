// Program to find the frequency of a character in a string 

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str;
    char ch;
    int count = 0;

    cout<<"Enter a string: ";
    getline(cin, str);

    cout<<"Enter a character to find its frequency: ";
    cin>>ch;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(ch == str[i])
            count++;
        else
            continue;
    }

    cout<<"The final count is: "<<count<<endl;
    return 0;
}