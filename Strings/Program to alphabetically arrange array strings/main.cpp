// program to alphabetically order the array of strings

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printArray(vector<string> arr)
{
    for(int i = 0; i<arr.size(); i++)
        cout<<i<<". "<<arr[i]<<endl;
}

bool myComp(string a, string b)
{
    return a<b;
}

vector<string> alphaSort(vector<string> arr)
{
    sort(arr.begin(), arr.end(), myComp);
    return arr;
}

int main()
{
    vector<string>  arr;
    cout<<"Enter the number of strings:";
    int n;
    cin>>n;
    cin.ignore();

    string temp;
    cout<<"Enter the strings:"<<endl;

    for(int i =0; i<n ;i++)
    {
        getline(cin, temp);
        arr.push_back(temp);
    }

    cout<<"\n"<<"Array before sorting: "<<endl;
    printArray(arr);

    arr = alphaSort(arr);

    cout<<"\n"<<"Array after sorting: "<<endl;
    printArray(arr);

    return 0;
}