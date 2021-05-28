// string sort lexographically & if same then bigger len first
// bat, apple, batman -> apple, batman, bat

// manual program

#include <iostream>
#include <algorithm>

using namespace std;

// main fun that compares the strings
int compareTo(string s1, string s2) {

    int i = 0;
    // run the loop till the len of smaller string due to AND condition
    while (i < s1.length() && i < s2.length()) {
        // check the stirng lexographically
        if (s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }
    // if they are equal uptil the len of smaller string
    // then sort by larger string coming first
    if (s1.length() > s2.length()) {
        return -1;
    } else {
        return 1;
    }
}

// bubble sort function but for strings
void sortfunc(string arr[], int n) {
    // for all the strings
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            if (compareTo(arr[j], arr[j + 1]) > 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

}

int main() {
    // input the size of string array and the strings in the array
    int n;
    cin >> n;
    string str[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    // sort
    sortfunc(str, n);
    
    // display the result
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
}

