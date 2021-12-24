
// Print all the subset of a string or array
// O(2^n)->Exponential
/*
 *  One of the efficient methods to such a question is that we can use bit masking and use bitmasks to take out all the subsets.
 *  Other method is to use recursion to take out all the subsets.
 *
 *  The following implementation is of printing all the subsets (powerset) of the string/array using recursion.
 *  https://www.youtube.com/watch?v=mEBEw_xScsE&ab_channel=AnujBhaiya
 */

#include <bits/stdc++.h>

using namespace std;

// helper function
void helper(string s, int index, string curr)
{
    // base case
    if (index == s.length())
    {
        // if the index becomes equal to the string length then print whatever is in the current string
        cout << curr << endl;
        return;
    }
    // recursive case -> 2 cases :: 1) index increases && add character 2) just the index increases
    helper(s, index + 1, curr + s[index]);
    helper(s, index + 1, curr);
}

// main function
void findAllSubsets(string str)
{
    string curr = "";
    helper(str, 0, curr);
}

int main()
{
    string str;
    cin >> str;

    findAllSubsets(str);

    return 0;
}