// False Number
// https://www.codechef.com/LTIME97C/problems/FALSNUM
// June 2021 Lunchtime Div 3

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        if (str[0] == '1') {
            // if first element is 1
            str.insert(1, "0");
        } else {
            // if first element not 1
            str.insert(0, "1");
        }
        cout << str << endl;
    }
    return 0;
}