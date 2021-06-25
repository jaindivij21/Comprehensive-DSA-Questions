// Saket and Strings
// https://www.youtube.com/watch?v=KbV6SQ6sD6Q
/*
 * Sanket has a string consisting of only 'a' and 'b' as the characters.
 * Sanket describes perfectness of a string as the maximum length substring of equal characters.
 * Sanket is given a number k which denotes the maximum number of characters he can change.
 * Find the maximum perfectness he can generate by changing no more than k characters.
 *
 * Input:
 * 2
 * abba
 * Output:
 * 4 (cuz aaaa)
 */

#include<iostream>
#include<cstring>

using namespace std;

// consider this ex.
// abbabbabbbbaaa

int swap(string s, int n, char x) {
    int left = 0;
    int right = 0;
    int temp = 0;
    int count = 0;
    int largest = 0;
    bool flag = true;

    // run an outside loop that runs until the right pointer is less than the length of the string
    while (right < s.length()) {
        
        // if the element is the one too be swapped increment count
        if (s[right] == x)
            count++;
       
        // used to put value into variable temp --> it holds the value to which left pointer will be brought back to after 
        // we get a specific substring
        // flag is for the fact that we just want a first temp value and not the other ones 
        if (right >= 1 && right != left) {
            if (s[right] != x && s[right - 1] == x)
                if (flag) {
                    temp = right;
                    flag = false;
                }
        }

        // if count gets eql to (1+max num of swaps)      
        if (count == n + 1) {
            // cal the length of the substring 
            int ans = right - left;
            largest = max(largest, ans);

            // update the pointers
            if (left == temp) {
                left = right;
            } else {
                left = temp;
                right = temp;
            }
            count = 0;
            flag = true;
            continue;
        }
        // update right pointer
        right++;
    }

    largest = max(largest, right - left);
    return largest;
}

int main() {
    // input the number of swaps
    int n;
    cin >> n;

    // input the string
    string str;
    cin >> str;

    // call the main functions

    // if the number of swaps is more than the string length
    int temp = str.length();
    if (n >= temp) {
        cout << temp << endl;
        return 0;
    }

    // swap b's w a first then a's w b. Greatest among them is the ans
    char letter = 'a';
    int x = swap(str, n, letter);
    letter = 'b';
    int y = swap(str, n, letter);

    cout << (x >= y ? x : y) << endl;

    return 0;
}