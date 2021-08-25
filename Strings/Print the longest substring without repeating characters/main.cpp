// print the longest substring without repeating characters
// https://www.geeksforgeeks.org/print-longest-substring-without-repeating-characters/

#include<bits/stdc++.h>

using namespace std;

// sliding window
string lss(string s) {
    string ans;
    int l = 0;   // positions for sliding window
    // map for holding the positions (not indexes of the characters)
    unordered_map<char, int> map;

    int startIndexOfAns;
    int maxCount = 0;
    // for every index on the
    for (int r = 0; r < s.size(); r++) {
        if (map.find(s[r]) == map.end()) {
            // unique
            map.insert(make_pair(s[r], r));   // insert the char and its index
        } else {
            // if already inside the hash map :: remove from the hash map all the earlier occurrences, update start index and max count and finally update l and r
            if (r - l > maxCount) {
                startIndexOfAns = l;
                maxCount = r - l;
            }
            while (l < r) {
                map.erase(s[l]);
                l++;
            }
            map.insert(make_pair(s[r], r));
        }
    }
    ans = s.substr(startIndexOfAns, maxCount);
    return ans;
}

// main function
int main() {
    string str;
    getline(cin, str);
    string ans = lss(str);
    cout << ans;
    return 0;
}