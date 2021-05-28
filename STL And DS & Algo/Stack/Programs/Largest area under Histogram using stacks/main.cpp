// Largest area under histogram using stacks
// https://www.youtube.com/watch?v=0do2734xhnU

/*
 *  The concept:
 *      For any bar, we need to find its limiting left and right bar i.e. the bar on the left and right which are
 *      smaller than its height. Using those bars we can calculate the max area for that specific bar.
 *      O(n2) - brute force
 *      but using stacks we can reduce the time complexity to just O(N)
 */

#include<iostream>
#include<stack>

using namespace std;

// main function
int maxArea(int arr[], int size) {
    // will help us compute the left and right limits
    // will contain the index
    // stack<int> s;

    int rightLimit[size];
    int leftLimit[size];

    // right limit array (run loop from right to left)
    stack<int> s1;
    // for the last element, push its index into stack and give its right limit as size of array
    s1.push(size - 1);
    rightLimit[size - 1] = size;

    for (int i = size - 2; i >= 0; i--) {
        // pop all the bigger elements than itself to get the right boundary
        while (!s1.empty() && arr[i] <= arr[s1.top()]) {
            s1.pop();
        }

        if (s1.empty()) {
            rightLimit[i] = size;
        } else {
            rightLimit[i] = s1.top();
        }
        s1.push(i);
    }

    // left limit array (run loop from left to right)
    stack<int> s2;
    // for the first element, push its index into stack and give its left limit as -1
    s2.push(0);
    leftLimit[0] = -1;

    for (int i = 1; i < size; i++) {
        // pop all the bigger elements to get the left boundary
        while (!s2.empty() && arr[i] < arr[s2.top()]) {
            s2.pop();
        }
        if (s2.empty()) {
            leftLimit[i] = -1;
        } else {
            leftLimit[i] = s2.top();
        }
        s2.push(i);
    }


    // stores the ans
    int maxArea = 0;
    for (int i = 0; i < size; i++) {
        // calculate the left and right limits
        int width = rightLimit[i] - leftLimit[i] - 1;
        int height = arr[i];
        // cal the area and also update max area
        int area = width * height;

        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    // input the info
    cout << "Enter the number of bars in histogram" << endl;
    int n;
    cin >> n;
    cout << "Enter the heights of bars" << endl;
    int histogram[n];
    for (int i = 0; i < n; i++)
        cin >> histogram[i];

    // get the max area
    cout << "The max area is: " << maxArea(histogram, n);

    return 0;
}
