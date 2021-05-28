// Greedy Problem
// Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value
// in the knapsack.

// Solution: Take out the fraction value/weight. Now greedily select the max to min to get most value in W capacity.

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// comparator function
bool compare(pair<int, int> p1, pair<int, int> p2) {
    double val1 = double(double(p1.first) / p1.second);
    double val2 = double(double(p2.first) / p2.second);
    return val1 > val2;
}

// main function that returns the max total value of the knapsack
double fractionalKnapsack(vector<pair<int, int>> obj, int size, int w) {
    double res = 0.0;
    int weight = w;
    // sort the vector in descending order of their cost/weight value
    sort(obj.begin(), obj.end(), compare);

    // traverse through the entire array
    for (int i = 0; i < size; i++) {
        if (obj[i].second <= weight) {
            // if the entire object can fit
            res = res + obj[i].first;
            weight -= obj[i].second;
        } else {
            // if the entire object can't fit, add the fractional par
            res += double((double(obj[i].first) / obj[i].second) * weight);
            break;
        }
    }
    return res;
}

int main() {
    cout << "Enter the weight" << endl;
    int w;
    cin >> w;

    cout << "Enter the number of total items" << endl;
    int n;
    cin >> n;

    // insert the n items
    vector<pair<int, int>> items;
    cout << "Enter the item's->" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        int a, b;
        cin >> a >> b;
        items.push_back(make_pair(a, b));
    }

    double result = fractionalKnapsack(items, n, w);

    cout << "The max fractional value possible in the bag is: " << result << endl;

    return 0;
}