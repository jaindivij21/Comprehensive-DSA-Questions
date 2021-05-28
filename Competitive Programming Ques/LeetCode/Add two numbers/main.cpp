// Longest Substring without repeating characters :: Leet Code
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Make use of hash map and store the indices and numbers itself which exist in substring

#include<bits/stdc++.h>

using namespace std;

int lenOfLSubstring(string s) {
    int maxAns = 0;
    if (s.empty())
        return 0;
    else {
        set<char> window;
        int left = 0;
        int right = 0;
        while (right < s.length()) {
            if (window.find(s[right]) == window.end()) {
                // new char, so add to the set
                window.insert(s[right]);
                right++;
                maxAns = max(maxAns, int(window.size()));
            } else {
                // repeating character :: reduce the window until we remove the re-occurring character
                while (s[left] != s[right]) {
                    window.erase(s[left]);
                    left++;
                }
                // remove the element
                window.erase(s[left]);
                left++;
            }
        }
    }
    return maxAns;
}

int main() {
    string str;
    cin >> str;

    int ans = lenOfLSubstring(str);
    cout << ans << endl;
    return 0;
}