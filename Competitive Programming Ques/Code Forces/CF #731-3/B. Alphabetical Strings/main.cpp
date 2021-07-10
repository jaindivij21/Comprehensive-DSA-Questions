// B. Alphabetical Strings
// 2-pointer approach
#include<bits/stdc++.h>

using namespace std;

// linear search
int search(string str, char x) {
    for (int i = 0; i < str.size(); i++)
        if (str[i] == x)
            return i;
    return -1;
}

// main solve function
void solve() {
    // input the string
    string str;
    cin >> str;

    // if str len is 1 or len is 2
    if ((str.size() == 1 && str == "a") || (str.size() == 2 && (str == "ab" || str == "ba"))) {
        cout << "YES" << endl;
        return;
    }
    // if str size is greater than or eql to 3
    if (str.size() >= 3 && str.size() <= 26) {
        // find a
        int index = search(str, 'a');
        if (index == -1) {
            // a not found in this case
            cout << "NO" << endl;
            return;
        }
        int l = index - 1;
        int r = index + 1;

        char alpha = 'a' + 1;    // 'b' since index is a
        while (l >= 0 || r <= str.size() - 1) {
            // loop exits as both of the limit passes its last position
            if (l >= 0 && str[l] == alpha) {
                // if this alphabet exists at left
                l--;
                alpha++;
                continue;
            } else if (r <= str.size() - 1 && str[r] == alpha) {
                // if this alphabet exists at right
                r++;
                alpha++;
                continue;
            } else {
                // if the alphabet doesn't exists neither on the left or right
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    // if nothing holds true, return false
    cout << "NO" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}