//  program to Remove characters from the first string which are present in the second string, (output is unordered)

#include<iostream>
#include<map>

using namespace std;

int main()
{
    // enter the strings
    string s1,s2;
    cout<<"Enter the main string:"<<endl;
    getline(cin,s1);
    cout<<"Enter the second string"<<endl;
    getline(cin, s2);

    map<char, int>:: iterator it;
    map<char, int>:: iterator itr;

    // create a map
    map<char, int> map;
    for(int i =0; s1[i]!='\0'; i++)
    {
        if(isblank(s1[i]))
            continue;
        it = map.find(s1[i]);
        if(it == map.end())
        {
            map.insert({s1[i],1});
        } else
            it->second++;
    }
    for(int i =0; s2[i]!='\0'; i++)
    {
        if(isblank(s2[i]))
            continue;
        it = map.find(s2[i]);
        if(it == map.end())
        {
            continue;
        } else
            it->second = 0;
    }
    for(itr=map.begin(); itr != map.end(); itr++) {
        if (itr->second != 0)
            for(int i = 0; i<itr->second; i++)
                cout << itr->first;
        else
            continue;
    }
    return  0;
}