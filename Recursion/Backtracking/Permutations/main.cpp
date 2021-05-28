// Permutations
// Given a string s like 'abc', find all the permutations of the string i.e. like bac, cab, abc, cba.... so on!
// Diagram: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<iostream>

using namespace std;

int count = 0;

// main function, passes the string and the iterator
// we make changes in the same string itself; therefore no output string
void permutate(string str, int i) {
    // base case
    if (str[i] == '\0') {
        cout << str << endl;
        count++;
        return;
    }
    // recursive case
    // for all the letter in the string
    for (int j = i; str[j] != '\0'; j++) {
        // swap the letters and call the recursive function on the remaining part
        swap(str[i], str[j]);
        permutate(str, i + 1);

        // Backtracking steps
        swap(str[i], str[j]);
    }
}

int main() {
    // input the string from the user
    cout << "Enter the string whose permutations are required" << endl;
    string str;
    cin >> str;

    // main funciton
    permutate(str, 0);

    // print a count
    cout << "The number of permutations are:" << count << endl;

    return 0;
}