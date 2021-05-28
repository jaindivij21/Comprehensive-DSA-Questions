// same code as main.cpp but with different sized arrays

// Program to merge K sorted arrays using heap (Min Heap)

#include<bits/stdc++.h>

using namespace std;

//In this pair, first int represents the element, next two int represents its position in 2d vector ie. i,j
#define pp pair<int,pair<int,int>>

// main function
vector<int> merge(vector<vector<int>> arr, int k) {
    // Min Heap that stores pairs and ans vector declared
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    vector<int> ans;
    // For all the arrays
    for (int i = 0; i < k; i++)
        // Pushing the first element of all K sorted arrays in the priority queue
        pq.push(make_pair(arr[i][0], make_pair(i, 0)));

    // Processing and pushing the remaining elements
    while (!pq.empty()) {
        pp front = pq.top();    // store the top/min pair
        pq.pop();

        // push this pair's data into the ans vector
        ans.push_back(front.first);

        // Take out the position of the popped element
        int i = front.second.first;
        int j = front.second.second;
        // If the next index is within array bounds
        if (j + 1 < arr[i].size())
            pq.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
    }
    return ans;
}

int main() {
    int k = 3;
    //Storing k sorted arrays in a 2d vector
    vector<vector<int>> arr{{2,  6,  12},
                             {1,  9},
                             {23, 34, 90, 2000}};
    // calculate the sorted array and print it
    vector<int> output = merge(arr, k);
    for (auto i:output)
        cout << i << " ";

    return 0;
}


