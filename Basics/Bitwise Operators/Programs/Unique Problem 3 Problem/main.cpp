// UNIQUE PROBLEM 3
// In an array all elements appear thrice. Find the number that appears once using bitwise operators

#include<iostream>

using namespace std;

void findOnceOccuring(int n, int arr[]) {
    int arr2[64] = {0};
    int itr = 0;
    for (int i = 0; i < n; ++i) {
        while (arr[i] > 0) {
            arr2[itr] += (arr[i] & 1);
            arr[i] = arr[i] >> 1;
            itr++;
        }
        itr = 0;
    }

    int power = 1;
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        arr2[i] %= 3;
        ans += arr2[i] * power;
        power *= 2;
    }

    cout<<"The single ans is "<<ans<<endl;
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