// Program to calculate exponenets of numbers fast using recursion
// Instead of normal exponentitaion that takes O(N) space we'll reduce the call stack space by reducing the recursion ==> O(logN) TC

// CONCEPT -> a^n = (a^(n/2))^2 instead of a^n = a*a^(n-1) --> therefore the recursive function becomes dividing instead of decreasing, reducing time complexity
/*
 *  It'll be different for odd and even
 *  ODD:
 *    Ex. a^9 = a*(a^(9/2))^2 
 *  EVEN:
 *    Ex. a^8 = (a^(9/2))^2 
 * 
*/


#include<iostream>

using namespace std;

int calPowerUsingRec(int n, int p) {
    // base case
    if (p == 0)
        return 1;
    // recursive call
    int temp = calPowerUsingRec(n, p / 2);
    temp *= temp;   // square temp

    if (p & 1) {
        // power is odd
        return n * temp;
    } else {
        // even
        return temp;
    }
}

int main() {
    // input the numbers
    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    cout << "Enter the power" << endl;
    int p;
    cin >> p;

    cout << "Ans: " << calPowerUsingRec(n, p) << endl;

    return 0;
}
