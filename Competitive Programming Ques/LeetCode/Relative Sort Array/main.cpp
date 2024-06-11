// Leetcode: Relative Sort Array
// https://leetcode.com/problems/relative-sort-array

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int, int> positions;

// Comparator function for sorting arr1 based on positions in arr2
bool customComparator(int a, int b) {
    // If both elements are in arr2, compare their positions
    if (positions.find(a) != positions.end() && positions.find(b) != positions.end()) {
        return positions[a] < positions[b];
    }
        // If only 'a' is in arr2, it should come before 'b'
    else if (positions.find(a) != positions.end()) {
        return true;
    }
        // If only 'b' is in arr2, it should come after 'a'
    else if (positions.find(b) != positions.end()) {
        return false;
    }
        // If neither 'a' nor 'b' are in arr2, maintain their relative order
    else {
        return a < b;
    }
}

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    // Store positions of elements in arr2 in a hash
    for (int i = 0; i < arr2.size(); i++) {
        positions[arr2[i]] = i;
    }

    // Sort arr1 using customComparator
    sort(arr1.begin(), arr1.end(), [](int a, int b) {
        return customComparator(a, b);
    });

    return arr1;
}

int main() {
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> ans = relativeSortArray(arr1, arr2);

    for (auto ele: ans) {
        cout << ele << " ";
    }

    return 0;
}