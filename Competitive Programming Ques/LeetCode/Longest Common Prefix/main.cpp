// Longest Common Prefix: Leetcode
// https://leetcode.com/problems/longest-common-prefix/

#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &str) {
    string ans = "";
    if (str.size() == 0) return ans;

    for (int i = 0; i < str[0].size(); i++) {
        char c = str[0][i];
        for (int j = 1; j < str.size(); j++) {
            if (i >= str[j].size() || str[j][i] != c) {
                return ans;
            } else {
                continue;
            }
        }
        ans += c;
    }
    return ans;
}

int main() {
    int size;
    cin >> size;
    vector<string> v;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    string ans = longestCommonPrefix(v);
    cout << ans << endl;

    return 0;
}