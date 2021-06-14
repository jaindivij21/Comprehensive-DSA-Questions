// Sort Colors :: Leetcode
// https://leetcode.com/problems/sort-colors/

#include<iostream>
#include<vector>

using namespace std;

// 2 pass algorithm :: counting algorithm -> works in only those cases, when the max number in array is small
void sortColors(vector<int> &nums) {
    int n = nums.size();
    vector<int> temp(3, 0);
    for (int i = 0; i < n; i++) {
        temp[nums[i]]++;
    }
    int pointer = 0;    // pointer for temp array
    for (int i = 0; i < n; i++) {
        if (temp[pointer] != 0) {
            nums[i] = pointer;
            temp[pointer]--;
        } else {
            pointer++;
            i--;
        }
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

    sortColors(v);

    for (auto i: v)
        cout << i << " ";

    return 0;
}