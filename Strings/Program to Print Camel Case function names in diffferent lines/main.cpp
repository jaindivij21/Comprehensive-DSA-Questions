// Write a program to break the camel case into different lines
/*
 *  INPUT:
 *  IAmACompetitiveProgrammer
 *  
 *  OUTPUT:
 *  I
 *  Am
 *  A
 *  Competitive
 *  Programmer
 */

#include<iostream>
#include<cstring>

using namespace std;

int main() {
    // input the string
    string str;
    cin >> str;

    // print the first string element
    cout << str[0];
    for (int i = 1; i < str.length(); i++) {
        // if the element is CAPITAL i.e. ASCII is less than 97, first print a newline char
        if (str[i] < 97)
            cout << "\n";
        cout << str[i];
    }

    return 0;
}