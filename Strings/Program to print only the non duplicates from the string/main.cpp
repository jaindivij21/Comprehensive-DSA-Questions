// program to remove duplicates from a string
// we will solve using map

#include <cstring>
#include <iostream>
#include <map>
#include<algorithm>

using namespace std;
int main()
{
    // declarations
    map <char, int> count;
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);

    //  iterators
    map<char, int>:: iterator it;
    map<char, int>:: iterator itr;

    //  make the map
    for(int i = 0; str[i] !='\0'; i++)
    {
        if(isblank(str[i]))
            continue;

        it = count.find(str[i]);
        if(it == count.end())
        {
            count.insert({str[i],1});
        } else
            it->second++;
    }

    //  main logic
    for(itr=count.begin(); itr != count.end(); itr++)
    {
        if(itr->second % 2 != 0)
            cout<<itr->first;
        else
            continue;
    }

    return 0;
}