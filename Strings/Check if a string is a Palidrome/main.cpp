// Program to check if a string is a palindrome

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string word;
    cout<<"Enter the word:"<<endl;
    cin>>word;

    int len = word.length();
    for(int i = 0; i<(len/2)+1; i++)
    {
        if(word[i] != word[len-i-1])
        {
            cout<<"Not a Palindrome"<<endl;
            exit(1);
        }
    }
    cout<<"A Palindrome"<<endl;

    return 0;
}