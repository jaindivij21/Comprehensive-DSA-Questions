// The next Palindrome
// https://www.codechef.com/problems/PALIN
// Better Soln: https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
// Better Soln and Submission 2: https://www.youtube.com/watch?v=rLkmrqhoU-A

#include<bits/stdc++.h>

using namespace std;

int AreAll9s(vector<int> num) {
    // checks if all the digits in the string are 9
    int n = num.size();
    int i;
    for (i = 0; i < n; ++i)
        if (num[i] != 9)
            return 0;
    return 1;
}

void findNextPalin(vector<int> &number) {
    int n = number.size();

    // mid index
    int mid = n / 2;

    // 2 pointers, one that runs towards left and other towards right
    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;   // begin of right side depends upon if the len is even or odd

    // ignore if the digits are same
    while (i >= 0 && number[i] == number[j])
        i--, j++;

    // check if the ith index is greater or smaller than its j counterpart || ALSO if the entire string is already a palindrome
    // i.e. i or j cross the boundary
    bool flag;
    if (number[i] < number[j] || i < 0)
        flag = true;
    else
        flag = false;

    // if flag is true, then we need to add 1 to the middle and propagate carry

    // but first mirror the left elements on the right which are left
    while (i >= 0) {
        number[j] = number[i];
        i--;
        j++;
    }

    // now handle the case of +1 or string already being a palindrome.
    // In this case we need to add 1 and propagate the carry
    if (flag) {
        int carry = 1;
        i = mid - 1;
        if (n % 2 == 1) {
            number[mid] += carry;
            carry = number[mid] / 10;
            number[mid] %= 10;
            j = mid + 1;
        } else
            j = mid;

        while (i >= 0) {
            number[i] += carry;
            carry = number[i] / 10;
            number[i] %= 10;

            // Copy mirror to right
            number[j++] = number[i--];
        }
    }
}

int main() {
    // test cases
    int t;
    cin >> t;
    while (t--) {
        // input
        vector<int> number;
        string str;
        cin >> str;
        for (char i : str)
            number.push_back(i - '0');

        // Corner Cases
        // erases if there are any 0's in the begin
        while (number[0] == 0)
            number.erase(number.begin());
        // string of len 0
        if (number.size() == 0)
            number.push_back('0');

        // if all the digits are 9
        if (AreAll9s(number)) {
            cout << 1;
            for (int i = 1; i < number.size(); i++)
                cout << 0;
            cout << 1;
        } else {
            // normal string
            findNextPalin(number);
            // print the answer
            for (int i = 0; i < number.size(); i++) {
                cout << number[i];
            }
            cout << endl;
        }
    }
    return 0;
}


