// Greedy Algorithm for Activity Selection
// You are given n activities with their start and finish times. Select the maximum number of activities
// that can be performed by a single person, assuming that a person can only work on a single activity at a time.

/*
 *  Solution: We basically have to find greedily the next activity with the least finish time so that we can choose the
 *  maximum number of activities. Also we have to choose the activity such that the start time is less than the finish time
 */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    // comparator function returns true when pair 1 has less finishing time than the pair 2
    return p1.second < p2.second;
}

void printMaxActivities(int start[], int finish[], int n) {
    // sort both the arrays based upon their finishing times in ascending order
    // make a hash map or vector of pairs to store both the arrays
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back(make_pair(start[i], finish[i]));
    }
    // sort OR COULD HAVE USED A MIN HEAP
    sort(jobs.begin(), jobs.end(), compare);

    // actual implementation
    // choose the job with minimum finishing time

    int i = 0;  // first activity always gets selected
    cout << i + 1 << "th Job, ";

    // for the rest of activities
    for (int j = 1; j < n; j++) {
        // if this activity has a start time greater or equal to the last selected finish time, then select it
        if (jobs[j].first >= jobs[i].second) {
            cout << j + 1 << "th Job, ";
            i = j;
        }
    }
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    printMaxActivities(s, f, n);

    return 0;
}