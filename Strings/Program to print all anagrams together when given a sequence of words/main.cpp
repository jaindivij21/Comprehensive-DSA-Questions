// program to print all anagrams together when given a sequence of words
// use of multimap

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

void printAnagramsTogether(string arr[], int size) {
    string mainArr[size];

    // copy the original arr into main arr
    for (int i = 0; i < size; i++) {
        mainArr[i] = arr[i];
    }

    // sort the old array
    for (int i = 0; i < size; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    vector<string> vec[size];

    for (int i = 0; i < size; i++)
    {
        auto it = find(vec->begin(), vec->end(), arr[i]);
        if (it != vec->end())
            continue;
        cout<<mainArr[i]<<" ";
        vec->push_back(arr[i]);
        for (int j = i + 1; j < size; j++)
        {
            if(arr[i]==arr[j])
            {
                cout<<mainArr[j]<<" ";
            }
        }
    }
}

int main()
{
    string wordArr[] = { "cat", "dog", "tac", "god", "act" };
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}