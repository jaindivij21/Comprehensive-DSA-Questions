// Program to check if two strings are anagrams of each other

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void ifAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        cout<<"They are not!"<<endl;
    else{
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int ans = s1.compare(s2);
        if(ans == 0)
            cout<<"They are!"<<endl;
        else
            cout<<"They are not!"<<endl;
    }
}

int main()
{
    // input the strings
    string s1, s2;
    cout<<"Enter the first string:";
    getline(cin, s1);
    cout<<"Enter the second string:";
    getline(cin, s2);

    // check if anagram
    ifAnagram(s1,s2);
}