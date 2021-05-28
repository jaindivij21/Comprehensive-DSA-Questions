// Friends Pairing Problem
// Given n friends who wanna go to the party, each guy can go as a single or as a couple. Find number fo ways in which N friends can go to party
// USE RECURSION

/*
 *  Ex. N = 3
 *      1,2,3
 *      1,2
 *      1,3
 *      2,3
 *      ===> 4 ways in total
 */

#include<iostream>

using namespace std;

// Returns factorial of n
int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

// main
int waysToTravel(int n) {
    // base cases
    if (n == 0) {
        // if no one is left to go thats also a case
        return 1;
    }
    if (n == 1) {
        // single person left at the end, he'll have to go alone
        return 1;
    }
    if (n == 2) {
        // two people left at the end, they can travel in 2 ways i.e 2 singles or 1 couple
        return 2;
    }

    // recursive cases

    // if one friend goes alone (1 way in which he can go, then recursive call on remaining n-1 people)
    int x = 1 * waysToTravel(n - 1);
    // if two friends go together (we multiply it with nCr cuz these 2 people can be any two people)
    int y = nCr(n-1, 1) * waysToTravel(n - 2);
    return x + y;
}

int main() {
    // input the number of friends
    int friends;
    cout << "Enter the number of friends" << endl;
    cin >> friends;

    // main funciton
    cout << "Ways to travel: " << waysToTravel(friends) << endl;

    return 0;
}