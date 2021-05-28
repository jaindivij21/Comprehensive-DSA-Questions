// 0-1 Knapsack Problem
// Using Recursion

// Given certain number of objects, their weights and profits, choose objects to maximize the profit

#include<iostream>

using namespace std;

// intitially we have all the n objects to choose from and hence the capacity of our bag is also fully available
int profit(int n, int c, int wt[], int price[]) {
    // base case
    if (n == 0 || c == 0) {
        // either capacity of our bag is full or there are no objects to be taken
        return 0;
    }
    // recursive case
    // x and y are the profits of both the cases
    // we dont take the nth object
    int y = 0 + profit(n - 1, c, wt, price);
    // we take the nth object
    int x;
    if (c >= wt[n - 1]) {
        // price of nth item (n-1 index) and remaining n-1 items
        x = price[n - 1] + profit(n - 1, c - wt[n - 1], wt, price);
    } else {
        // else if the capacity of bag exceeds with the bag even then we dont add it to the bag
        x = 0; // there just take the profits of n-1 objects which is already covered by y
    }

    return max(x, y);
}

int main() {
    cout << "Enter the num of objects" << endl;
    int objs;
    cin >> objs;

    int wts[objs];
    cout << "Enter the weights of the objects" << endl;
    for (int i = 0; i < objs; i++)
        cin >> wts[i];

    int profits[objs];
    cout << "Enter the profits of the objects" << endl;
    for (int i = 0; i < objs; i++)
        cin >> profits[i];

    int capacity;
    cout << "Enter the capacity" << endl;
    cin >> capacity;

    cout << "The max profit possible is: " << profit(objs, capacity, wts, profits) << endl;
    return 0;
}