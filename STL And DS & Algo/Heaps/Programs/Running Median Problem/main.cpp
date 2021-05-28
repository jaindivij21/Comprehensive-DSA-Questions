// Running median problem using heaps
/*
 *  You are given a running stream of numbers that is you cannot store them all and at any point the user can query
 *  the median of all the numbers until then. The running stream is not sorted!
 *      Median is the middle most element in a list of sorted numbers\
 *
 *      Solving Methods:
 *      1) Sort the array and find the middle most element (Expensive)
 *      2) Make 2 heaps - max and min. Add all the elements to both the heaps and keep a count variable that stores number of elements in the heaps. When the query arises start popping from both the heaps,
 *         if count is odd: pop (count/2) -1 times and now the top of both heaps is median. if count is even: median is the avg of top of both heaps after popping (count/2)-1 elements. (Expensive) -- Check
 *         by drawing on paper.
 *
 *      3) This implementation: Make 2 heaps, a max heap for all the elements smaller than the median and a min heap for all the elements bigger than the median.
 */

#include<iostream>
#include<queue>
#include<functional>
#include<cstdio>

using namespace std;

int main() {
    int input;
    float median;

    // 4 -1 3 -1 12 5 1 -1 example
    // heaps
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Input the running stream
    while (scanf("%d", &input) != EOF) {
        if (input == -1) {
            // calculate the median until now
            cout << "The median is " << median << endl;
            continue;
        } else {
            if (maxHeap.empty() && minHeap.empty()) {
                // insertion of first element
                maxHeap.push(input);
                median = input;
                continue;
            } else {
                if (input <= median) {
                    // add to min heap and check for balancing (i.e. the difference bw the 2 heaps should ot be more than 1)
                    maxHeap.push(input);
                    if (maxHeap.size() - minHeap.size() > 1) {
                        // pop the max element from the max heap and push it into min heap
                        int tempElement = maxHeap.top();
                        maxHeap.pop();
                        minHeap.push(tempElement);
                    }
                } else {
                    // add of max heap and check for balancing (i.e. the difference bw the 2 heaps should ot be more than 1)
                    minHeap.push(input);
                    if (minHeap.size() - maxHeap.size() > 1) {
                        // pop the min element from the min heap and push it into max heap
                        int tempElement = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(tempElement);
                    }
                }
            }
        }
        // Calculate the median everytime at the end of each iteration
        if (minHeap.size() == maxHeap.size())
            // if both heaps have the same size then avg of top of both heaps is our median
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        if (minHeap.size() == maxHeap.size() + 1)
            // if min heap is bigger than top of min heap is the median
            median = float(minHeap.top());
        if (maxHeap.size() == minHeap.size() + 1)
            // if min heap is bigger than top of min heap is the median
            median = float(maxHeap.top());
    }

    return 0;
}