// Painters Partition Problem
// https://www.geeksforgeeks.org/painters-partition-problem/
// https://hack.codingblocks.com/app/practice/1/1057/problem

#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

// checks if all the paintings can be painted in mid amount of time
bool canBePainted(int arr[], int boards, int painters, int mid) {
    // to execute this func we'll find out painters reqd to paint all paintings in mid amount of time
    // then check if we have the available number of painters
    int p = 1;
    int currTime = 0;
    for (int i = 0; i < boards; i++) {
        if (currTime + arr[i] > mid) {
            p++;
            currTime = arr[i];
            continue;
        }
        currTime += arr[i];
    }
    // check if avaible painters are more or less
    if (p > painters)
        return false;
    else
        return true;
}

int minTime(int *arr, int boards, int painters, int largestBoard, int sum) {
    int ans = INT_MAX;
    // if painters are more than number of paintings
    if (painters >= boards) {
        return largestBoard;
    }
        // if we have only one painter
    else if (painters == 1) {
        return sum;
    }
        // in every other case using binary tedchnique
    else {
        // limits
        int mid = 0;
        int l = largestBoard;
        int r = sum;
        while (l <= r) {
            mid = (l + r)  / 2;
            // if all paintings can be painted in mid amount of time
            if (canBePainted(arr, boards, painters, mid)) {
                // update the val of ans and try finding more less time
                ans = min(mid, ans);
                r = mid - 1;
            }
                // else try out for more time
            else {
                l = mid + 1;
            }
        }
        // return ans
        return ans;
    }
}


int main() {
    // input the values and the array
    int painters;
    cin >> painters;
    int boards;
    cin >> boards;
    int arr[boards];
    // made two varibles to hold vals of largest board and the sum of all boards
    int largestBoard = INT_MIN;
    int sumOfAll = 0;
    for (int i = 0; i < boards; i++) {
        cin >> arr[i];
        largestBoard = max(largestBoard, arr[i]);
        sumOfAll += arr[i];
    }
    sort(arr, arr + boards);  // sort the array in case its not
    cout << "The min time to paint all the paintings: " << minTime(arr, boards, painters, largestBoard, sumOfAll)
         << endl;
    return 0;
}