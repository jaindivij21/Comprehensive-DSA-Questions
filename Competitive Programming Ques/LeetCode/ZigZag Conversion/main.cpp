// ZigZag Conversion :: LeetCode
// https://leetcode.com/problems/zigzag-conversion/

#include<bits/stdc++.h>

using namespace std;

// converts into zigzag string
string convert(string s, int numRows) {
    // make a map that stores string corresponding to each row (for example if rows = 3, we have 3 rows 1,2, and 3 in our map)
    map<int, string> map;
    int pos = 0;    // represents 1,2,3 
    bool incr = true;

    for (auto c: s) {
        // if the position is 1 then start incrementing and if pos is rows then start decrementing
        if (pos == numRows) incr = false;
        if (pos == 1) incr = true;

        // increase/decrease value of position wrt value of incr
        if (incr) pos++; else pos--;
        
        // finally on that position, add the value to the string (if however the position is not already created, then create it)
        if (map.find(pos) == map.end()) {
            map.insert(make_pair(pos, ""));
        }
        map[pos] += c;
    }
    // finally append the entire answer into a single string to return
    string ans;
    for (auto i: map) {
        ans.append(i.second);
    }
    
    return ans;
}

int main() {
    string str;
    cin >> str;

    int rows;
    cin >> rows;

    string ans = convert(str, rows);
    cout << ans << endl;

    return 0;
}