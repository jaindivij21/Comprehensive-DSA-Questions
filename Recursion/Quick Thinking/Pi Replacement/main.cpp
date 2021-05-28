// Replace pi in String to 3.14
// USE RECURSION (inplace)
// Ex. xpifgpi --> x3.14fg3.14

#include<iostream>
#include<cstring>

using namespace std;

// replace pi function where we pass the array and the inital position
void pi(char *a, int i) {
    // base case
    if (a[i] == '\0') {
        // reach the end of string
        return;
    }
    // recursive case (look for pi)
    if (a[i] == 'p' && a[i + 1] == 'i') {
        // found pi
        // forward shift the the following subarray and adding 3.14 inplace of pi

        // bring a new counter j to the end of string
        int j = i + 2;
        while (a[j] != '\0')
            j++;

        // shifting
        while (j >= i + 2) {
            a[j + 2] = a[j];
            j--;
        }

        // replace
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';

        // recursive call in remaining subarray after 3.14 added
        pi(a, i + 4);

    } else {
        // not the end of string nor found pi, therefore just iterate forward into the string
        pi(a, i + 1);
    }
}

int main() {
    // limit the string lenght to 100 characters
    char str[100];

    // input
    cout << "Enter the string" << endl;
    cin.get(str, 100);

    //  main
    pi(str, 0);

    // print output str
    for (int i = 0; i < strlen(str); i++)
        cout << str[i];
    cout << endl;
    return 0;
}