// Sliding window Problem: Find the maximum element in a window of k elements in an array
// USING DEQUE (efficient)

/*
 *  Sample Input:
 *      9
 *      1 2 3 1 4 5 2 3 6
 *      3
 *  Sample Output:
 *      3 3 3 4 5 5 5 6
 */

#include <iostream>
#include<deque>

using namespace std;

int main() {
    int n;
    int k;

    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;

    //We have to process first k elements separately
    deque<int> Q(k);
    int i;
    for (i = 0; i < k; i++) {

        while (!Q.empty() && a[i] > a[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);

    }
    //Process the remaining elements
    for (; i < n; i++) {
        cout << a[Q.front()] << " ";

        //1. Remove the elements which are not the part of the window(Contraction)
        while ((!Q.empty() && (Q.front() <= i - k))) {
            Q.pop_front();
        }

        //2. Remove the elements which are not useful and are in window
        while (!Q.empty() && a[i] >= a[Q.back()]) {
            Q.pop_back();
        }

        //3. Add the new elements(Expansion)
        Q.push_back(i);
    }

    cout << a[Q.front()] << endl;


    return 0;
}
