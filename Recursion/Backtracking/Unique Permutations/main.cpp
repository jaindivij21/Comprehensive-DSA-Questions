// Unique Permutations
// Given a string s like 'abc', find all the permutations of the string i.e. like bac, cab, abc, cba.... so on!
// Diagram: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/


// The difference bw normal and unique permutations is that you can use *SETS*  to just store the unique
#include<iostream>
#include<set>
#include<cstring>

using namespace std;

int count = 0;

// main function, passes the string and the iterator with the set (passed by reference &)
void permutate(string str, int i, set<string> &s) {
    // base case
    if (str[i] == '\0') {
        s.insert(str);
        // cout << str << endl;
        // count++;
        return;
    }
    // recursive case
    // for all the letter in the string
    for (int j = i; str[j] != '\0'; j++) {
        // swap the letters and call the recursive function on the remaining part
        swap(str[i], str[j]);
        permutate(str, i + 1, s);

        // Backtracking steps
        swap(str[i], str[j]);
    }
}

int main() {
    // input the string from the user
    cout << "Enter the string whose permutations are required" << endl;
    string str;
    cin >> str;

    // make the sets
    set<string> s;

    // main funciton
    permutate(str, 0, s);

    // cout << "The number of permutations are:" << count << endl;
    for (auto item: s) {
        cout << item << endl;
    }

    return 0;
}