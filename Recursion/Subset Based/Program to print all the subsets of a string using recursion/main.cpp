// Program to print all the subsequences of a string
// BACKTRACKING (RECURSION)

#include<iostream>

using namespace std;

// count variable
int count = 0;

// recurisve function to print all the subsequences
void generateAllSubsequences(string input, string output, int i) {
    // base case
    if (input[i] == '\0') {
        // means the end of the input string, means now we can print the output string
        cout << output << endl;
        count++;
        return;
    }
    // recursive case
    char x = input[i];   // x stores what is at ith index of input array
    // 2 ways to go, either include x or exclude x character

    // exclude (generating empty string first)
    generateAllSubsequences(input, output, i + 1);
    // include
    output.push_back(x);
    generateAllSubsequences(input, output, i + 1);
}

int main() {
    string input;
    cout << "Enter the string" << endl;
    cin >> input;
    string output; // empty string

    // make iterators for both input string
    int i = 0;  // input

    // main function
    cout << "The subsequences are: " << endl;
    generateAllSubsequences(input, output, i);

    // print the number of subsequences
    cout << "The number of subsequences: " << count << endl;

    return 0;
}