// Small Factorials
// https://www.codechef.com/problems/FCTRL2

// This problem basically asks you to calculate the factorial of a number up to 100. Tricky problem since we need to calculate upto 100, who factorial
// is somethere in the power 10^157. But even if we use unsigned long long int with a size of 8 bytes or 64 bits; we can only store numbers with a max 
// value of 2^64 -1 ==> thats around 10^19. Hence need to use arrays to store the numbers! 

#include<bits/stdc++.h>

using namespace std;

int calFactorial(int arr[], int n) {
    // curr len and elements of array i.e. 120 since we start from 6
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 1;
    int len = 3;

    for (int i = 6; i <= n; i++) {
        // all the multiplications
        int tempLen = 0;
        int carry = 0;
        while (tempLen != len) {
            // number of multiplications in each multiplication
            int x = arr[tempLen] * i + carry;
            arr[tempLen] = x % 10;
            carry = x / 10;
            tempLen++;
        }
        // need to check the carry i.e. if its 0 or not
        if (carry != 0) {
            // if not 0
            while (carry != 0) {
                // until carry is equal to 0, we need to append it in front of the array
                arr[tempLen] = carry % 10;
                carry /= 10;
                tempLen++;
            }
            // update and return the new length
            len = tempLen;
        }
    }
    return len;
}

int main() {
    // input test cases
    int testCases;
    cin >> testCases;

    // for all test cases
    while (testCases--) {
        // input the number
        int n;
        cin >> n;
        if (n <= 5) {
            // if i is less than 5
            int ans[] = {1, 2, 6, 24, 120};
            cout << ans[n - 1] << endl;
            continue;
        } else {
            // if greater than 5 then do the multiplication computation
            int fac[200];   // array that stores the answer in reverse

            // cal the factorial and print it
            int len = calFactorial(fac, n);
            for (int i = len - 1; i >= 0; i--) {
                cout << fac[i];
            }
        }
        cout << endl;
    }

    return 0;
}