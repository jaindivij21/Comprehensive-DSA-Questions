// Sort the Strings
// https://www.youtube.com/watch?v=Z6QZfEL3rxg

// Sort the Strings
// https://www.youtube.com/watch?v=Z6QZfEL3rxg

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string extractString(string str, int key)
{
    // use strtok function to take out the keys to compare them
    // BUT THERE IS A PROBLEM
    // strtok only excepts char array and not string class object, therefore we need to access the address of the
    // string object so as to treat it as a char array
    char *ptr = strtok((char *) str.c_str(), " ");
    while(key>1)
    {
        ptr = strtok(NULL, " ");
        key--;
    }
    return (string)ptr;
}

bool numericCompare(pair<string, string> a, pair<string, string> b){
    int key1, key2;
    key1 = stoi(a.second);
    key2 = stoi(b.second);
    return key1 < key2;
}

bool lexCompare(pair<string, string> a, pair<string, string> b){
    string key1, key2;
    key1 = a.second;
    key2 = b.second;
    // operators for strings by default do it lexographically
    return key1 < key2;
}

int main()
{
    // input the number of strings
    int n;
    cin>>n;
    cin.ignore();

    // make an array to store all the strings
    string a[100];
    for(int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    int key;
    string reversal, ordering;
    cin>>key>>reversal>>ordering;

    // make a array of pairs to store all the strings and their corresponding keys
    pair<string, string> strPair[100];
    for(int i = 0; i<n; i++)
    {
        strPair[i].first = a[i];
        strPair[i].second = extractString(a[i], key);
    }

    // next we need to sort the arrays based on the the mehtod chosen
    if(ordering=="numeric")
        sort(strPair, strPair+n, numericCompare);
    else
        sort(strPair, strPair+n, lexCompare);

    // check for reversal
    if (reversal == "true")
    {
        for(int i = 0; i<n/2; i++)
            swap(strPair[i],strPair[n-i-1]);
    }

    // print the output
    for(int i = 0; i<n; i++)
        cout<<strPair[i].first<<" "<<endl;

    return 0;
}