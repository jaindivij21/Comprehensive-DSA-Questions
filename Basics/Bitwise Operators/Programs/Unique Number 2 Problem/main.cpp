// UNIQUE NUMBER 2
// We are given an array of n numbers. All the numbers are present twice except for 2 numbers
// which are present once.
// Use bitwise to find those 2 numbers

#include<iostream>

using namespace std;

void findOnceOccuring(int n, int arr[]) {
    // do XOR of all the numbers
    int a = 0;
    for (int i = 0; i < n; i++)
        a = a ^ arr[i];
    int temp = a;

    // find the postition of first set bit from the right
    // WHY? --> if a bit is set after xor means that both the nums have different bits at that position.
    int pos = -1;
    int x = 0;
    while (pos < 0) {
        if ((a & 1) == 1) {
            pos = x;
        }
        x++;
        a = a >> 1;
    }

    // find all the numbers that have a set bit at position and XOR them. Those appering 2 times will cancel and we'll get our first ans
    int ans1 = 0;
    int mask = 1 << pos;
    for (int i = 0; i < n; i++) {
        if ((arr[i] & mask) > 0)
            ans1 = ans1 ^ arr[i];
    }
    // we get ans 1
    // now for ans 2
    int ans2 = ans1 ^temp;

    cout << "The two numbers are " << min(ans1, ans2) << " " << max(ans1, ans2) << endl;
}

int main() {
    cout << "Enter the array size" << endl;
    int size;
    cin >> size;
    cout << "Enter the array" << endl;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    findOnceOccuring(size, arr);

    return 0;
}