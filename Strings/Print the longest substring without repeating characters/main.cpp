// print the longest substring without repeating characters
// https://www.geeksforgeeks.org/print-longest-substring-without-repeating-characters/

#include<bits/stdc++.h>

using namespace std;

// sliding window
string lss(string s) {
    string ans;
    
    // map for holding the positions (not indexes of the characters)
    unordered_map<char, int> map;

    // for ans, the maximum len and the starting index of lonegst substring
    int startIndexOfAns;
    int maxCount = 0;

    // for every index on the
    int l = 0;   // positions for sliding window
    for (int r = 0; r < s.size(); r++) {
        if (map.find(s[r]) == map.end()) {
            // unique : not already in the hash map -> insert it into the hash map
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
            // finally insert into the hash map the char which was the repeatin one and has been removed by the above loop
            map.insert(make_pair(s[r], r));
        }
    }
    // return ans
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