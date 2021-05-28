// Reverse Integer :: LeetCode
// https://leetcode.com/problems/reverse-integer/

#include<bits/stdc++.h>

using namespace std;

pair<int, int> limits() {
    long int x = 1;
    for (int i = 1; i <= 31; i++)
        x *= 2;
    return make_pair(x - 1, -1 * (x));
}

int reverse(int x) {
    pair<int, int> limit = limits();
    int reverseAns = 0;
    while (x != 0) {
        int temp = x % 10;
        x /= 10;

        reverseAns *= 10;
        reverseAns += temp;
    }
    return (reverseAns >= limit.second && reverseAns <= limit.first) ? reverseAns : 0;
}

int main() {
    int num;
    cin >> num;

    int ans = reverse(num);

    cout << ans << endl;

    return 0;
}