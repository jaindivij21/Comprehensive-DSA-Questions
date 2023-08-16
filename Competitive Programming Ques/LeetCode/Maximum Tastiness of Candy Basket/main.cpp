// Leetcode:  Maximum Tastiness of Candy Basket
// https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/
// Similar Problem (Inspiration): https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

// Helper Method
// Returns true or false based on if the threshold value or greater than threshold value can be equal to
// the minimum of the absolute differences of k pairs in price array
// Basically find a subsequence from price array where the difference is greater than equal to threshold.
bool isValid(vector<int> &price, int threshold, int k) {
    int count = 1, i = 1, last = 0;
    while (count < k && i < price.size()) {
        if (price[i] - price[last] >= threshold) {
            last = i;
            count++;
        }
        i++;
    }

    return count == k;
}

// Method that returns the maximum value of the smallest absolute difference of the prices of any two candies in
// the basket with k candies.
int maximumTastiness(vector<int> &price, int k) {
    // Sort the array in ascending order
    sort(price.begin(), price.end());

    // Result variable
    int result = INT_MIN;

    // Implement a Binary Search
    int left = 0;
    int right = price.back() - price[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isValid(price, mid, k)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int size;
    cin >> size;

    int k;
    cin >> k;

    vector<int> price(size);
    for (int i = 0; i < size; i++) {
        cin >> price[i];
    }

    cout << maximumTastiness << endl;

    return 0;
}