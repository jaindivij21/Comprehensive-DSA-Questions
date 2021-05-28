// Tower Of Hanoi
// Classical Recursion Problem

/*
 *  Concept:
 *      * Can move only one disk at a time.
 *      * There cant be a bigger disk over a smaller disk.
 */

#include<iostream>

using namespace std;

// main function
void buildTowerOfHanoi(int n, char src, char help, char dest) {
    // base case
    if (n == 0) // if there are no disks to move
        return;
        // recursive
    else {
        // move 1 to n-1 disks form src to helper using recursion
        buildTowerOfHanoi(n - 1, src, dest, help);    // assume it works
        // shift nth disk from src to dest
        cout << "Shift disk " << n << " from " << src << " to " << dest << endl;
        // finally move the n-1 disks in helper to dest above the nth disk (recursion)
        buildTowerOfHanoi(n - 1, help, src, dest);
    }
}

int main() {
    // input the number of disks
    int n;
    cout << "Enter the number of disks" << endl;
    cin >> n;

    buildTowerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}