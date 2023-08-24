// Leetcode: Account Balance After Rounded Purchase
// https://leetcode.com/problems/account-balance-after-rounded-purchase

#include<iostream>

using namespace std;

int accountBalanceAfterPurchase(int purchaseAmount) {
    int num = purchaseAmount % 10;
    if (num < 5) {
        return 100 - (purchaseAmount - num);
    } else {
        return 100 - (purchaseAmount + (10 - num));
    }
}

int main() {
    int purchaseAmount;
    cin >> purchaseAmount;

    cout << accountBalanceAfterPurchase(purchaseAmount) << endl;

    return 0;
}