#include <cstring>
#include <iostream>
#include <map>
#include<algorithm>

using namespace std;
int main()
{
    map <char,int> count;
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);

    map<char, int>::iterator it ;
    map<char, int>::iterator itr ;

    // make a map
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

    int max = 0;
    char character;
    // find the max
    for(itr = count.begin(); itr != count.end(); ++itr)
    {
        if(itr->second > max)
        {
            max = itr->second;
            character = itr->first;
        }
    }

    cout<<"The max occurrence was "<<character<<" : "<<max<<endl;


    return 0;
}