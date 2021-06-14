// Sort Colors :: Leetcode
// https://leetcode.com/problems/sort-colors/

#include<iostream>
#include<vector>

using namespace std;

// kind of 1 pass algorithm :: insertion sort
void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        // for every element, try to put it at its correct position
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > temp) {
            swap(nums[j], nums[j + 1]);
            j--;
        }
        nums[j + 1] = temp;
    }
}

int main() {
    int size;
    cin >> size;

    vector<int> v;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    insertionSort(v);

    for (auto i: v)
        cout << i << " ";

    return 0;
}