// Program to find pair of elements which sum to zero using hashing/hashmap in an array
// 0(N)

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
    // keep adding numbers to the hash map and at the same time keep checking for their complementary numbers so that they add upto 0
    int arr[] = {1, 3, -2, 6, 2, 7, -6};

    // map stores the numbers and their indexes
    unordered_map<int, int> map;
    for (int i = 0; i < 7; i++) {
        map.insert(make_pair(arr[i], i));
        auto itr = map.find(-1 * arr[i]);
        if (itr != map.end()) {
            // complementary element found, therefore print the pair
            cout << "Pair: " << itr->first << "," << arr[i] << endl;
        }
    }

    return 0;
}