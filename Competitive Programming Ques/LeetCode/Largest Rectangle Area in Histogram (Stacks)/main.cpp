// Largest Rectangle In Histogram :: Leetcode
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://www.youtube.com/watch?v=MhQPpAoZbMc&t=1423s

/*
 * whenever you see a monotonic increase in the input which could yield  the answer closest to required you gotta
 * understand that you should use a stack data structure to  calculate the answer.
 */

#include<bits/stdc++.h>

using namespace std;

// will use stack to solve this problem
int largestRectangleArea(vector<int> &heights) {
    stack<int> index;   // stores the indexes

    // IMPORTANT
    heights.push_back(0);   // example: [2,4] we do this because there can be a case where the array is over but stack still has items

    index.push(0);  // push the first index

    // The basic idea is that for each bar, we need to find the smaller bar to the left and to the right, this way we can
    // calculate the max area for that bar.

    // O(n) runtime :: push the bar's index in increasing order : i index gives you the right bound and stack helps us get the left bound.
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        // if the bar is smaller than the previous bar, it gives us opportunity to pop and and cal the rectangles : but why?
        // because we encounter a right limit for that bar
        while (!index.empty() && heights[index.top()] > heights[i]) {
            // pop until the while condition fail and for every pop we calculate the area
            int barHeight = heights[index.top()];
            index.pop();
            // for this pop : we know the right limit is 'i' and the left limit will be stack top; however if the stack is empty means
            // there is no smaller bar towards the left of popped element and only the right limiting factor
            // calculate the width
            int width;
            if (index.empty())
                width = i;
            else
                width = i - index.top() - 1;
            maxArea = max(maxArea, width * barHeight);
        }
        // we have to push the indexes into the stack everytime
        index.push(i);
    }
    return maxArea;
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
    cout << largestRectangleArea(v);

    return 0;
}