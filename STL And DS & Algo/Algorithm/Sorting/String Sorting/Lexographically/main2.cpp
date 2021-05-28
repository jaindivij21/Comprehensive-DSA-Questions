// string sort lexographically & if same then bigger len first
// bat, apple, batman -> apple, batman, bat

#include<iostream>
#include<algorithm>

using namespace std;

// main compare function
bool myCompare(string a, string b) {
    // if iterators return 0 that is one string is substring to the other one and is present at index 0 of it then,
    if (a.find(b) == 0 || b.find(a) == 0)
        // return desceding in order of their length
        return a.length() > b.length();
    else
    {
        // return ascending lexographically
        return a < b;
    }
}

int main() {
    // input the information
    int noOfStrings;
    cout << "Enter the number of strings:";
    cin >> noOfStrings;

    cout << "Enter the strings:" << endl;
    cin.ignore();

    // array of strings
    string str[noOfStrings];
    // input all the strings in the array
    for (int i = 0; i < noOfStrings; i++) {
        getline(cin, str[i]);
    }

    sort(str, str + noOfStrings, myCompare);

    // display sorted strings
    for (int i = 0; i < noOfStrings; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
