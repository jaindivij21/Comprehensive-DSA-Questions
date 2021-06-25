// Sort Game Help Sanju Problem
/*
 * Sort Game
 * Sanju needs your help! He gets a list of employees with their salary. The maximum salary is 100.
 * Sanju is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary.
 * And if two employees have the same salary, they should be arranged in lexicographical manner.
 * Also the list should only contains names of those employees having salary greater than or equal to a given number x.
 */

/*
Input:
79
4
Eve 78
Bob 99
Suzy 86
Alice 86
Output:
Bob 99
Alice 86
Suzy 86
*/


// doing it in basic fashion without using much stl
#include<iostream>
#include<algorithm>

using namespace std;

int compare(pair<string, int> a, pair<string, int> b) {
    if(a.second == b.second)
        return a.first > b.first;
    else
        return a.second < b.second;
}

void sort(pair<string, int> arr[], int n) {
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    int salLimit;
    cin >> salLimit;

    int noOfEmp;
    cin >> noOfEmp;

    pair<string, int> arr[noOfEmp];
    for (int i = 0; i < noOfEmp; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr, noOfEmp);

    for (int i = 0; i < noOfEmp; i++) {
        if (arr[i].second < salLimit)
            continue;
        else
            cout << arr[i].first << " " << arr[i].second << endl;
    }
}