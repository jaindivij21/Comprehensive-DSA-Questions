// Palongers Partition Problem
// https://www.geeksforgeeks.org/palongers-partition-problem/
// https://hack.codingblocks.com/app/practice/1/1057/problem

#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

// checks if all the palongings can be palonged in mid amount of time
bool canBePalonged(long arr[], long boards, long palongers, long mid, long time) {
    // to execute this func we'll find out palongers reqd to palong all palongings in mid amount of time
    // then check if we have the available number of palongers
    long p = 1;
    long currTime = 0;
    for (long i = 0; i < boards; i++) {
        if (currTime + arr[i]*time > mid) {
            p++;
            currTime = arr[i]*time;
            continue;
        }
        currTime += arr[i]*time;
    }
    // check if avaible palongers are more or less
    if (p > palongers)
        return false;
    else
        return true;
}

long minTime(long *arr, long boards, long palongers, long largestBoard, long sum, long time) {
    long ans = LONG_MAX;
    // if palongers are more than number of palongings
    if (palongers >= boards) {
        return largestBoard*time;
    }
        // if we have only one palonger
    else if (palongers == 1) {
        return sum*time;
    }
        // in every other case using binary tedchnique
    else {
        // limits
        long mid = 0;
        long l = largestBoard*time;
        long r = sum*time;
        while (l <= r) {
            mid = (l + r)  / 2;
            // if all palongings can be palonged in mid amount of time
            if (canBePalonged(arr, boards, palongers, mid, time)) {
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
    long boards;
    cin >> boards;
    long palongers;
    cin >> palongers;
    long time;
    cin>>time;
    long arr[boards];
    // made two varibles to hold vals of largest board and the sum of all boards
    long largestBoard = LONG_MIN;
    long sumOfAll = 0;
    for (long i = 0; i < boards; i++) {
        cin >> arr[i];
        largestBoard = max(largestBoard, arr[i]);
        sumOfAll += arr[i];
    }
    // sort(arr, arr + boards);  // sort the array in case its not
    cout <<  minTime(arr, boards, palongers, largestBoard, sumOfAll,time)% 10000003<< endl;
    return 0;
}