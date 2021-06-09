// Longest Substring Without Repeating Characters :: Leetcode
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Sliding Window Problem : O(n)
// We basically need a hash map/set like data structure to maintain char uniqueness

#include<bits/stdc++.h>

using namespace std;

int ans(string s) {
    int maxAns = INT_MIN;

    // define set and pointers
    set<int> window;
    int left = 0;
    int right = 0;
    while (right <= s.length() - 1) {
        if (window.find(s[right]) == window.end()) {
            // unique element in current window
            window.insert(s[right]);
            right++;
        } else {
            // collision, found in set :: so remove all the elements leading upto the problem element (inclusive) and shorten the window
            while (s[left] != s[right]) {
                // erase the elements upto the problem element
                window.erase(s[left]);
                left++;
            }
            // erase the problem element
            window.erase(s[left]);
            left++;
        }
        maxAns = max(maxAns, int(window.size()));
    }
    return maxAns;
}

int main() {
    string str;
    cin >> str;
    cout << ans(str);
    return 0;
}