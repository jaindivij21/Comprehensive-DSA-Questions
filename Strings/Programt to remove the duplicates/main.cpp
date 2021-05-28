// program to remove duplicates from a string
// we will solve using map

#include <cstring>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int main()
{
    // declarations
    vector <char> arr;
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);

    //  iterators
    vector<char>:: iterator itr;

    //  make the vector
    for(int i = 0; str[i] !='\0'; i++)
    {
        if(isblank(str[i]))
            continue;
        itr = find(arr.begin(), arr.end(), str[i]);
        if(itr != arr.end())
            continue;
        else
            arr.push_back(str[i]);
    }

    for(auto & i: arr)
    {
        cout<<i;
    }
    return 0;
}