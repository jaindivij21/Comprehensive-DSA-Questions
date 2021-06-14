// Plus One :: Leetcode
// https://leetcode.com/problems/plus-one/

#include<bits/stdc++.h>

using namespace std;

// will try to do it; without converting the hassle of converting the array into an int
vector<int> plusOne(vector<int> &digits) {
    vector<int> ans(digits.size() + 1, 0);
    int pointer = digits.size();

    int carry = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
        int temp = 0;
        if (i == digits.size() - 1) {
            temp = digits[i] + 1 + carry;
        } else {
            temp = digits[i] + carry;
        }
        carry = (temp == 10) ? 1 : 0;
        temp = (temp == 10) ? 0 : temp;
        ans[pointer--] = temp;
    }
    if (carry)
        ans[pointer] = carry;
    vector<int> final = ((ans[0] == 0)) ? vector<int>(ans.begin() + 1, ans.end()) : ans;
    return final;
}

int main() {
    int n;
    cin >> n;

    vector<int> num;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    vector<int> ans = plusOne(num);

    for (auto i: ans)
        cout << i << " ";

    return 0;
}