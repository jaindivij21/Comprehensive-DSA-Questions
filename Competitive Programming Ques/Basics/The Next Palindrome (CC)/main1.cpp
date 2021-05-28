// The next Palindrome
// https://www.codechef.com/problems/PALIN
// Better Soln: https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
// Better Soln and Submission 2: https://www.youtube.com/watch?v=rLkmrqhoU-A

#include <bits/stdc++.h>

#define lli long long int
using namespace std;

string findNextPalin(string K) {
    lli len = K.length();   // len
    string x = K;   // copy into other string

    // make the palindrome of the current string, by duplicating it through the mid
    for (lli i = len / 2; i < len; i++) {
        K[i] = K[len - i - 1];
    }
    // if the new string is bigger than the original string, it is the answer
    if (K > x) {
        return K;
    } else {
        // else we need to do some work :: add 1 to the mid unless its a 9
        for (lli i = (len - 1) / 2; i >= 0; i--) {
            if (x[i] != '9') {
                // if its not a 9 increment by 1 else put 0
                x[i]++;
                break;
            } else {
                x[i] = '0';
            }
        }
        // finally again make the palindrome of the current string, by duplicating it through the mid
        for (lli i = len / 2; i < len; i++) {
            x[i] = x[len - i - 1];
        }
        // handle the case of 9 by adding 1's
        if (x[0] == '0') {
            x += '1';
            x[0] = '1';
        }
        return x;
    }
}

int main() {
    // input
    int T;
    scanf("%d", &T);
    while (T--) {
        string K;
        cin >> K;
        // find the next smallest palindrome
        cout << findNextPalin(K) << endl;
    }
    return 0;
}
