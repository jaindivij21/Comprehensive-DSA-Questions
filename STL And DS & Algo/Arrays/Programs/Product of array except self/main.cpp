
// Program to output the product array except self
// https://www.youtube.com/watch?v=gREVHiZjXeQ

#include<bits/stdc++.h>

using namespace std;

void printProductArray(vector<int> v, int s) {
    // we have to solve this in O(N) TC and constant space

    // make an output vector (also behaves like a left cumulative product)
    vector<int> output(s);

    // make output array as left Cumulative product array :: means its indexes store the product of all the edges to the left (itself included)
    for (int i = 0; i < s; i++) {
        if (i == 0)
            output[i] = v[i];
        else
            output[i] = v[i] * v[i - 1];
    }

    int product = 1;    // behaves like a right cumulative product

    // main operation
    product = 1;    // corner case
    for (int i = s - 1; i > 0; i--) {
        output[i] = v[i - 1] * product;
        product *= v[i];
    }
    // corner case
    output[0] = product;

    // print the output array
    for (int i = 0; i < s; i++) {
        cout << output[i] << " ";
    }
}

int main() {
    /// input the array
    vector<int> v;
    int size;

    cin >> size;
    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    printProductArray(v, size);

    return 0;
}