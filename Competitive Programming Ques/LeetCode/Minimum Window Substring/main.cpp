// Minimum Window Substring :: Leetcode
// https://leetcode.com/problems/minimum-window-substring/
// https://www.youtube.com/watch?v=nMaKzLWceFg

// sliding window or 2 pointers

#include<bits/stdc++.h>

using namespace std;

string minWindow(string s, string t) {
    // if length is 0
    if (s.length() == 0 || t.length() == 0) {
        return "";
    }

    // declare map
    unordered_map<char, int> map;
    // fill the map with the characters of the target string
    for (auto c: t) {
        if (map.find(c) == map.end()) {
            map.insert(make_pair(c, 1));
        } else {
            map[c]++;
        }
    }

    // main solution
    int count = 0;  // keeps count of all the chars (from target) that have appeared in string
    int l = 0;  // sliding window's left pointer (i is the right pointer)

    // variable to store the answer (ans string's length and start pointer)
    int minLength = INT_MAX;
    int minLeft = 0;

    for (int i = 0; i < s.length(); i++) {
        // incrementing right window one by one
        if (map.find(s[i]) != map.end()) {
            // if elem in map is found decrement its map val (if -ve means in excess)
            map[s[i]]--;
            // if that elements val in map is +ve or 0 means that means we have to include it
            if (map[s[i]] >= 0) {
                count++;
            }
        }

        // count value is 1 so make it eql to 3
        while (count == t.length()) {
            // eligible window
            // length save
            if (minLength > i - l + 1) {
                minLength = i - l + 1;
                minLeft = l;
            }
            //  diminish the window using left pointer
            if (map.find(s[l]) != map.end()) {
                map[s[l]]++;    // remove it hence increment the value
                if (map[s[l]] > 0) {
                    // found the char from target string and removed it so reduce the count
                    count--;
                }
            }
            l++;
        }
    }
    if (minLength > s.length())
        return "";
    return s.substr(minLeft, minLength);
}

int main() {
    string string1;
    cin >> string1;
    string string2;
    cin >> string2;

    cout << minWindow(string1, string2);

    return 0;
}