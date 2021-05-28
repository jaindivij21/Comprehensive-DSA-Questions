// program for pattern searching in a string

#include<iostream>
#include<cstring>

using namespace std;

void patternCheck(string s1, string s2) {
    // calculate length of both the strings
    int len1 = s1.length();
    int len2 = s2.length();

    // set i = 0
    int i = 0;
    // run a loop
    for (int j = 0; j < len1; j++) {
        // compare strings 1 and 2
        if (s1[j] == s2[i]) {
            i++;    // increment i if that index is equal
            if (i == len2) {
                // and if the value of i which is the number of times the string indexes have been equal is equal 
                // to the len of pattern, then its a match
                cout << "Pattern found at index " << (j - len2 + 1) << endl;
                
                // reset i = 0 and j = next index from where the pattern matched last time 
                j = j-len2 + 1;
                i = 0;
            }
        } 
        // if there's no match 
        else {
            // reset j to next index from where the pattern matching started
            if (i > 1)
                j = j - i;
            // reset i and continue
            i = 0;
            continue;
        }
    }
}


int main() {
    string str;
    string toBeSearched;

    // input the strings
    cout << "Enter the main string:";
    getline(cin, str);

    cout << "Enter the pattern string to be searched:";
    getline(cin, toBeSearched);

    // calling the main function
    patternCheck(str, toBeSearched);

    return 0;
}